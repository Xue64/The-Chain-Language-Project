//
// Created by Rufelle on 02/11/2022.
//

#ifndef CUBECLUB_RS_ASM_FILECONTROL_H
#define CUBECLUB_RS_ASM_FILECONTROL_H
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>


namespace rsasm{
    namespace file {
        void invoke_file(std::string file_name){
            std::fstream bytecode;
            bytecode.open(file_name, std::ios::in);
            if (!bytecode){
                std::cout << "did not find the specified file in the directory.\n";
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
                std::cout << "Incompatible file extension. RS ASM only reads .ccbyte files.\n";
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
