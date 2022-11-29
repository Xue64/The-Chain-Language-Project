//
// Created by Rufelle on 11/11/2022.
//

#ifndef CUBECLUB_RS_ASM_COMPILER_H
#define CUBECLUB_RS_ASM_COMPILER_H
#include "opcodestream.h"
#include "../Virtual Machine/memory.h"
#include "../../deprecated/deprecated_stringstream.h"
#include "loggers/commandstream.h"


namespace chain{
    class Compiler{
        chain::Memory * memory;
        std::vector<string_construct> * vector;
        chain::commandStream * machine;


    public:
        Compiler(chain::Memory * memory){
            this->memory = memory;
            machine = new chain::commandStream(memory);
        }


        void push_vector(std::vector<string_construct> * vector){
            this->vector = vector;
            for (auto i: *vector){
                interpret(i);
            }
            return;
        }

    public:
        static void interpret (string_construct str){

            }





    };
}


#endif //CUBECLUB_RS_ASM_COMPILER_H
