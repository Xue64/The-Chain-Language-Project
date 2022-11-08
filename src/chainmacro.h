//
// Created by Rufelle on 03/11/2022.
//

#ifndef CUBECLUB_RS_ASM_CHAINMACRO_H
#define CUBECLUB_RS_ASM_CHAINMACRO_H
#define _ccmain_ int main(int argc, char ** argv)
#define _arguments_present argc>1
#define CURR_VER "alpha 0.0.1"
#define _debug_ std::cout << "pass" << std::endl
#define make_nullvector std::vector<std::string> * nullvctr__
#define nullvector nullvctr__
#define _maindeclare_ chain::Memory * memory = new chain::Memory(); std::vector<std::string> * file_line;
#define make_nullboolean bool _nullboolean
#define nullboolean _nullboolean
#endif //CUBECLUB_RS_ASM_CHAINMACRO_H


