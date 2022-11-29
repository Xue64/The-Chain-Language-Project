//
// Created by Rufelle on 30/11/2022.
//

#ifndef CUBECLUB_RS_ASM_CHAIN_TIME_H
#define CUBECLUB_RS_ASM_CHAIN_TIME_H
#include <iostream>
#include <chrono>
namespace chain{

    namespace time_limiter{
        auto time_start(){
            auto var = std::chrono::high_resolution_clock::now();
            return std::chrono::high_resolution_clock::now();
        }

        auto time_end(){
            return std::chrono::high_resolution_clock::now();
        }

        auto start = time_start();
    }

}


#endif //CUBECLUB_RS_ASM_CHAIN_TIME_H
