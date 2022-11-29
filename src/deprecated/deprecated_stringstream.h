//
// Created by Rufelle on 05/11/2022.
//

#ifndef CUBECLUB_RS_ASM_DEPRECATED_STRINGSTREAM_H
#define CUBECLUB_RS_ASM_DEPRECATED_STRINGSTREAM_H
#include <iostream>
#include <vector>
#include "../TRex Encryption/trex.h"
#include "../Main Module/chainmacro.h"
#include <string>
#include <ctype.h>
#include "deprecated_stringconstruct.h"







namespace chain {
    namespace sstream {

        bool isWhiteSpace(std::string);

        void set_operators(string_construct& holder){
            std::string temp = holder.string;
            holder._operator = temp[temp.length()-1];
            if (temp.length()>1){
                holder.secondary_operator = temp[temp.length()-2];
            } else{
                holder.secondary_operator = '\0';
            }
        }


        void lexer (string_construct & holder, bool first){ // lexer for determining operators
            std::string temp = holder.string;
            holder.clear(); // clear the contents of holder
            set_operators(holder);
            char operator_holder = holder._operator;

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
                holder.operators[3] = true;
                holder._operator = ':';
                operator_present;
                return;
            }


            else if (operator_holder=='d'){
                holder.operators[4] = true;
                holder._operator = 'd';
                operator_present;
                return;
            }

            else if (operator_holder== 'h'){
                holder.operators[5] = true;
                holder._operator = 'h';
                operator_present;
                return;
            }

            else if (operator_holder== 'b'){
                holder.operators[6] = true;
                holder._operator = 'b';
                operator_present;
                return;
            }

            else if (operator_holder== ','){
                holder.operators[7] = true;
                holder._operator = ',';
                holder._secondaryop[0] = true;
                if (!first){
                    std::cout << temp << "is not first.\n";
                    operator_present;
                    return;
                }
                std::cout << "The secondary operator is: " << holder.secondary_operator << std::endl;
                if (holder.secondary_operator = 'd'){
                    holder._secondaryop[1] = true;
                }
                else if (holder.secondary_operator = 'h'){
                    holder._secondaryop[2] = true;
                }
                else if (holder.secondary_operator = 'b'){
                    holder._secondaryop[3] = true;
                }
                else if (holder.secondary_operator == ',' || holder.secondary_operator == ':'){
                    chain::throw_error::syntax_invalid_operand(holder);
                }

                else {
                    holder._secondaryop[4] = true;
                }


                operator_present;
                return;
            }
        }




        make_nullvector;
        std::vector<string_construct> * string_parser(std::string str){ // parses strings and separates them into individual words
            string_construct result_holder;
            result_holder.clear();
            result_holder.string = "";
            auto * returning = new std::vector<string_construct>();
            // holds the vector of parsed words
            bool first = true; // for checking operator, so it does not apply to the first line of the string
            while (true){
                int index = str.find(" ");
                result_holder.string = str.substr(0, index);
                str = str.substr(index+1, str.length());
                if (isWhiteSpace(result_holder.string)){ // checks if string is just whitespace
                    str = str.substr(index+1, str.length());
                    continue;
                }
                lexer(result_holder, first);
                first = false;
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

        void lowerString (std::string &str){
            for (int i=0; i<str.length(); i++){
                str[i] = tolower(str[i]);
            }
        }

    }
}


#endif //CUBECLUB_RS_ASM_DEPRECATED_STRINGSTREAM_H
