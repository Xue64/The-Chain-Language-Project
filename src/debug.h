//
// Created by Rufelle on 02/11/2022.
//

#ifndef CUBECLUB_RS_ASM_DEBUG_H
#define CUBECLUB_RS_ASM_DEBUG_H
#include <iostream>
#include "memory.h"
#include <vector>
#define __debug__ std::cout << "debugger passed here\n"
namespace chain {
    namespace debug {
        template <typename T>
        void print_vector (std::vector<T> vector){
            for (T i : vector){
                std::cout << i << std::endl;
            }
        }

        void print_parser (std::vector<string_construct> vector){
            for (int i=0; i<vector.size(); i++){
                std::cout << vector[i].string << " ";
                if (vector[i].reference){
                    std::cout << "references using the reference operator\n";
                } if (vector[i].address){
                    std::cout <<"references to a direct address\n";
                } if (vector[i].label){
                    std::cout << "is a label\n";
                } if (vector[i].comment){
                    std::cout << "is a comment";
                } if (vector[i].definite_comment){
                    std::cout << "is a definite comment.\n";
                } if (!vector[i].classified) {
                    std::cout << "does not have an operator.\n";
                }
            }
        }

    }
}



#endif //CUBECLUB_RS_ASM_DEBUG_H
