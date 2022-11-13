//
// Created by Rufelle on 13/11/2022.
//

#ifndef CUBECLUB_RS_ASM_STRINGCONSTRUCT_H
#define CUBECLUB_RS_ASM_STRINGCONSTRUCT_H

namespace chain{
    struct string_construct{
        std::string string;
        bool operators[9]; /* operators written guide
 * 0 - if operator is present
 * 1 - absolute comment
 * 2 - in-line comment
 * 3 - label
 * 4 - decimal
 * 5 - hex
 * 6 - binary
 * 7 - active operator
 * 8 - secondary operator
 */
        char _operator;
        char secondary_operator;
        bool _secondaryop[5]; /*written guide secondaryop
     *  0 - if secondary operator is needed
     *  1 - if secondary operator is decimal
     *  2 - if secondary operator is hex
     *  3 - if secondary operator is binary
     *  4 - if it is a label
     */

        string_construct(){
            clear();
        }

        void clear(){
            for (int i=0; i<9; i++){
                operators[i] = false;
            }
            _operator = '\0';
            secondary_operator = '\0';
            for (int i=0; i<5; i++){
                _secondaryop[i] = false;
            }
        }
    };
}




#endif //CUBECLUB_RS_ASM_STRINGCONSTRUCT_H
