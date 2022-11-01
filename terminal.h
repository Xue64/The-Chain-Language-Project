//
// Created by Rufelle on 01/11/2022.
//
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "vercontrol.h"
#ifndef CUBECLUB_RS_ASM_TERMINAL_H
#define CUBECLUB_RS_ASM_TERMINAL_H

namespace rsasm{
    namespace terminal {
        void setup(){
            time_t tmd;
            tmd = time(0);
            std::string time_and_date(ctime(&tmd));
            std::cout << "CubeClub's interpreted ASM (RSASM) v. " << rsasm::get_version() << " sysinfo: " << time_and_date;
            std::cout << "Use the following terminal commands: \"$help\", \"$update\", \"$ver\" and \"$about\" for more relevant details.\n";
        }

        void end_process(){
            std::cout << "\n\nPress the enter key to end process...";
            getchar();
        }
    }

}


#endif //CUBECLUB_RS_ASM_TERMINAL_H
