//
// Created by Rufelle on 01/11/2022.
//

#ifndef CUBECLUB_RS_ASM_VERCONTROL_H
#define CUBECLUB_RS_ASM_VERCONTROL_H



#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include "error.h"
#include "chainmacro.h"
#include <string>
#include <ShellAPI.h>


namespace shell{
	int system_no_output( std::string command )
{
    command.insert( 0, "/C " );

    SHELLEXECUTEINFOA ShExecInfo = {0};
    ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
    ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
    ShExecInfo.hwnd = NULL;
    ShExecInfo.lpVerb = NULL;
    ShExecInfo.lpFile = "cmd.exe";        
    ShExecInfo.lpParameters = command.c_str();   
    ShExecInfo.lpDirectory = NULL;
    ShExecInfo.nShow = SW_HIDE;
    ShExecInfo.hInstApp = NULL;

    if( ShellExecuteExA( &ShExecInfo ) == FALSE )
        return -1;

    WaitForSingleObject( ShExecInfo.hProcess, INFINITE );

    DWORD rv;
    GetExitCodeProcess( ShExecInfo.hProcess, &rv );
    CloseHandle( ShExecInfo.hProcess );

    return rv;
}
}


namespace chain {

    bool connected;

    bool get_internet(){
        return connected;
    }

    namespace install {


        void install_update (){
            std::cout << "Checking for internet availability, this may take a while...\n";
            connected = system("ping google.com > null");
            connected = !connected;
            if(!get_internet()){
                chain::throw_error::no_internet();
                return;
            }
            std::cout << "\nDo you have git installed? Git is a dependency for installation. [Y/N]: ";
            char c;
            std::cin >> c;
            if (c=='Y'){

            } else if (c=='N'){
                std::cout << "We will install git for you. Is that okay? [Y/N]: ";
                std::cin >> c;
                if (c=='Y'){
                    system("winget install git.git > null");
                } else {
                    std::cout << "Now terminating process...\n";
                    getchar();
                    exit(0);
                }
            } else {
                std::cout << "Invalid input. Please try again.";
                install_update();
            }
        }

    }




    void version_control(){
        const char * curr_version = CURR_VER;

        std::fstream version_control;

        shell::system_no_output("cd chain-Files && git pull CubeClub-chain-Ver-Checker > nul");
        version_control.open("updater.txt", std::ios::in);

			
			
        if (!version_control){
            chain::throw_error::updater_not_found();


        } else {
            std::string remote_ver;
            std::getline(version_control, remote_ver);
            if (!strcmp(curr_version, remote_ver.c_str())){

            } else {

                chain::throw_error::update_available(remote_ver);
            }

        }

    }

    std::string get_version (){

        std::string return_value(CURR_VER);
        return return_value;
    }





}






#endif //CUBECLUB_RS_ASM_VERCONTROL_H
