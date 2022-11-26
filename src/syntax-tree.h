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
#include <cctype>
#include <typeinfo>

namespace chain{



    enum Operators{ // finds out what operators are there
        TRASH_OP, COMMA, LABEL_CREATE, LABEL_REFERENCE, NUMERIC_10, NUMERIC_2, NUMERIC_16, QUOTE, PERIOD, SEMICOLON, NO_OPERAND
    };

    enum EscapeSequence{
        TRASH_ESC, NEWLINE, ENDLINE, NOESCAPE
    };



    enum Identifier{ // identifies the type of word
        TRASH_ID, OPERATOR, STRING, NUMERIC, COMMAND, DIRECTIVE, COMMENT, ESCAPE_SEQUENCE
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


    struct Token{
        Identifier type;
        std::string string;
        Operators _operators;
        int numeric;
        EscapeSequence sequence;

        void newToken(){
            type = TRASH_ID;
            string = nullptr;
            _operators = TRASH_OP;
            numeric = std::string::npos+1;
            sequence = TRASH_ESC;
        }
    };



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

        else if (str.at(str.length()-2)=='\\'){
            complex.string_2 = str.substr(str.length()-2, 2);
            complex.string_1 = str.substr(0, str.length()-2);
        }

        else {
            complex.exists = false;
            complex.string_1 = str;
            complex.string_2 = nullptr;
        }

        return complex;

    }

    Operators operator_tokenizer (std::string str){
        if (str==";"){
            return SEMICOLON;
        } else if (str==","){
            return COMMA;
        } else if (str=="$"){
            return LABEL_REFERENCE;
        } else if (str==":"){
            return LABEL_CREATE;
        } else if (str=="\""){
            return QUOTE;
        } else if (str=="."){
            return PERIOD;
        } return NO_OPERAND;
    }

    EscapeSequence escape_tokenizer (std::string str){
        char last = str.at(str.length()-1);
        if (last == 'n'){
            return NEWLINE;
        } else if (last == '0'){
            return ENDLINE;
        } return NOESCAPE;
    }



    Operators numeric_tokenizer (std::string &str){
        if (find_previous(str)=='d'|| find_previous(str)=='h'|| find_previous(str)=='b'){
            if (find_previous(str)=='h'){
                std::string hex_ID;
                hex_ID += str.substr(0, 2);
                if (hex_ID=="0x"){
                    str = str.erase(0, 2);
                    str = str.erase(str.length()-1, 1);
                    return NUMERIC_16;
                } else {
                    throw_error::invalid_hex_format(str);
                }

            }

            else if (find_previous(str)=='b'){
                str.erase(str.length()-1, 1);
                return NUMERIC_2;
            }

            else if (find_previous(str)=='d'){
                str.erase(str.length()-1, 1);
                return NUMERIC_10;
            }

            return NO_OPERAND;
        }
    }


    /*
     * To implement
     * -> chain-algorithms
     *
     */
    int toBase10 (std::string str, Operators identifier){
        if (identifier == NUMERIC_10){
            return strDec(str);
        }
        if (identifier == NUMERIC_16){
            return strHex(str);
        }
        if (identifier == NUMERIC_2){
            return strBin(str);
        }
        throw_error::not_numeric(str);
        return -1;

    }


    chain::Token tokenizer (std::string str){
        Token token;
        token.newToken();
        Operators operand = numeric_tokenizer(str);
        if (operand != NO_OPERAND){
            token.type = NUMERIC;
            token.string = str;
            token.numeric = toBase10(str, operand);
            return token;
        }
        EscapeSequence sequence = escape_tokenizer(str);
        if (sequence != NOESCAPE){
            token.type = ESCAPE_SEQUENCE;
            token.sequence = sequence;
            token.string = str;
            return token;
        }

    }

    std::shared_ptr<std::vector<chain::Token>> lexer (std::string line){
        auto parsed_line = std::make_shared<std::vector<chain::Token>>();
        while(true){
            std::size_t found = line.find(' ');
            std::size_t not_found = line.find_first_not_of(' ');
            if (found == std::string::npos){
                break;
            }

            if (not_found == std::string::npos){
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
        return parsed_line;
    }






}


#endif //CUBECLUB_RS_ASM_SYNTAX_TREE_H
