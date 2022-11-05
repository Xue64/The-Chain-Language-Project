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
#include <vector>


namespace chain{
    namespace file {

        std::string parse_extension (std::string str){
            char c = '0';
            int length = str.length() - 1;
            int skip = 0;
            while (c!='.'){ // finds the position of the period
                c = str[skip];
                skip++;
            } skip--;
            char temp[length+1];
            int ctr = 0; // as index for the file extension holder string
            while (c!='\0') {
                temp[ctr] = str[skip + ctr];
                ctr++;
                c = temp[ctr-1];
            }
            std::string extension(temp);
            return extension;

        }


        std::vector<std::string>* invoke_file(std::string file_name){
            make_nullvector;
            std::fstream bytecode;
            bytecode.open(file_name, std::ios::in);
            if (!bytecode){
                chain::throw_error::file_not_found();
                return nullvector;
            }
            std::string file_extension = parse_extension(file_name);
            if (file_extension!=".cc" && file_extension!=".ccbyte"){
                chain::throw_error::invalid_file_extension();
                return nullvector;
            }
            std::vector<std::string> * file_parsed = new std::vector<std::string>();
            while (true){
                if (bytecode.eof()){
                    break;
                }
                std::string stream;
                std::getline(bytecode, stream);
                if (stream.find_first_not_of(' ')==std::string::npos){
                    continue;
                }
                file_parsed->push_back(stream);
            }
            return file_parsed;


    }

    namespace debug {
            void printfile(std::fstream bytecode){
                while(true){
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



}
#endif //CUBECLUB_RS_ASM_FILECONTROL_H
