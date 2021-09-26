/**
 * OC interview question.
 *
 * Write a VM that simulates a computer.
 *
 * First, the program will receive 5 input in this order:
 *
 * memorySizeInBytes: the memory of the VM
 * printBeginOffset: the starting address in memory to start printing out.
 * bytesPerElement: the number of bytes per element.
 * numElementsToPrint: the number of elements to print.
 * numElementsPerLine: the number of elements per line.
 *
 *
 * After that, it will accept bunch of ASM instructions.
 * const unordered_map<string, pair<uint8_t, bool>> kOpCodes{
    {"hlt", {1, false}},
    {"psh", {2, true}},
    {"pop", {3, false}},
    {"equ", {4, true}},
    {"lth", {5, true}},
    {"inc", {6, false}},
    {"add", {7, true}},
    {"mlt", {8, true}},
    {"jmp", {9, true}},
    {"jmf", {10, true}}
    };

    Instruction is in the form of:
    [code][width] [param:optional]

    Instructions might contain additional parameters.
 */

//#define _DEBUG

#include <unordered_map>
#include <limits>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cassert>

using std::unordered_map;
using std::string;
using std::pair;

const unordered_map<string, pair<uint8_t, bool>> kOpCodes{
    {"hlt", {1, false}},
    {"psh", {2, true}},
    {"pop", {3, false}},
    {"equ", {4, true}},
    {"lth", {5, true}},
    {"inc", {6, false}},
    {"add", {7, true}},
    {"mlt", {8, true}},
    {"jmp", {9, true}},
    {"jmf", {10, true}}
};

struct IOStream
{
    void IgnoreLineIn() const
    {
        vm_in.clear();
        vm_in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::istream& vm_in;
    std::ostream& vm_out;
    std::ostream& vm_err;
};

struct AssemblerConfiguration
{
    AssemblerConfiguration()
        : memory_size_(0)
        , begin_offset_(0)
        , num_elements_(0)
        , num_elements_per_line_(0)
        , bytes_per_element_(1)
    {}
    AssemblerConfiguration(const AssemblerConfiguration& config) = default;
    AssemblerConfiguration& operator=(const AssemblerConfiguration& config) = default;
    ~AssemblerConfiguration() {}
    AssemblerConfiguration(AssemblerConfiguration&& config)
        : memory_size_(config.memory_size_)
        , begin_offset_(config.begin_offset_)
        , num_elements_(config.num_elements_)
        , num_elements_per_line_(config.num_elements_per_line_)
        , bytes_per_element_(config.bytes_per_element_)
    {
        config.memory_size_ = 0;
        config.begin_offset_ = 0;
        config.bytes_per_element_ = 0;
        config.num_elements_ = 0;
        config.num_elements_per_line_ = 0;
    }
    AssemblerConfiguration& operator=(AssemblerConfiguration&& config)
    {
        if (this != &config) {
            memory_size_ = config.memory_size_;
            begin_offset_ = config.begin_offset_;
            bytes_per_element_ = config.bytes_per_element_;
            num_elements_ = config.num_elements_;
            num_elements_per_line_ = config.num_elements_per_line_;

            config.memory_size_ = 0;
            config.begin_offset_ = 0;
            config.bytes_per_element_ = 0;
            config.num_elements_ = 0;
            config.num_elements_per_line_ = 0;
        }
        return *this;
    }

    // Memory size in bytes.
    uint64_t memory_size_;

    // Offset starting address.
    uint64_t begin_offset_;

    // Number of elements.
    uint64_t num_elements_;

    // Number of elements per line.
    uint64_t num_elements_per_line_;

    // Number of bytes per element.
    uint64_t bytes_per_element_;
};

class CoolAssembler
{
public:
    CoolAssembler() = delete;

    CoolAssembler(const AssemblerConfiguration& config)
        : asm_config_(config)
        , mem_(new uint8_t[asm_config_.memory_size_])
    {}

    CoolAssembler(const CoolAssembler&) = delete;
    CoolAssembler& operator=(const CoolAssembler&) = delete;

    CoolAssembler(CoolAssembler&& cool_asm)
        : asm_config_(std::move(cool_asm.asm_config_))
        , mem_(std::move(cool_asm.mem_))
    {
        cool_asm.asm_config_.memory_size_ = 0;
        cool_asm.asm_config_.begin_offset_ = 0;
        cool_asm.asm_config_.bytes_per_element_ = 0;
        cool_asm.asm_config_.num_elements_ = 0;
        cool_asm.asm_config_.num_elements_per_line_ = 0;
        cool_asm.mem_ = nullptr;
    }

