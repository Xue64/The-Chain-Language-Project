//
// Created by Rufelle on 03/11/2022.
//

#ifndef CUBECLUB_RS_ASM_CHAINMACRO_H
#define CUBECLUB_RS_ASM_CHAINMACRO_H
#include "eventhandler.h"
#define _ccmain_ int main(int argc, char ** argv)
#define _arguments_present argc>1
#define _set_file_ std::string read_file(argv[2]);
#define _set_file_direct_call_ std::string read_file(argv[1])
#define CURR_VER "alpha 0.0.1"
#define _debug_ std::cout << "pass" << std::endl
#define make_nullvector std::vector<std::string> * nullvctr__
#define nullvector nullvctr__
#define _maindeclare_ chain::Memory * memory = new chain::Memory(); std::vector<std::string> * file_line; chain::Compiler * compiler = new chain::Compiler(memory);
#define make_nullboolean bool _nullboolean
#define nullboolean _nullboolean
#define _argument_ argv[1]
#define _configure_arguments_ chain::toLowerCaseTerminalArguments(argv[1], argv[2])
#define decode(str, i) if(str==chain::opcode[i])
#define operator_present holder.operators[0] = true
#define _direct_call_ argc==2

namespace chain{
    int line = 0;
}


#endif //CUBECLUB_RS_ASM_CHAINMACRO_H



