//
// Created by Rufelle on 26/11/2022.
//

#ifndef CUBECLUB_RS_ASM_SYNTAX_TREE_H
#define CUBECLUB_RS_ASM_SYNTAX_TREE_H
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "chain-algorithms.h"
#include <ctype.h>

namespace chain{



    enum Operators{ // finds out what operators are there
        COMMA, LABEL_CREATE, LABEL_REFERENCE, NUMERIC_10, NUMERIC_2, NUMERIC_16, QUOTE_START, QUOTE_END, PERIOD, SEMICOLON
    };

    std::unique_ptr<std::array<char, 5>> operator_token = std::make_unique<std::array<char, 5>>();



    enum Identifier{ // identifies the type of word
        OPERATOR, STRING, HEX, DECIMAL, BINARY, COMMAND, DIRECTIVE, COMMENT
    };


    /*
     * Operator -   [,] secondary operand identifier
     *              [$] label reference operator
     *              [:] label creator operator
     *              [d] decimal operator
     *              [h] hex operator
     *              [b] binary operator
     *              ["] string operator
     *
     */


    struct Double_String{ // struct for complex words i.e., "hello," will be turned to -> hello and ,
        std::string string_1;
        std::string string_2;
        boolean exists;
    };

    struct Triple_String : Double_String {
        std::string string_3;
    };

    struct Token{
        Identifier type;
        std::string string;
    };

    struct Operator_Token : Token { // for polymorphism, allows to specify operator
        Operators _operator;
    };

    struct Numeric : Token{
        int number;
    };


    char find_previous (std::string str){
        return str.at(str.length()-2);
    }


    std::string extract_from_first(std::string str){
        return str.substr(1, str.length()-1);
    }

    std::string extract_from_last(std::string str){
        return str.substr(0, str.length()-1);
    }




    Double_String complex_word(std::string str){
        Double_String complex;

        complex.exists = true;

        if (str.at(0)=='$'){
            complex.string_2 = '$';
            complex.string_1 = extract_from_first(str);
        }

        else if (str.at(0)=='.'){
            complex.string_2 = '.';
            complex.string_1 = extract_from_first(str);
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
            complex.string_2 = '"';
            complex.string_1 = extract_from_first(str);
        }

        else if(find_previous(str)==';'){
            complex.string_2 = ';';
            complex.string_1 = extract_from_last(str);
        }

        else {
            complex.exists = false;
            complex.string_1 = str;
            complex.string_2 = nullptr;
        }

        return complex;

    }

    std::shared_ptr<chain::Token> tokenizer (std::string){

    }

    std::shared_ptr<std::vector<chain::Token>> lexer (std::string line){
        auto parsed_line = std::make_shared<std::vector<std::shared_ptr<chain::Token>>>();std::shared_ptr<std::vector<std::shared_ptr<chain::Token>>> parsing= std::make_shared<std::vector<std::shared_ptr<chain::Token>>>();
        while(true){
            std::size_t found = line.find(" ");
            if (found == std::string::npos){
                break;
            }
            std::string word = line.substr(0, found);
            line.erase(0, found);
            Double_String ds = complex_word(word);
            /*
             * Checks if the word is complex
             */

            if (ds.exists){
                parsed_line->push_back(tokenizer(ds.string_1));
                parsed_line->push_back(tokenizer(ds.string_2));
            } else {
                parsed_line->push_back(tokenizer(word));
            }


        }
    }






}


#endif //CUBECLUB_RS_ASM_SYNTAX_TREE_H
