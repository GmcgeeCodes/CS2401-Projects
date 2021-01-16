/*
 * Gerald McGee
 * Ohio University 
 * 12/13/20
 * Othello board class 
*/
#ifndef OBOARD_H
#define OBOARD_H 
#include <queue>
#include <string>
#include "bpiece.h"
#include "game.h"
#include "colors.h"
#include <cstdlib>
#include <iostream>

namespace main_savitch_14{

class oboard: public game{
    public:
        oboard(){
            restart();
        }
        void restart();  //
        void make_move(const std::string& move); //
        bool is_legal(const std::string& move) const; // 
        oboard* clone() const; //
        void compute_moves(std::queue<std::string> &moves) const;
        void display_message(const std::string &message) const;
        bool novalid_moves() const;
        int wscore() const; //updates and can return white score
        int bscore() const; // updates and can return black score
    
        void display_status() const;
        int evaluate() const;
        bool is_game_over() const;

    private:
        char user;
        char computer;
        bpiece othelloboard[8][8];
        int passCounter;
        bool quit;
        void searchFlip(const std::string &move);
        // 8 search helpers **************************************************************
        bool searchUp(int &tmp, int row, int column)const;
        bool searchDown(int &tmp, int row, int column)const;
        bool searchRight(int &tmp, int row, int column)const; 
        bool searchLeft(int &tmp, int row, int column)const;
        // diagonols
        bool searchRUP_diagonol(int &tmp, int row, int column)const;
        bool searchLUP_diagonol(int &tmp, int row, int column)const;
        bool searchRDown_diagonol(int &tmp, int row, int column)const;
        bool searchLDown_diagonol(int &tmp, int row, int column)const;
        // Seach all 
        bool search_all(int row,int column) const; // this function searches if a position has a valid flank
        // ********************************************************************************
        bool is_edgeNotCorner(int row, int column) const;
        bool is_corner(int row, int column) const;
        bool validPass() const;
        game::who winning() const;
};
void print();

}
#endif
