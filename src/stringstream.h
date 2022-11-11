//
// Created by Rufelle on 05/11/2022.
//

#ifndef CUBECLUB_RS_ASM_STRINGSTREAM_H
#define CUBECLUB_RS_ASM_STRINGSTREAM_H
#include <iostream>
#include <vector>
#include "trex.h"
#include "chainmacro.h"






struct string_construct{
    std::string string;
    bool operators[6]; /* operators written guide
 * 0 - if operator is present
 * 1 - absoulte comment
 * 2 - in-line comment
 * 3 - reference
 * 4 - label
 * 5 - address
 */


    char _operator;

    string_construct(){
        clear();
    }

    void clear(){
        for (int i=0; i<6; i++){
            operators[i] = false;
        }
        _operator = '\0';
    }
};


namespace chain {
    namespace sstream {

        bool isWhiteSpace(std::string);

        void check_operator (string_construct &holder){
            std::string temp = holder.string;
            char operator_holder = temp[temp.length()-1];
            holder.clear();
            if (temp==";"){
                holder.operators[1] = true;
                holder._operator = ';';
                operator_present;
                return;
            }

            else if (operator_holder==';'){
                holder.operators[2] = true;
                holder._operator = ';';
                operator_present;
                return;
            }

            else if (operator_holder==':'){
                holder.operators[4] = true;
                holder._operator = ':';
                operator_present;
                return;
            }


            else if (operator_holder==','){
                holder.operators[5] = true;
                holder._operator = ',';
                operator_present;
                return;
            }

            else if (operator_holder== '&'){
                holder.operators[3] = true;
                holder._operator = '&';
                operator_present;
                return;
            }
        }




        make_nullvector;
        std::vector<string_construct> * string_parser(std::string str){
            string_construct result_holder;
            result_holder.clear();
            result_holder.string = "";
            std::vector<string_construct> * returning = new std::vector<string_construct>();
            // holds the vector of parsed words
            while (true){
                int index = str.find(" ");
                result_holder.string = str.substr(0, index);
                str = str.substr(index+1, str.length());
                if (isWhiteSpace(result_holder.string)){ // checks if string is just whitespace
                    str = str.substr(index+1, str.length());
                    continue;
                }
                check_operator(result_holder);
                if (result_holder.operators[1]){ // checks if string is a definite comment
                    return returning;
                }
                if (result_holder.operators[0]){ // checks if string has an operator
                    result_holder.string = result_holder.string.substr(0, result_holder.string.length()-1);
                    result_holder.string[result_holder.string.length()] = '\0';
                }
                returning->push_back(result_holder);
                if (result_holder.operators[2]){ // checks if string has a comment operator
                    return returning;
                }
                if (index==-1){ // checks for trailing whitespace
                    break;
                }
            }
            return returning;

        }


        void file_encryptor (std::vector<std::string> * file){

            for (int i=0; i<file->size(); i++){
                (*file)[i] = trex::encrypt((*file)[i]);
            }

        }


        bool isWhiteSpace (std::string str){
            if(str.find_first_not_of(' ') != std::string::npos)
            {
                return false;
            }
            return true;
        }

        void file_printer (std::vector<std::string> file_vector) {
            for (int i = 0; i<file_vector.size(); i++){
                std::cout << file_vector[i] << std::endl;
            }
        }

    }
}


#endif //CUBECLUB_RS_ASM_STRINGSTREAM_H
