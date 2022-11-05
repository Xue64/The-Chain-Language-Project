//
// Created by Rufelle on 03/11/2022.
//

#ifndef CUBECLUB_RS_ASM_ERROR_H
#define CUBECLUB_RS_ASM_ERROR_H
#include <iostream>

namespace chain {

    namespace throw_error {

        void no_internet (){
            std::cout << "Error N01: Internet privileges unspecified, please check your internet connection to start the updater module.\n";
        }

        void updater_not_found (){
            std::cout << "Error N02: Update module not found, please re-install the CVM as the updater module cannot be found.\n\tFile integrity breach error. Updates are unable to commence.\n";
        }

        void update_available (std::string str){
            std::cout << "Error N03: Outdated Chain module, please update your CVM using the .update directive.\n";
            std::cout << "\tCurrent available version for download: " << str << std::endl;
        }

        void invalid_input (){
            std::cout << "Error IN1: Invalid input, please follow input standards.\n";
        }

        void file_not_found (){
            std::cout << "Error IN2: File not found, the specified file input cannot be found in the directory.\n\tCheck the filename specified and make sure that the file ends in either .cc or .ccbyte.\n";
        }

        void invalid_file_extension(){
            std::cout << "Error IN3: Invalid file extension, the specified file is not compatible with the CVM.\n\tThe CVM can only execute .ccbyte files and can only read .cc files.\n";
        }

    }
}

#endif //CUBECLUB_RS_ASM_ERROR_H
