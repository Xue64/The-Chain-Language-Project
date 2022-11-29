//
// Created by Rufelle on 05/11/2022.
//

#ifndef CUBECLUB_RS_ASM_TREX_H
#define CUBECLUB_RS_ASM_TREX_H
#include <iostream>
#include <cstring>
#include <time.h>


namespace trex {




    std::string encrypt (std::string cpystring)
    {
        int length = cpystring.size();
        char random [] = {'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I' ,'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int olength = (3*length)+4;
        char * string = new char[olength];
        strcpy(string,cpystring.c_str());
        srand(time(NULL));
        char * tstring;
        tstring = (char*)malloc(sizeof(char)*10000);
        strcpy(tstring, string);

        for (int i = 0; i<olength; i++)
        {
            string[i] = random[rand()%60];
        }
        int fdegree, sdegree;
        do{
            string[0] = (rand()%10+66); // sets the first random structure to the first index
            string[olength - 1] = (rand()%10+70); //sets the second random structure to the last index
            sdegree = string[0] - 66;
        }
        while (fdegree==sdegree||string[0]==string[olength-1]); // checks for hazards

        do {
            if (string[0]>string[olength-1])
            {
                fdegree = string[0]-string[olength-1];
                fdegree = fdegree % 16;
            }

            else
            {
                fdegree = string[olength-1] - string[0];
                fdegree = fdegree % 16;
            }
        }
        while (fdegree==sdegree);


        char enc = (rand()%15)+65;
        string[1] = enc;
        string[2] = fdegree + enc;


        int base = 0;
        for (int i=4; i<olength; i+=3)
        {
            if (tstring[base]==' ')
            {
                string[i] = 68+fdegree;
                string[i+1] = 64+fdegree;
                base = base+1;
                continue;
            }
            string[i] = tstring[base]+fdegree;
            string[i+1] = tstring[base]+sdegree;
            base = base + 1;
            string[olength] = '\0';

        }
        free(tstring);
        char cpy [olength];
        strcpy(cpy, string);
        std::string returning(cpy);
        return returning;
    }

    std::string decrypt (std::string str)
    {
        char string[str.length()];
        strcpy(string, str.c_str());
        int length = strlen(string);
        char * tstring;
        tstring = (char*)malloc(sizeof(char)*10000);
        strcpy(tstring, string);
        strcpy(string, "");
        int flength = length - 4;
        flength = flength/3;
        int fdegree, sdegree;
        sdegree = tstring[0]-66;
        if (tstring[0]>tstring[length-1])
        {
            fdegree = tstring[0] - tstring[length-1];
            fdegree = fdegree % 16;
        }
        else
        {

            fdegree = tstring[length-1] - tstring[0];

            fdegree = fdegree % 16;
        }
        int base = 0;
        char * dec;
        dec = (char*)malloc(sizeof(char)*10000);
        for (int i=4; i<length; i+=3)
        {
            if (tstring[i]==68+fdegree&&tstring[i+1]==64+fdegree)
            {
                dec[base] = ' ';
                base++;
                continue;
            }
            else
            {
                dec[base] = tstring[i] - fdegree;
                char checker;
                checker = tstring[i+1] - sdegree;

            }

            base = base + 1;
            continue;

        }
        dec[base+1] = '\0';
        strcpy(string, dec);
        free(tstring);
        std::string returning(string);

        return returning;
    }


}


#endif //CUBECLUB_RS_ASM_TREX_H
