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

#include <unordered_map>
#include <sstream>
#include <iostream>
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

class CoolAssembler
{
public:
    CoolAssembler() = delete;

    CoolAssembler(uint64_t memorySizeInBytes, uint64_t printBeginOffset, 
            uint8_t bytesPerElement, uint64_t numElementsToPrint,
            uint64_t numElementsPerLine)
        : memory_size_(memorySizeInBytes)
        , begin_offset_(printBeginOffset)
        , bytes_per_element_(bytesPerElement)
        , num_elements_(numElementsToPrint)
        , num_elements_per_line_(numElementsPerLine)
        , mem_(new uint8_t[memory_size_])
    {

    }

    CoolAssembler(const CoolAssembler&) = delete;
    CoolAssembler& operator=(const CoolAssembler&) = delete;

    CoolAssembler(CoolAssembler&& cool_asm)
        : memory_size_(std::move(cool_asm.memory_size_))
        , begin_offset_(std::move(cool_asm.begin_offset_))
        , bytes_per_element_(std::move(cool_asm.bytes_per_element_))
        , num_elements_(std::move(cool_asm.num_elements_))
        , num_elements_per_line_(std::move(cool_asm.num_elements_per_line_))
        , mem_(std::move(cool_asm.mem_))
    {
        cool_asm.memory_size_ = 0;
        cool_asm.begin_offset_ = 0;
        cool_asm.bytes_per_element_ = 0;
        cool_asm.num_elements_ = 0;
        cool_asm.num_elements_per_line_ = 0;
        cool_asm.mem_ = nullptr;
    }

    CoolAssembler& operator=(CoolAssembler&& cool_asm)
    {
        if (this != &cool_asm) {
            if (mem_ != nullptr)
                delete[] mem_;
            
            // Move data.
            memory_size_ = std::move(cool_asm.memory_size_);
            begin_offset_ = std::move(cool_asm.begin_offset_);
            bytes_per_element_ = std::move(cool_asm.bytes_per_element_);
            num_elements_ = std::move(cool_asm.num_elements_);
            num_elements_per_line_ = std::move(cool_asm.num_elements_per_line_);
            mem_ = std::move(cool_asm.mem_);

            // Release old data.
            cool_asm.memory_size_ = 0;
            cool_asm.begin_offset_ = 0;
            cool_asm.bytes_per_element_ = 0;
            cool_asm.num_elements_ = 0;
            cool_asm.num_elements_per_line_ = 0;
            cool_asm.mem_ = nullptr;
        }
        return *this;
    }

    ~CoolAssembler()
    {
        if (mem_ != nullptr)
            delete[] mem_;
    }

    void PrintMemory() const
    {
        // Potential overflow here.
        uint64_t end_addr = begin_offset_ + num_elements_ * bytes_per_element_;
        uint64_t count_element = 0;

        // Also want to do bound checking here. Invalid input? end_addr might go pass
        // mem_ total size.
        //
        // Bound checking
        end_addr = end_addr < memory_size_ ? end_addr : memory_size_;
        for (uint64_t start_addr = begin_offset_; start_addr < end_addr; 
                start_addr += bytes_per_element_) {
            if (count_element == num_elements_per_line_) {
                printf("\n");
                count_element = 0;
            }

            // Print each element.
            for (uint8_t i = 0; i < bytes_per_element_; i++) {
                printf("%02hhx", mem_[start_addr + i]);
            }

            count_element++;
            printf(" ");
        }
        printf("\n");
    }

    void GetInstructions() const
    {
        // Get ASM instructions.
        string asm_instruction;
        uint64_t start_addr = 0;
        while (std::getline(std::cin, asm_instruction)) {

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
    // Memory size in bytes.
    uint64_t memory_size_;

    // Offset address to print out.
    uint64_t begin_offset_;

    // Number of bytes per element.
    uint8_t bytes_per_element_;

    // Number of elements.
    uint64_t num_elements_;

    // Number of elements per line.
    uint64_t num_elements_per_line_;
    
    // Memory segment.
    uint8_t* mem_;
};

int main()
{
    uint64_t memorySizeInBytes = 0;
    uint64_t printBeginOffset = 0;
    uint64_t numElementsToPrint = 0;
    uint64_t numElementsPerLine = 0;
    uint8_t bytesPerElement = 1;

    // Get memory config.
    scanf("%lu %lu %hhu %lu %lu", &memorySizeInBytes, &printBeginOffset,
            &bytesPerElement, &numElementsToPrint, &numElementsPerLine);

    /*
    uint8_t mem[memorySizeInBytes];
    memset(mem, 0, memorySizeInBytes);

    PrintMemory(mem, memorySizeInBytes, printBeginOffset, bytesPerElement, 
            numElementsToPrint, numElementsPerLine);
    GetASMInstructions(mem);
    PrintMemory(mem, memorySizeInBytes, printBeginOffset, bytesPerElement, 
            numElementsToPrint, numElementsPerLine);
    */

    CoolAssembler coolVM1(memorySizeInBytes, printBeginOffset, bytesPerElement,
                            numElementsToPrint, numElementsPerLine);
    coolVM1.PrintMemory();
    coolVM1.GetInstructions();
    coolVM1.PrintMemory();

    return 0;
}
