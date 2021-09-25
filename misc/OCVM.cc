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
    {

    }

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

    void PrintMemory(std::ostream& outp_stream) const
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
                outp_stream << "\n";
                count_element = 0;
            }

            // Print each element.
            for (uint8_t i = 0; i < asm_config_.bytes_per_element_; i++) {
                outp_stream << std::setfill('0') << std::setw(2);
                outp_stream << std::hex << (0xFF & mem_[start_addr + i]);
                //printf("%02hhx", mem_[start_addr + i]);
            }

            count_element++;
            outp_stream << " ";
        }
        outp_stream << "\n";
    }

    void GetInstructions(std::istream& inp_stream) const
    {
        // Get ASM instructions.
        string asm_instruction;
        uint64_t start_addr = 0;
        while (std::getline(inp_stream, asm_instruction)) {

            // Read the instruction into memory.
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

private:
    // Virtual machine configuration.
    AssemblerConfiguration asm_config_;
    
    // Memory segment.
    uint8_t* mem_;
};

/**
 * Note to myself: Test cases might overflow operands or results.
 * Initial assumption: Th input line will have 5 numeric arguments on it. We can no longer make the assumption
 * that the input is formatted correctly and valid.
 */
int ReadConfiguration(std::istream& stdin, AssemblerConfiguration& config)
{
    stdin >> config.memory_size_;

    stdin >> config.begin_offset_;

    // 1, 2, 4, 8 bytes only.
    stdin >> config.bytes_per_element_;

    stdin >> config.num_elements_;

    stdin >> config.num_elements_per_line_;

    #ifdef _DEBUG
    std::cout << config.memory_size_ << " " << config.begin_offset_
        << " " << config.bytes_per_element_ << " " << config.num_elements_
        << " " << config.num_elements_per_line_ << "\n";
    #endif
    
    return 0;
}

int main()
{
    AssemblerConfiguration new_vm_config;
 
    // Get memory config.
    /*
    scanf("%lu %lu %hhu %lu %lu", 
                &new_vm_config.memory_size_, &new_vm_config.begin_offset_,
                &new_vm_config.bytes_per_element_, &new_vm_config.num_elements_, 
                &new_vm_config.num_elements_per_line_);
    */

    #ifdef _DEBUG
    std::cout << new_vm_config.memory_size_ << " " << new_vm_config.begin_offset_
        << " " << new_vm_config.bytes_per_element_ << " " << new_vm_config.num_elements_
        << " " << new_vm_config.num_elements_per_line_ << "\n";
    #endif

    ReadConfiguration(std::cin, new_vm_config);
    CoolAssembler coolVM1(new_vm_config);
    coolVM1.PrintMemory(std::cout);
    coolVM1.GetInstructions(std::cin);
    coolVM1.PrintMemory(std::cout);

    return 0;
}