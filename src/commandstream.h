//
// Created by Rufelle on 11/11/2022.
//

#ifndef CUBECLUB_RS_ASM_COMMANDSTREAM_H
#define CUBECLUB_RS_ASM_COMMANDSTREAM_H
#include "memory.h"
#include "stringstream.h"
#include "chainmacro.h"


class commandStream{
    chain::Memory * memory;

public:
    commandStream(chain::Memory * memory){
        this->memory = memory;
    }


};

#endif //CUBECLUB_RS_ASM_COMMANDSTREAM_H
