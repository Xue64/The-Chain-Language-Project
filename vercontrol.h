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


namespace rsasm {

    bool connected;

    bool get_internet(){
        return connected;
    }

    namespace install {

        void install_gcc(){
            std::cout << "\nDo you have gcc installed? GCC is a dependency for installation. [Y/N]: ";
            char c;
            std::cin >> c;
            if (c=='Y'){

            } else if (c=='N'){
                std::cout << "We will install gcc for you. Is that okay? [Y/N]: ";
                std::cin >> c;
                if (c=='Y'){
                    std::cout << "We are opening the website to help you install gcc.\n";
                    system("start iexplore https://gcc.gnu.org/install/");
                    getchar();
                    getchar();
                    exit(0);
                } else {
                    std::cout << "Now terminating process...\n";
                    getchar();
                    exit(0);
                }
            } else {
                std::cout << "Invalid input. Please try again.";
                install_gcc();
            }
        }

        void install_git(){
            if (system("git -v")){
                std::cout << "\nGit is not installed.\n";
            } else {
                (system("winget install git.git"));
            }

        }

        void install_update (){
            std::cout << "Checking for internet availability, this may take a while...\n";
            connected = system("ping google.com > null");
            connected = !connected;
            if(!get_internet()){
                std::cout << "Cannot install update, please check your internet privileges.\n";
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
            install_gcc();
        }

    }



    void version_control(){
        const char * curr_version = CURR_VER;

        std::fstream version_control;

        shell::system_no_output("cd RSASM-Files && git pull CubeClub-RSASM-Ver-Checker > nul");
        version_control.open("RSASM-Files\\updater.txt", std::ios::in);

			
			
        if (!version_control){
            std::cout << "\nUpon invoking of system file integrity check, found one (1) vulnerability. Version control dependency not found.\nWill be unable to update this installation of RS ASM.\n";


        } else {
            std::string remote_ver;
            std::getline(version_control, remote_ver);
            if (!strcmp(curr_version, remote_ver.c_str())){

            } else {

                std::cout << "\n\nA new version is available! Please go to the update settings using the \"$update\" command.\n";
            }

        }

    }

    std::string get_version (){

        std::string return_value(CURR_VER);
        return return_value;
    }





}






#endif //CUBECLUB_RS_ASM_VERCONTROL_H
