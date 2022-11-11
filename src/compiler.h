//
// Created by Rufelle on 11/11/2022.
//

#ifndef CUBECLUB_RS_ASM_COMPILER_H
#define CUBECLUB_RS_ASM_COMPILER_H
#include "opcodestream.h"
#include "memory.h"
#include "stringstream.h"
#include "commandstream.h"

class Compiler{
    chain::Memory * memory;
    std::vector<string_construct> * vector;
    commandStream * machine;


public:
    Compiler(chain::Memory * memory){
        this->memory = memory;
        machine = new commandStream(memory);
    }


    void push_vector(std::vector<string_construct> * vector){
        this->vector = vector;
        for (auto i: *vector){
            interpret(i);
        }
        return;
    }

private:
    void interpret (string_construct str){

    }




};

#endif //CUBECLUB_RS_ASM_COMPILER_H
