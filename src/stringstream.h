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
        for (auto i : operators){
            i = false;
        }
    }

    void clear(){
        string_construct();
    }
};


namespace chain {
    namespace sstream {

        bool isWhiteSpace(std::string);

        void check_operator (string_construct &holder, std::string &temp, bool &comment){
            char operator_holder = temp[temp.length()-1];

            std::cout << "Current operator in check of word: " << temp << " is " << operator_holder << std::endl;

            if (temp==";"){
                holder.operators[1] = true;
                holder._operator = ';';
                operator_present;
            }

            else if (operator_holder==';'){
                holder.operators[2] = true;
                holder._operator = ';';
                operator_present;
            }

            else if (operator_holder==':'){
                holder.operators[4] = true;
                holder._operator = ':';
                operator_present;
            }

            else if (operator_holder==','){
                holder.operators[5] = true;
                holder._operator = ',';
                operator_present;
            }

            else if (operator_holder== '&'){
                holder.operators[3] = true;
                holder._operator = '&';
                operator_present;
            }
        }




        make_nullvector;
        std::vector<string_construct> * string_parser (std::string str){ // break up line to words


            int iterator = 0;
            std::string temp = "";
            char c;
            std::vector<string_construct> * line = new std::vector<string_construct>();
            string_construct holder;
            holder.clear();

            while (iterator<str.length()){
                bool comment = false;
                c = str[iterator];

                if (c==' '){
                    check_operator(holder, temp, comment);

                    if (temp.length()!=0){
                        holder.string = temp;
                        line->push_back(holder);

                        if (comment){
                            return line; // if a comment is found, ignore the rest of the line
                        }

                        holder.clear();
                    }

                    temp = "";
                    iterator++;
                    continue;
                }

                temp += c;
                iterator++;


            } if (!line->empty()&&!isWhiteSpace(holder.string)){
                make_nullboolean;
                check_operator(holder, temp, nullboolean);
                holder.string = temp;
                line->push_back(holder);
            }

            return line;
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
