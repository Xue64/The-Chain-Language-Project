//
// Created by Rufelle on 05/11/2022.
//

#ifndef CUBECLUB_RS_ASM_STRINGSTREAM_H
#define CUBECLUB_RS_ASM_STRINGSTREAM_H
#include <iostream>
#include <vector>
#include "trex.h"
#include "chainmacro.h"



struct string_construct {
    std::string string;
    bool comment = false;
    bool reference = false;
    bool address = false;
    bool definite_comment = false;
    bool label = false;
    bool classified = false;

    void reset (){
        comment = false;
        reference = false;
        address = false;
        definite_comment = false;
        label = false;
        classified = false;
    }
};

namespace chain {
    namespace sstream {

        void check_operator (string_construct &holder, std::string &temp, bool &comment){
            char operator_holder = temp[temp.length()-1];
            if (temp==";"){
                holder.definite_comment = true;
                holder.classified = true;
                comment = true;
            } else if (operator_holder==';'){
                holder.comment = true;
                holder.classified = true;
                comment = true;
            } else if (operator_holder==':'){
                holder.label = true;
                holder.classified = true;
            } else if (operator_holder==','){
                holder.address = true;
                holder.classified = true;
            } else if (operator_holder== '&'){
                holder.reference = true;
                holder.classified = true;
            }
        }


        make_nullvector;
        std::vector<string_construct> * string_parser (std::string str){ // break up line to words
            int iterator = 0;
            std::string temp = "";
            char c;
            std::vector<string_construct> * line = new std::vector<string_construct>();
            string_construct holder;
            holder.reset();
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
                        holder.reset();
                    }
                    temp = "";
                    iterator++;
                    continue;
                }
                temp += c;
                iterator++;
            } if (!line->empty()){
                bool invalid;
                check_operator(holder, temp, invalid);
                holder.string = temp;
                line->push_back(holder);
            }

            return line;
        }

        void file_encryptor (std::vector<std::string> * file){

            /*for (int i=0; i<file->size(); i++){
                std::cout << "Now encrypting\n";
                (*file)[i] = trex::encrypt((*file)[i]);
                std::cout << "At line " << i+1 << ": " << (*file)[i] << std::endl;
            }*/
        }



        void file_printer (std::vector<std::string> file_vector) {
            for (int i = 0; i<file_vector.size(); i++){
                std::cout << file_vector[i] << std::endl;
            }
        }

    }
}


#endif //CUBECLUB_RS_ASM_STRINGSTREAM_H
