//
// Created by Rufelle on 03/11/2022.
//

#ifndef CUBECLUB_RS_ASM_ERROR_H
#define CUBECLUB_RS_ASM_ERROR_H
#include <iostream>
#include "chainmacro.h"
#include "deprecated_stringconstruct.h"
namespace chain {

    namespace throw_error {

        // virtual machine or compiler errros

        void no_internet (){
            std::cout << "[NoNetworkException - 101]: Internet privileges unspecified, please check your internet connection to start the updater module.\n";
        }

        void updater_not_found (){
            std::cout << "[UpdaterNotFoundException - 100]: Update module not found, please re-install the CVM as the updater module cannot be found.\n\tFile integrity breach error. Updates are unable to commence.\n";
        }

        void update_available (std::string str){
            std::cout << "[OutdatedChainWarning - 001]: Outdated Chain module, please update your CVM using the .update directive.\n";
            std::cout << "\tCurrent available version for download: " << str << std::endl;
        }

        //file errors

        void invalid_input (){
            std::cout << "[InvalidInputException - 401]: Invalid input, please follow input standards.\n";
        }

        void file_not_found (){
            std::cout << "[FileNotFoundException - 402]: File not found, the specified file input cannot be found in the directory.\n\tCheck the filename specified and make sure that the file ends in either .cc or .ccbyte.\n";
            exit(402);
        }

        void invalid_file_extension(){
            std::cout << "[InvalidFileExtensionException - 403]: Invalid file extension, the specified file is not compatible with the CVM.\n\tThe CVM can only execute .ccbyte files and can only read .link files.\n";
            exit(405);
        }



        // syntax errors:

        void syntax_invalid_operand(chain::string_construct error){
            /*
             * deprecated error
             */
            std::cout << "[Error SN1 - 500]: In line " << chain::line << " invalid operand: " << error.secondary_operator << " around line: " << error.string << std::endl;
            exit(500);
        }

        void invalid_hex_format(std::string str){
            std::cout << "[InvalidHexFormatException - 501]: In line " << chain::line << " numerical declaration error, where numeric declaration " << str << " does not follow format 0x<num>h" << std::endl;
            exit(501);
        }

        // logic errors

        void not_numeric(std::string str){
            std::cout << "[NumericTokenizerException- 901]: In line " << chain::line << " numeric tokenizer error, " << str <<  " is not a numeric variable. Please contact the customer support for help. This is a virtual machine / compiler error.\n";
            exit(901);
        }



    }
}

#endif //CUBECLUB_RS_ASM_ERROR_H
