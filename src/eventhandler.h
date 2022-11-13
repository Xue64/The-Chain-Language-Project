//
// Created by Rufelle on 13/11/2022.
//

#ifndef CUBECLUB_RS_ASM_EVENTHANDLER_H
#define CUBECLUB_RS_ASM_EVENTHANDLER_H
#include <iostream>
#include <ctype.h>

namespace chain{
    void toLowerCaseTerminalArguments (char * arg1, char * arg2){
        int i = 0;
        while (arg1[i]){
            arg1[i] = tolower(arg1[i]);
            i++;
        }
        i = 0;
        while (arg2[i]){
            arg2[i] = tolower(arg2[i]);
        }
    }
}




#endif //CUBECLUB_RS_ASM_EVENTHANDLER_H
