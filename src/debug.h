//
// Created by Rufelle on 02/11/2022.
//

#ifndef CUBECLUB_RS_ASM_DEBUG_H
#define CUBECLUB_RS_ASM_DEBUG_H
#include <iostream>
#include "memory.h"
#define __debug__ std::cout << "debugger passed here\n"
namespace chain {
    namespace debug {
        void print_RAM (chain::Memory * memory){
            for (int i=0; i<memory->MEMORY_CAPACITY; i++){
                int zero = 10000;
                std::cout << i;
                for (int j=0; j<=4; j++){
                    if (i<zero){
                        std::cout << "0";
                    }
                    zero/=10;
                }
                std::cout << " ";
                for (int j=0; j<8; j++){
                    std::cout << memory->RAM[i][j];
                }
                std::cout << std::endl;
            }
        }

        void print_RAM (Memory * memory, int range_A, int range_B){
            std::cout << std::endl;
            for (int i=range_A; i<range_B; i++){
                int zero = 10000;
                for (int j=0; j<4; j++){
                    if (i<zero){
                        std::cout << "0";
                    }
                    zero/=10;
                }
                std::cout << i;
                std::cout << " ";
                for (int j=0; j<8; j++){
                    std::cout << memory->RAM[i][j];
                }
                std::cout << std::endl;
            }
        }
    }
}



#endif //CUBECLUB_RS_ASM_DEBUG_H
