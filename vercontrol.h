//
// Created by Rufelle on 01/11/2022.
//

#ifndef CUBECLUB_RS_ASM_VERCONTROL_H
#define CUBECLUB_RS_ASM_VERCONTROL_H

#define CURR_VER "alpha 0.0.1"

#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>

namespace rsasm {

    void version_control(){
        const char * curr_version = CURR_VER;
        std::fstream version_control;
        version_control.open("..//updater.txt", std::ios::in);
        if (!version_control){
            std::cout << "System integrity check found one (1) vulnerability... version control dependency not found.\n";


        } else {
            std::string remote_ver;
            std::getline(version_control, remote_ver);
            if (!strcmp(curr_version, remote_ver.c_str())){

            } else {
                std::cout << "A new version is available! Please go to the update settings using the \"$update\" command.\n";
            }
        }
    }


}






#endif //CUBECLUB_RS_ASM_VERCONTROL_H
