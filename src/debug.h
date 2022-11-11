//
// Created by Rufelle on 02/11/2022.
//

#ifndef CUBECLUB_RS_ASM_DEBUG_H
#define CUBECLUB_RS_ASM_DEBUG_H
#include <iostream>
#include "memory.h"
#include <vector>
#include "stringstream.h"
#define __debug__ std::cout << "debugger passed here\n"
namespace chain {
    namespace debug {
        template <typename T>
        void print_vector (std::vector<T>* vector){
            for (auto i : *vector){
                std::cout << i.string << "ENDSTRING" << std::endl;
            }
        }

        void print_parser (std::vector<string_construct> vector){
            for (int i=0; i<vector.size(); i++){
                std::cout << vector[i].string << " ";

                if (vector[i].operators[3]){
                    std::cout << "references using the reference operator\n";
                }

                if (vector[i].operators[5]){
                    std::cout <<"references to a direct address\n";
                }

                if (vector[i].operators[4]){
                    std::cout << "is a label\n";
                }

                if (vector[i].operators[1]){
                    std::cout << "is an absolute comment\n";
                }

                if (vector[i].operators[2]){
                    std::cout << "is an in-line comment.\n";
                }

                if (!vector[i].operators[0]) {
                    std::cout << "does not have an operator.\n";
                }
                if (vector[i]._operator == '\0'){
                    std::cout << "DOES NOT HAVE AN OPERATOR\n";
                    continue;
                }
                std::cout << "Found with operator " << vector[i]._operator << std::endl;
            }
        }

    }
}



#endif //CUBECLUB_RS_ASM_DEBUG_H
