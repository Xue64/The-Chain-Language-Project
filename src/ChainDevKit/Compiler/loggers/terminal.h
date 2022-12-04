//
// Created by Rufelle on 01/11/2022.
//
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <string>
#include "../../Virtual Machine/vercontrol.h"
#ifndef CUBECLUB_RS_ASM_TERMINAL_H
#define CUBECLUB_RS_ASM_TERMINAL_H
#include <chrono>
#include "../../Virtual Machine/chain-time.h"
#include "../../Virtual Machine/vercontrol.h"
#include "../opcodestream.h"
#include "../../Virtual Machine/filecontrol.h"

namespace chain{

    namespace terminal {

        void event_loop (){



        }


        void setup(){
            time_t tmd;
            tmd = time(0);
            std::string time_and_date(ctime(&tmd));
            std::cout << "Relatively Simpler ASM virtual machine v. " << chain::get_version() << " sysinfo: " << time_and_date;
            std::cout << "(c) CubeClub Technologies, 2022. All rights reserved.\n";
            std::cout << "Use the following terminal commands: \".help\", \".update\", \".ver\", and \".about\" for more relevant details.\n\n";
        }

        void compilation_success(){
            auto termination_time = (chain::time_limiter::time_end() - chain::time_limiter::start);
            auto total_time = std::chrono::duration_cast<std::chrono::microseconds>(termination_time);
            std::unique_ptr<std::string>time_str = std::make_unique<std::string>();
            auto time_bbb = ((total_time.count())/100000.0);
            auto float_time = static_cast<float>(time_bbb);
            std::cout << "------------------------------\n[Done] Executed in ";
            printf("%.02f sec", float_time);
            std::cout << "\n[Compilation Success] File stored at " + chain::file::file_name;
            std::cout << "\n[TEST BUILD VER] ALPHA BUILD 0.0.2C";
            std::cout << "\nEnter any key to terminate process...";
            getchar();
        }



    }
    
    

}


#endif //CUBECLUB_RS_ASM_TERMINAL_H
