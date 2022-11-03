//
// Created by Rufelle on 03/11/2022.
//

#ifndef CUBECLUB_RS_ASM_OPCODESTREAM_H
#define CUBECLUB_RS_ASM_OPCODESTREAM_H
#include <string>
#include <iostream>

namespace chain {

    std::string opcode[256] = {"null_opcode", "load", "save", "tor", "toac", "incr",
                               "add", "sub", "mult", "exp", "set", "setr",
                               "not", "jump", "jpos", "jneg", "int",
                               "char", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode","null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode","null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode","null_opcode","null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode", "null_opcode", "null_opcode",
                               "null_opcode", "null_opcode","null_opcode"};

}



#endif //CUBECLUB_RS_ASM_OPCODESTREAM_H
