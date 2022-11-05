//
// Created by Rufelle on 01/11/2022.
//

#include <map>
#ifndef CUBECLUB_RS_ASM_MEMORY_H
#define CUBECLUB_RS_ASM_MEMORY_H
#include <cmath>
#include <cstdlib>
#include <iostream>
namespace chain {

    class Memory {
    public:
        const int MEMORY_CAPACITY = pow(2, 16); // total memory capacity in bytes
        const int BIT_CAPACITY = MEMORY_CAPACITY*8; // total memory capacity in bits
        const int BASIC_CAPACITY = 8; // 8-bit capacity
        const int ADVANCED_CAPACITY = 16;

        int ** RAM, * AC, * R, * PC, * AR, * ACx, * ACy, * Rx, * Ry;
        int Z;
        Memory(){
            RAM = (int**)malloc(sizeof(int*)*MEMORY_CAPACITY);
            for (int i=0; i<MEMORY_CAPACITY; i++){
                RAM[i] = new int[8];
            }

            // REGISTERS
            AC = new int[ADVANCED_CAPACITY];
            R = new int[ADVANCED_CAPACITY];
            PC = new int[ADVANCED_CAPACITY];
            AR = new int[ADVANCED_CAPACITY];
            ACx = AC;
            ACy = AC+BASIC_CAPACITY;
            Rx = R;
            Ry = R+BASIC_CAPACITY;
            std::map<std::string, int> * label = new std::map<std::string, int>(); //hashmap for loop labels
            clearMemory();

        }

        void clearMemory(){
            for (int i=0; i<MEMORY_CAPACITY; i++){
                for (int j=0; j<8; j++){
                    RAM[i][j] = 0;

                }
            }
            for (int i=0; i<8; i++){
                AC[i] = 0;
                R[i] = 0;
                PC[i] = 0;
                AR[i] = 0;
            }
            Z = 0;

            return;

        }

        void view_registers() {
            std::cout << "AC = [";
            for (int i=0; i<ADVANCED_CAPACITY; i++){
                std::cout << AC[i];
                if (i!=ADVANCED_CAPACITY-1){
                    std::cout << ", ";
                }
            } std::cout << "]\n";

            std::cout << "ACx = [";
            for (int i=0; i<BASIC_CAPACITY; i++){
                std::cout << ACx[i];
                if (i!=BASIC_CAPACITY-1){
                    std::cout << ", ";
                }
            } std::cout << "]\n";

            std::cout << "ACy = [";
            for (int i=0; i<BASIC_CAPACITY; i++){
                std::cout << ACy[i];
                if (i!=BASIC_CAPACITY-1){
                    std::cout << ", ";
                }
            } std::cout << "]\n";

            std::cout << "R = [";
            for (int i=0; i<ADVANCED_CAPACITY; i++){
                std::cout << R[i];
                if (i!=ADVANCED_CAPACITY-1){
                    std::cout << ", ";
                }
            } std::cout << "]\n";

            std::cout << "Rx = [";
            for (int i=0; i<BASIC_CAPACITY; i++){
                std::cout << Rx[i];
                if (i!=BASIC_CAPACITY-1){
                    std::cout << ", ";
                }
            } std::cout << "]\n";

            std::cout << "Ry = [";
            for (int i=0; i<BASIC_CAPACITY; i++){
                std::cout << Ry[i];
                if (i!=BASIC_CAPACITY-1){
                    std::cout << ", ";
                }
            } std::cout << "]\n";

            std::cout << "AR = [";
            for (int i=0; i<ADVANCED_CAPACITY; i++){
                std::cout << AR[i];
                if (i!=ADVANCED_CAPACITY-1){
                    std::cout << ", ";
                }
            } std::cout << "]\n";

            std::cout << "PC = [";
            for (int i=0; i<ADVANCED_CAPACITY; i++){
                std::cout << PC[i];
                if (i!=ADVANCED_CAPACITY-1){
                    std::cout << ", ";
                }
            } std::cout << "]\n";

            std::cout << "Z = [" << Z << "]\n";
        }

    };

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




#endif //CUBECLUB_RS_ASM_MEMORY_H
