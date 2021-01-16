// Implementation file for the board piece (bpiece class)
#include "bpiece.h"
bpiece::bpiece(char color){
        color = toupper(color);
        if(color == 'W'){
            W = true;
            B =false;
            N = false;
        }
        else if (color == 'B'){
            W = false;
            B = true;
            N = false;
        }
        else {
            W = false;
            B = false;
            N = true;
        }
}