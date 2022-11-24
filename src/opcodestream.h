//
// Created by Rufelle on 03/11/2022.
//

#ifndef CUBECLUB_RS_ASM_OPCODESTREAM_H
#define CUBECLUB_RS_ASM_OPCODESTREAM_H
#include <string>
#include <iostream>

namespace chain {



    /* ONE OPERAND PARADIGM
     * load (mov)
     * tor (mov)
     * toac (mov)
     * save (mov)
     * sum (add)
     * dif (sub)
     * setac (set)
     * setr (set)
     * char (log8)   log8.char& acx
     * int (log16)
     */


    std::string opcode[256] = {"null_opcode", "load", "save", "tor", "toac", "incr",
                               "sum", "dif", "mult", "exp", "setac", "setr",
                               "not", "jump", "jpos", "jneg", "int",
                               "char", "move","equa","comp",
                               "inc", "dec", "add", "sub",
                               "set", "null_opcode", "null_opcode", "null_opcode",
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
