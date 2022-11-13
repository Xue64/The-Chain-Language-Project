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
        std::map<std::string, bool*> * label;
        bool ** RAM, * AC, * R, * PC, * AR, * ACx, * ACy, * Rx, * Ry;
        std::string * register_list;



        long const int MEMORY_CAPACITY = pow(2, 16); // total memory capacity in bytes
        const int BIT_CAPACITY = MEMORY_CAPACITY*8; // total memory capacity in bits
        const int BASIC_CAPACITY = 8; // 8-bit capacity
        const int ADVANCED_CAPACITY = 16;


        int Z;
        Memory(){
            RAM = (bool**)malloc(sizeof(bool*)*MEMORY_CAPACITY);
            for (int i=0; i<MEMORY_CAPACITY; i++){
                RAM[i] = new bool[8];
            }

            // REGISTERS
            AC = new bool[ADVANCED_CAPACITY];
            R = new bool[ADVANCED_CAPACITY];
            PC = new bool[ADVANCED_CAPACITY];
            AR = new bool[ADVANCED_CAPACITY];
            ACx = AC;
            ACy = AC+BASIC_CAPACITY;
            Rx = R;
            Ry = R+BASIC_CAPACITY;
            label = new std::map<std::string, bool*>(); //hashmap for loop labels
            clearMemory();
            register_list = new std::string[8];
            initiateRegisterLabels();

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

        void initiateRegisterLabels(){
            register_list[0] = "AC";
            register_list[1] = "ACx";
            register_list[2] = "ACy";
            register_list[3] = "R";
            register_list[4] = "Rx";
            register_list[5] = "Ry";
            register_list[6] = "PC";
            register_list[7] = "AR";


            label->insert({register_list[0], AC});
            label->insert({register_list[1], ACx});
            label->insert({register_list[2], ACy});
            label->insert({register_list[3], R});
            label->insert({register_list[4], Rx});
            label->insert({register_list[5], Ry});
            label->insert({register_list[6], PC});
            label->insert({register_list[7], AR});

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
