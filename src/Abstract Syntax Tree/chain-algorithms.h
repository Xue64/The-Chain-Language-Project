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
        auto bin_array = std::array<char, 8>();
        bin_array.at(0) = 'A';
        return bin_array;
    }


    char find_previous (std::string str){
        return str.at(str.length()-1);
    }


    std::string extract_from_first(std::string str){
        return str.substr(1, str.length()-1);
    }

    std::string extract_from_last(std::string str){
        return str.substr(0, str.length()-1);
    }

    struct Complex_String{ // struct for complex words i.e., "hello," will be turned to -> hello and ,
        std::string string_1;
        std::string string_2;
        bool exists;
    };

    Complex_String complex_word(std::string str){
        Complex_String complex;
        if (str.length()==1){
            complex.string_1 = str;
            complex.exists = false;
            return complex;
        }

        complex.exists = true;
        if (str.at(0)=='$'){
            complex.string_1= '$';
            complex.string_2 = extract_from_first(str);
        }

        else if (str.at(0)=='.'){
            complex.string_1 = '.';
            complex.string_2 = extract_from_first(str);
        }

        else if (find_previous(str)==':'){
            complex.string_2 = ':';
            complex.string_1 = extract_from_last(str);
        }

        else if (find_previous(str)==','){
            complex.string_2 = ',';
            complex.string_1 = extract_from_last(str);
        }

        else if (find_previous(str)=='"'){
            complex.string_2 = '"';
            complex.string_1 = extract_from_last(str);
        }

        else if (str.at(0)=='"'){
            complex.string_1 = '"';
            complex.string_2 = extract_from_first(str);
        }

        else if(find_previous(str)==';'){
            complex.string_2 = ';';
            complex.string_1 = extract_from_last(str);
        }
        else if (str.at(str.length()-2)=='\\'){
            complex.string_2 = str.substr(str.length()-2, 2);
            complex.string_1 = str.substr(0, str.length()-2);
        }
            /*
             * TO-DO: Create Triple String
             *
             */

        else {
            complex.exists = false;
            complex.string_1 = str;
            complex.string_2 = "";
        }

        return complex;

    }
}



#endif //CUBECLUB_RS_ASM_CHAIN_ALGORITHMS_H