    CoolAssembler& operator=(CoolAssembler&& cool_asm)
    {
        if (this != &cool_asm) {
            if (mem_ != nullptr)
                delete[] mem_;
            
            // Move data.
            asm_config_ = std::move(cool_asm.asm_config_);
            mem_ = std::move(cool_asm.mem_);

            // Release old data.
            cool_asm.asm_config_.memory_size_ = 0;
            cool_asm.asm_config_.begin_offset_ = 0;
            cool_asm.asm_config_.bytes_per_element_ = 0;
            cool_asm.asm_config_.num_elements_ = 0;
            cool_asm.asm_config_.num_elements_per_line_ = 0;
            cool_asm.mem_ = nullptr;
        }
        return *this;
    }

    ~CoolAssembler()
    {
        if (mem_ != nullptr)
            delete[] mem_;
    }

    /**
     * Dump the memory in hex of in mem_ to the output device.
     */
    void PrintMemory(const IOStream& io_stream) const
    {
        // Potential overflow here. How to deal with it?
        uint64_t end_addr = asm_config_.begin_offset_ + 
            asm_config_.num_elements_ * asm_config_.bytes_per_element_;
        uint64_t count_element = 0;

        // Also want to do bound checking here. Invalid input? end_addr might go pass
        // mem_ total size. Solved by only print within the total memory size.
        //
        // Bound checking
        end_addr = end_addr < asm_config_.memory_size_ ? 
            end_addr : asm_config_.memory_size_;

        for (uint64_t start_addr = asm_config_.begin_offset_; start_addr < end_addr; 
                start_addr += asm_config_.bytes_per_element_) {
            if (count_element == asm_config_.num_elements_per_line_) {
                io_stream.vm_out << "\n";
                count_element = 0;
            }

            // Print each element.
            for (uint8_t i = 0; i < asm_config_.bytes_per_element_; i++) {
                io_stream.vm_out << std::setfill('0') << std::setw(2);
                io_stream.vm_out << std::hex << (0xFF & mem_[start_addr + i]);
                //printf("%02hhx", mem_[start_addr + i]);
            }

            count_element++;
            io_stream.vm_out << " ";
        }
        io_stream.vm_out << "\n";
    }

    /**
     * Load the ASM instructions and covert it to binary format.
     */
    void GetInstructions(const IOStream& io_stream) const
    {
        // Get ASM instructions.
        string asm_instruction;
        uint64_t start_addr = 0;
        while (std::getline(io_stream.vm_in, asm_instruction)) {

            // Read the instruction into memory.
            // Need a better way to do this, what happens if the opcode's length is no longer 3?
            string op_code = asm_instruction.substr(0, 3);
            if (kOpCodes.find(op_code) != kOpCodes.end()) {
                uint64_t op_code_encoded = (kOpCodes.at(op_code).first) << 0x2;

                uint8_t width_char = asm_instruction[3] - '0';
                uint64_t width = 0;

                switch (width_char) {
                    case 2:
                        width = 0x1;
                        break;
                    case 4:
                        width = 0x2;
                        break;
                    case 8:
                        width = 0x3;
                }
                
                // If width_char = 2, then width = 1.
                // If width_char = 4, then width = 2.
                // If width_char = 8, then width = 3.
                //unsigned width_char_copy = width_char;
                //while (width_char_copy >>= 1) width++;

                op_code_encoded |= width;

                // Write opcode and the width to the first byte.
                mem_[start_addr] = op_code_encoded;

                // Check if there's a param. If there's a param, write it to memory
                // according to the width.
                if (kOpCodes.at(op_code).second) {
                    // Same problem with the opcode's length. If the opcode's length is not 3,
                    // this needs to be changed.
                    string param = asm_instruction.substr(5);
                    int64_t param_int = std::stol(param);

                    for (int i = width_char; i > 0; i--) {
                        mem_[start_addr + i] = param_int & 0xFF;
                        param_int >>= 0x8;
                    }

                    start_addr += width_char;
                }

                start_addr += 1;
            }       
        }
    }

    /**
     * Run the program loaded in mem_
     */
    void Run() const
    {

    }

private:
    // Virtual machine configuration.
    AssemblerConfiguration asm_config_;
    
