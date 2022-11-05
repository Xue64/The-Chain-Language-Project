//
// Created by Rufelle on 05/11/2022.
//

#ifndef CUBECLUB_RS_ASM_STRINGSTREAM_H
#define CUBECLUB_RS_ASM_STRINGSTREAM_H
#include <iostream>
#include <vector>
#include "trex.h"
#include "chainmacro.h"
namespace chain {
    namespace sstream {
        make_nullvector;
        std::vector<std::string> * string_parser (std::string){
            return nullvector;
        }

        void file_encryptor (std::vector<std::string> * file){

            for (int i=0; i<file->size(); i++){
                (*file)[i] = trex::encrypt((*file)[i]);
            }
        }

        void file_printer (std::vector<std::string> file_vector) {
            for (int i = 0; i<file_vector.size(); i++){
                std::cout << file_vector[i] << std::endl;
            }
        }

    }
}


#endif //CUBECLUB_RS_ASM_STRINGSTREAM_H
