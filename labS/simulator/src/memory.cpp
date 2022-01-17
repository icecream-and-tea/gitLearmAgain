/*
 * @Author       : Chivier Humber
 * @Date         : 2021-09-15 21:15:24
 * @LastEditors  : Chivier Humber
 * @LastEditTime : 2021-11-23 16:08:51
 * @Description  : file content
 */
#include "common.h"
#include "memory.h"


namespace virtual_machine_nsp {
    void memory_tp::ReadMemoryFromFile(std::string filename, int beginning_address) {
        int16_t result;
        std::ifstream input_file;
        input_file.open(filename);
        input_file.is_open();//打开文件
        //读一行后用代码转换函数得到代码，再存入内存
        std::string code_line;
        while (getline(input_file, code_line))
        {
            std::cout << code_line << std::endl;
			result = TranslateInstruction(code_line);
            memory[beginning_address] = result;
			beginning_address ++;
        }

    }

    int16_t memory_tp::GetContent(int address) const {
        // get the content
        // TO BE DONE
        return memory[address];
    }

    int16_t& memory_tp::operator[](int address) {
        // get the content
        // TO BE DONE
        return memory[address];
    }    
};