    // Memory segment.
    uint8_t* mem_;
};

uint64_t GetUInt(const IOStream& io_stream, uint64_t upper_limit)
{
    uint64_t result = 0;
    while (true) {
        io_stream.vm_in >> result;

        // Check for failed extraction.
        if (io_stream.vm_in.fail()) {
            io_stream.vm_in.clear();
            io_stream.vm_in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            //io_stream.vm_in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return result;
        }
    }
}

uint64_t GetBytesPerElement(const IOStream& io_stream)
{
    uint64_t result = 1;
    while (true) {
        io_stream.vm_in >> result;

        switch (result) {
            case 1:
            case 2:
            case 4:
            case 8:
                return result;
            default:
                io_stream.vm_in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                io_stream.vm_err << "Invalid bytes per element. Either 1, 2, 4, and 8.\n";
        }
    }
}

/**
 * Note to myself: Test cases might overflow operands or results.
 * Initial assumption: The input line will have 5 numeric arguments on it. We can no longer make the assumption
 * that the input is formatted correctly and valid.
 * 
 * What kind of input would break the program?
 */
int ReadConfiguration(const IOStream& io_stream, AssemblerConfiguration& config)
{
    // 31U is 11111 in binary. Everytime an input is valid, turn on the bit for
    // valid_flag.
    const uint8_t kValidInput = 31U;
    uint8_t valid_flag = 0U;

    // Overall:
    // begin_offset_ + num_elements * bytes_per_element_ < memory_size_;
    // If not, prompt the user to input again. 
    while (valid_flag != kValidInput) {
        // What could possibly happen here?
        // 1. User input a too large/too small number.
        // 2. User input a negative number.
        // 3. User input a valid number but the OS does not permit such allocation size
        // for a single buffer.
        // 4. User input some non-integer characters.
        //config.memory_size_ = GetUInt(io_stream, std::numeric_limits<uint64_t>::max());
        io_stream.vm_in >> config.memory_size_;
        if (io_stream.vm_in.fail()) {
            io_stream.IgnoreLineIn();
            io_stream.vm_err << "Invalid memory size.\n";
            valid_flag = 0U;
            continue;
        } else {
            valid_flag |= 1U;
        }

        // What could possibly happen here?
        // 1. User input a too large / too small number.
        // 2. User input a negative number.
        // 3. User input a number which is outside of the range of [0, memory_size_]
        // 4. User input some non-integer characters.
        //config.begin_offset_ = GetUInt(io_stream, config.memory_size_);
        io_stream.vm_in >> config.begin_offset_;
        if (io_stream.vm_in.fail()) {
            io_stream.IgnoreLineIn();
            io_stream.vm_err << "Invalid begin offset.\n";
            valid_flag = 0U;
            continue;
        } else {
            valid_flag |= (1U << 1);
        }

        // 1, 2, 4, 8 bytes only.
        // User input anything rather than 1, 2, 4, or 8.
        //config.bytes_per_element_ = GetBytesPerElement(io_stream);
        io_stream.vm_in >> config.bytes_per_element_;
        if (io_stream.vm_in.fail()) {
            io_stream.IgnoreLineIn();
            valid_flag = 0U;
            continue;
        } else {
            switch (config.bytes_per_element_) {
                case 1:
                case 2:
                case 4:
                case 8:
                    valid_flag |= (1U << 2);
                    break;
                default:
                    io_stream.IgnoreLineIn();
                    io_stream.vm_err << "Invalid bytes per element. Either 1, 2, 4, and 8.\n";
                    valid_flag = 0U;
                    break;
            }
        }

        if (!valid_flag) continue;

        //config.num_elements_ = GetUInt(io_stream, std::numeric_limits<uint64_t>::max());
        io_stream.vm_in >> config.num_elements_;
        if (io_stream.vm_in.fail()) {
            io_stream.IgnoreLineIn();
            io_stream.vm_err << "Invalid number of elements to print out.\n";
            valid_flag = 0U;
        } else {
            valid_flag |= (1U << 3);
        }

        //config.num_elements_per_line_ = GetUInt(io_stream, std::numeric_limits<uint64_t>::max());
        io_stream.vm_in >> config.num_elements_per_line_;
        if (io_stream.vm_in.fail()) {
            io_stream.IgnoreLineIn();
            io_stream.vm_err << "Invalid number of elements per line.\n";
            valid_flag = 0U;
        } else {
            valid_flag |= (1U << 4);
        }
    }
    #ifdef _DEBUG
    std::cout << config.memory_size_ << " " << config.begin_offset_
        << " " << config.bytes_per_element_ << " " << config.num_elements_
        << " " << config.num_elements_per_line_ << "\n";
    #endif

    return 0;
}

int main()
{
    IOStream io_stream {std::cin, std::cout, std::cerr};

    AssemblerConfiguration new_vm_config;
 
    // Get memory config.
    /*
    scanf("%lu %lu %hhu %lu %lu", 
                &new_vm_config.memory_size_, &new_vm_config.begin_offset_,
                &new_vm_config.bytes_per_element_, &new_vm_config.num_elements_, 
                &new_vm_config.num_elements_per_line_);
    */

    ReadConfiguration(io_stream, new_vm_config);

    CoolAssembler coolVM1(new_vm_config);
    coolVM1.PrintMemory(io_stream);
    coolVM1.GetInstructions(io_stream);
    coolVM1.PrintMemory(io_stream);

    return 0;
}
