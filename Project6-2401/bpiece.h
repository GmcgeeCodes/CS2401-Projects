/*
 * Gerald McGee
 * Ohio University 
 * 12/13/20
 * Othello board class piece class definition
 */
#ifndef BPIECE_H
#define BPIECE_H
#include "colors.h"


class bpiece{
    public:
        bpiece(char color = 'N');
        
    void flip(){
        if(W)
            set_B();
        else
            set_W();
    }
    void set_W(){
        W = true;
        B = false;
        N = false;
    }
    void set_B(){
        W = false;
        B = true;
        N = false;
    }
    void set_N(){
        W = false;
        B = false;
        N = true;
    }
    bool is_W() const{
        if(W)
            return true;
        return false;
    }
    bool is_B() const{
        if(B)
            return true;

        return false;
    }
    bool is_N() const{
        if(N)
            return true;
        return false;
    }
    
    private:
    bool W;
    bool B;
    bool N;
};
#endif 