//
// Created by Rufelle on 26/11/2022.
//
#include <string>
#include <memory>
#ifndef CUBECLUB_RS_ASM_CHAIN_ALGORITHMS_H
#define CUBECLUB_RS_ASM_CHAIN_ALGORITHMS_H

namespace chain{

    int strHex (std::string str){
        std::string binary;
        return (int)str.at(1);
    }

    int strBin (std::string str){
        return (int)str.at(1);
    }

    int strDec (std::string str){
        return (int)str.at(1);
    }

    std::array<char, 8> toBin (int num){
        auto bin_array = std::array<ch
        bin_array->at(0) = 'A';
        return bin_array;
    }

}

#endif //CUBECLUB_RS_ASM_CHAIN_ALGORITHMS_H
