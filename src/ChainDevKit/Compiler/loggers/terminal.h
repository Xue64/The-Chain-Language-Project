//
// Created by Rufelle on 01/11/2022.
//
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "../../Virtual Machine/vercontrol.h"
#ifndef CUBECLUB_RS_ASM_TERMINAL_H
#define CUBECLUB_RS_ASM_TERMINAL_H
#include <chrono>
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




        void end_process(){
            std::cout << "-----------------------\n";
            std::cout << "Press the enter key to end process...";
            getchar();
        }

        void compilation_success(){
            auto termination_time = (chain::time_limiter::time_end() - chain::time_limiter::start);
            auto total_time = std::chrono::duration_cast<std::chrono::microseconds>(termination_time);
            std::cout << "------------------------------\n[Done] Executed in 0." << total_time.count() << " ms";
            std::cout << "\n[Compilation Success] File stored at " + chain::file::file_name;
            std::cout << "\nEnter any key to terminate process...";
            getchar();
        }



    }
    
    

}


#endif //CUBECLUB_RS_ASM_TERMINAL_H
