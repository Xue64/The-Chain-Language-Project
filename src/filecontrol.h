//
// Created by Rufelle on 02/11/2022.
//

#ifndef CUBECLUB_RS_ASM_FILECONTROL_H
#define CUBECLUB_RS_ASM_FILECONTROL_H
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include "error.h"


namespace chain{
    namespace file {

        //deprecated method, please change
        void invoke_file(std::string file_name){
            std::fstream bytecode;
            bytecode.open(file_name, std::ios::in);
            if (!bytecode){
                chain::throw_error::invalid_file_extension();
                return;
            }
            char filename[8];
            int length = file_name.size();
            int stander = 6;
            for (int i=0; i<7; i++){
                filename[stander] = file_name[length-i-1];
                stander--;
            }
            filename[7] = '\0';
            if (strcmp(filename, ".ccbyte")){

                return;
            }
            while (true){
                std::string stream;
                std::getline(bytecode, stream);
                std::cout << "\n";
                std::cout << stream;
                if (bytecode.eof()){
                    break;
                }


            }

    }
    }

}
#endif //CUBECLUB_RS_ASM_FILECONTROL_H
