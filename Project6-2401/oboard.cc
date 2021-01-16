/*
 * Gerald McGee
 * Ohio University 
 * 12/13/20
 * Othello board implementation file
*/

#include "oboard.h"
#include "colors.h"
#include "bpiece.h"
#include <iostream>
#include <iostream>
#include <queue>

namespace main_savitch_14{

void oboard::restart(){
    for(size_t i = 0; i < 8; i++){
        for(size_t j = 0; j < 8; j++){
            othelloboard[i][j].set_N();
        }    
    }
    othelloboard[3][4].set_B();
    othelloboard[4][3].set_B();
    othelloboard[3][3].set_W();
    othelloboard[4][4].set_W();

    computer = 'B';
    user = 'W';
    passCounter = 0;
    quit = false;
    game::restart();
}
void oboard::make_move(const std::string& move){
    if(!is_legal(move)) return;
     if(move[0] == 'q' || move[0] == 'Q'){
        quit = true;
        return;
    }
    if(move == "xx" || move == "XX"){ // both players have no valid moves game over
        if(passCounter < 2){
           ++passCounter;
        }
        game::make_move(move);
        return;
    }
    passCounter = 0;

    // check for pass move here, we just increment pass and game#
    int row = int(toupper(move[0]) - 'A');
    int column = int(move[1] - '1');
    
    if(next_mover() == HUMAN){
        othelloboard[row][column].set_W();
    }
    else if(next_mover() == COMPUTER){
        othelloboard[row][column].set_B();
    }

    searchFlip(move);
    game::make_move(move);
} 
bool oboard::is_legal(const std::string& move) const{
    if(move[0] == 'q' || move[0] == 'Q'){
        return true;
    }
   if(move == "xx" || move == "XX"){
       if(novalid_moves() == true){
           return true;
        }
       return false;
   }
    int row = int(toupper(move[0]) - 'A');
    int column = int(move[1] - '1'); 
    if(othelloboard[row][column].is_N() == true){
        if(search_all(row, column) == true){
            return true;
        }  
    }
    return false;
}
bool oboard::validPass() const{
    if(novalid_moves() == true){
        return true;
    }
    return false;
}
void oboard::display_status() const{
    cout << endl << endl << endl;
    const string LETTERS = "ABCDEFGH";

    // Header
    cout << BOLD << B_BLUE << "                ";
    cout << BOLD << B_BLUE << WHITE << "OTHELLO" << "                " ;

    cout << RESET << endl;

    cout << BOLD << B_BLUE << "   ";
    int i = 0;
    while (i < 8){
        cout << "  " << i + 1 << " ";
        ++i;
    }


    cout << "    " << RESET << endl;
    print();

    for(int i = 0; i < 8; i++){
        cout << BOLD << B_BLUE;
        cout << " " << LETTERS[i] << " ";
            
        cout << BLUE;
        for(int j = 0; j < 8; j++){
            if (othelloboard[i][j].is_N()){
                cout << B_RED  << "|   ";
            }
            else if (othelloboard[i][j].is_B()){
                cout << B_RED <<  "|";
                cout << B_BLUE  << " B ";
            }
            else {
                cout << B_RED <<  "|";
                cout << B_WHITE  << " W ";
            }
        }
        cout << "|";

        cout << BOLD << B_BLUE;
        cout << " " << WHITE << LETTERS[i] << " ";
        cout << RESET << endl;
        print();

    }

    cout << BOLD << B_BLUE << "   ";
    int j = 0;
    while (j < 8){
        cout << "  " << j + 1 << " ";
        ++j;
    } 

    cout << BOLD <<  B_BLUE  << "    " << RESET << endl;
    cout << RESET;
    cout << endl;
}
oboard* oboard::clone() const{
    return new oboard(*this);
}
void oboard::compute_moves(std::queue<std::string> &moves) const{
    string tmp;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; ++j){
            tmp = char(i + 65);
            tmp += char(j + 49);
            if(is_legal(tmp)){
                moves.push(tmp);
            }
        }
    }
}
int oboard::evaluate() const{
    int tmp = bscore() - wscore();
    return tmp;
}
bool oboard::is_game_over() const{
    if(quit)
        return true;
    else if(passCounter == 2)
        return true;
    else if((wscore() + bscore()) == 64)
        return true;

    return false;
}
void print(){
    cout << B_BLUE << "   ";
    cout << B_RED << BLUE << "---------------------------------";
    cout << B_BLUE << "   " << RESET;
    cout << endl;
}

void oboard::searchFlip(const std::string &move){ 
    int row = int(toupper(move[0]) - 'A');
    int column = int(move[1] - '1'); 
    int flipNum = 0;
    int dtmp = row; int utmp = row; int rtmp = column; int ltmp = column;
    int RUPRow = row; int RUPColumn = column; int LUPRow = row; int LUPColumn = column;
    int right_downDiag_row = row; int right_downDiag_column = column; int left_DownDiag_row = row; int left_DownDiag_column = column;

    if(!is_edgeNotCorner(row, column) && (!is_corner(row, column))){
        if(searchUp(flipNum, row, column) == true){
            for(int i = 0; i < flipNum; ++i){
                othelloboard[utmp - 1][column].flip();
                --utmp;
            }
        }
        if(searchDown(flipNum, row, column) == true){
            for(int i = 0; i < flipNum; ++i){
                othelloboard[dtmp +1][column].flip();
                ++dtmp;
            }
        } 
        if(searchRight(flipNum, row, column) == true){
            for(int i = 0; i < flipNum; ++i){
                othelloboard[row][rtmp + 1].flip();
                ++rtmp;
            }
        } 
        if(searchLeft(flipNum, row, column) == true){
            for(int i = 0; i < flipNum; ++i){
               othelloboard[row][ltmp - 1].flip();
                --ltmp;
            }
        } 
        if(searchRUP_diagonol(flipNum, row, column) == true){
            for(int i = 0; i < flipNum; ++i){ 
                othelloboard[RUPRow - 1][RUPColumn+ 1].flip();
                --RUPRow;
                ++RUPColumn;
            } 
        }
        if(searchLUP_diagonol(flipNum, row, column) == true){ 
            for(int i = 0; i < flipNum; ++i){ 
                othelloboard[LUPRow - 1][LUPColumn - 1].flip();
                --LUPRow;
                --LUPColumn;
            } 
        }
        if(searchRDown_diagonol(flipNum, row, column) == true){
            for(int i = 0; i < flipNum; ++i){
                othelloboard[right_downDiag_row + 1][right_downDiag_column + 1].flip();
                ++right_downDiag_row;
                ++right_downDiag_column;
            }
        }  
        if(searchLDown_diagonol(flipNum, row, column) == true){
            for(int i = 0; i < flipNum; ++i){
                othelloboard[left_DownDiag_row + 1][left_DownDiag_column - 1].flip();
                ++left_DownDiag_row;
                --left_DownDiag_column;
            }
        }          
    }
    else if(is_edgeNotCorner(row,column) == true){
        if(row == 0){ // if the space is in row 0
            if(searchDown(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[dtmp +1][column].flip();
                    ++dtmp;
                }
            } 
            if(searchRight(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[row][rtmp + 1].flip();
                    ++rtmp;
                }   
            } 
            if(searchLeft(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[row][ltmp - 1].flip();
                    --ltmp;
                }
            } 
            if(searchRDown_diagonol(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[right_downDiag_row + 1][right_downDiag_column + 1].flip();
                    ++right_downDiag_row;
                    ++right_downDiag_column;
                }
            }  
            if(searchLDown_diagonol(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[left_DownDiag_row + 1][left_DownDiag_column - 1].flip();
                    ++left_DownDiag_row;
                    --left_DownDiag_column;
                }
            }          
        } // end of if the space is in row 0

        else if (row == 7){
            if(searchUp(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[utmp - 1][column].flip();
                    --utmp;
                }
            }
              if(searchRight(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[row][rtmp + 1].flip();
                    ++rtmp;
                }   
            } 
            if(searchLeft(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[row][ltmp - 1].flip();
                    --ltmp;
                }
            } 
            if(searchRUP_diagonol(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){ 
                    othelloboard[RUPRow - 1][RUPColumn+ 1].flip();
                    --RUPRow;
                    ++RUPColumn;
                } 
            }   
            if(searchLUP_diagonol(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){ 
                    othelloboard[LUPRow - 1][LUPColumn - 1].flip();
                    --LUPRow;
                    --LUPColumn;
                } 
            }
        } // end of is the space is in row 7
        else if(column == 0){
            if(searchUp(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[utmp - 1][column].flip();
                    --utmp;
                }
            }
            if(searchDown(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[dtmp +1][column].flip();
                    ++dtmp;
                }   
            } 
            if(searchRight(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[row][rtmp + 1].flip();
                    ++rtmp;
                }
            } 
            if(searchRUP_diagonol(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){ 
                    othelloboard[RUPRow - 1][RUPColumn+ 1].flip();
                    --RUPRow;
                    ++RUPColumn;
                }    
            }
            if(searchRDown_diagonol(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[right_downDiag_row + 1][right_downDiag_column + 1].flip();
                    ++right_downDiag_row;
                    ++right_downDiag_column;
                }
            }  


        } // end of if the space is in column 0 
        else if (column == 7){
            if(searchLeft(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[row][ltmp - 1].flip();
                    --ltmp;
                }
            } 
            if(searchLUP_diagonol(flipNum, row, column) == true){ 
                for(int i = 0; i < flipNum; ++i){ 
                    othelloboard[LUPRow - 1][LUPColumn - 1].flip();
                    --LUPRow;
                    --LUPColumn;
                } 
            }
            if(searchLDown_diagonol(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[left_DownDiag_row + 1][left_DownDiag_column - 1].flip();
                    ++left_DownDiag_row;
                    --left_DownDiag_column;
                }
            }
            if(searchUp(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[utmp - 1][column].flip();
                    --utmp;
                }
            }
            if(searchDown(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[dtmp +1][column].flip();
                    ++dtmp;
                }   
            } 
        }
    } 
    // end of edge not corner
    else if(is_corner(row, column) == true){
        if((row == 0) && (column == 0)){
            if(searchDown(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[dtmp +1][column].flip();
                    ++dtmp;
                }
            } 
            if(searchRight(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[row][rtmp + 1].flip();
                    ++rtmp;
                }
            } 
            if(searchRDown_diagonol(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[right_downDiag_row + 1][right_downDiag_column + 1].flip();
                    ++right_downDiag_row;
                    ++right_downDiag_column;
                }
            }  
        }
        else if((row == 0) && (column == 7)){
            if(searchDown(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[dtmp +1][column].flip();
                    ++dtmp;
                }
            }
            if(searchLDown_diagonol(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[left_DownDiag_row + 1][left_DownDiag_column - 1].flip();
                    ++left_DownDiag_row;
                    --left_DownDiag_column;
                }
            }
            if(searchLeft(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[row][ltmp - 1].flip();
                    --ltmp;
                }
            }           
        }
        else if((row == 7) &&(column == 0)){
            if(searchRight(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[row][rtmp + 1].flip();
                    ++rtmp;
                }
            } 
            if(searchRUP_diagonol(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){ 
                    othelloboard[RUPRow - 1][RUPColumn+ 1].flip();
                    --RUPRow;
                    ++RUPColumn;
                } 
            }
            if(searchUp(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[utmp - 1][column].flip();
                    --utmp;
                }
            }
        }
        else if((row == 7) && (column == 7)){
            if(searchUp(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[utmp - 1][column].flip();
                    --utmp;
                }
            }
            if(searchLeft(flipNum, row, column) == true){
                for(int i = 0; i < flipNum; ++i){
                    othelloboard[row][ltmp - 1].flip();
                    --ltmp;
                }
            } 
            if(searchLUP_diagonol(flipNum, row, column) == true){ 
                for(int i = 0; i < flipNum; ++i){ 
                    othelloboard[LUPRow - 1][LUPColumn - 1].flip();
                    --LUPRow;
                    --LUPColumn;
                } 
            }
        }
        
    } 
}
bool oboard::searchUp(int &tmp, int row, int column)const{ // search up
    tmp = 0;
    if (next_mover() == HUMAN){
        int rt = 0;
        while (row > 0){
            if(othelloboard[row - 1][column].is_W() == true){
                if(rt > 0)
                    return true;
                else 
                    return false;
            }
            else if(othelloboard[row - 1][column].is_N() == true)
                return false;
            else {
                ++tmp;
            }
            --row;
            ++rt;
        }
    }
     else if(next_mover() == COMPUTER){
        int rt = 0;
        while (row > 0){
            if(othelloboard[row -1][column].is_B() == true){
                if(rt > 0)
                    return true;
                else 
                    return false;
            }
            else if(othelloboard[row - 1][column].is_N() == true) 
                return false;
            else{
                ++tmp;
            }
            --row;
            ++rt;
        }
    }
    return false;
}
bool oboard::searchLeft(int &tmp, int row, int column)const{ // search left
    tmp = 0;
    if (next_mover() == HUMAN){
        int rt = 0;
        while (column > 0){
            if(othelloboard[row][column - 1].is_W() == true){
                if(rt > 0)
                    return true;
                else 
                    return false;    
            }
            else if(othelloboard[row][column - 1].is_N() == true)
                return false;
            else{
                ++tmp;
            }
            --column;
            ++rt;
        }
    }else if(next_mover() == COMPUTER){
        int rt = 0;
        while (column > 0){
            if(othelloboard[row][column - 1].is_B() == true){
                if(rt > 0)
                    return true;
                else 
                    return false;
            }
            else if(othelloboard[row][column - 1].is_N() == true) 
                return false;
            else{
                ++tmp;
            }
            --column;
            ++rt;
        }
    }
    return false; 
}
bool oboard::searchDown(int &tmp, int row, int column)const{  // search Down 
    tmp = 0;
    if (next_mover() == HUMAN){
        int rt = 0;
        while(row < 7){
            if(othelloboard[row + 1][column].is_W() == true)
                if (rt > 0)
                    return true;
                else
                    return false;
            else if(othelloboard[row + 1][column].is_N() == true)
                return false;
            else{
                ++tmp;
            }
            ++row;
            ++rt;
        }
    } else if (next_mover() == COMPUTER){
        int rt = 0;
        while(row < 7){
            if(othelloboard[row + 1][column].is_B() == true){
                if (rt > 0)
                    return true;
                else
                    return false;
            }
            else if(othelloboard[row + 1][column].is_N() == true) 
                return false;
            else{
                ++tmp;
            }
            ++row;
            ++rt;
        }
    }
    return false;
}
bool oboard::searchRight(int &tmp, int row, int column)const{ //search right
    tmp = 0;
    if (next_mover() == HUMAN){
        int rt = 0;
        while(column < 7){
            if(othelloboard[row][column + 1].is_W() == true){
                if (rt > 0)
                    return true;
                else
                    return false;
            }
            else if(othelloboard[row][column + 1].is_N() == true)
                return false;
            else{
                ++tmp;
            }
            ++column;
            ++rt;
        }
    } else if (next_mover() == COMPUTER){
        int rt = 0;
        while(column < 7){
            if(othelloboard[row][column + 1].is_B() == true){
                if (rt > 0)
                    return true;
                else
                    return false;
            }
            else if(othelloboard[row][column + 1].is_N() == true) 
                return false;
            else{
                ++tmp;
            }
            ++column;
            ++rt;
        }
    }
    return false;
}
bool oboard::searchRUP_diagonol(int &tmp, int row, int column)const{ // search right up diagonol
    tmp = 0;
    if(next_mover() == HUMAN){
        int rt = 0;
        while(column < 7 && row > 0){
            if(othelloboard[row - 1][column + 1].is_W() == true){
               if (rt > 0)
                    return true;
                else
                    return false;
            }
            else if(othelloboard[row - 1][column + 1].is_N() == true)
                return false;
            else{
                ++tmp;
            }
            ++column;
            --row;
            ++rt;
        }
    } else if (next_mover() == COMPUTER){
        int rt = 0;
        while(column < 7 && row > 0){
            if(othelloboard[row - 1][column + 1].is_B() == true){
                if (rt > 0)
                    return true;
                else
                    return false;
            }
            else if(othelloboard[row - 1][column + 1].is_N() == true)
                return false;
            else{
                ++tmp;
            }
            ++column;
            --row;
            ++rt;
        }
    }
    return false;
}
bool oboard::searchLUP_diagonol(int &tmp, int row, int column)const{ // search left up diagonol
    tmp = 0;
    if(next_mover() == HUMAN){
        int rt = 0;
        while(column > 0 && row > 0){
            if(othelloboard[row - 1][column - 1].is_W() == true){ 
               if (rt > 0)
                    return true;
                else
                    return false;
            }
            else if(othelloboard[row - 1][column - 1].is_N() == true)
                return false;
            else{
                ++tmp;
            }
            ++rt;
            --column;
            --row;
        }
    } else if (next_mover() == COMPUTER){
        int rt = 0;
        while(column > 0 && row > 0){
            if(othelloboard[row - 1][column - 1].is_B() == true){
               if (rt > 0)
                    return true;
                else
                    return false;
            }
            else if(othelloboard[row - 1][column - 1].is_N() == true)
                return false;
            else{
                ++tmp;
            }
            --column;
            --row;
            ++rt;
        }
    }
    return false;
}
bool oboard::searchRDown_diagonol(int &tmp, int row, int column)const{ // search right-down diagonol
    tmp = 0;
    if(next_mover() == HUMAN){
        int rt = 0;
        while(column < 7 && row < 7){
            if(othelloboard[row + 1][column + 1].is_W() == true){
                if (rt > 0)
                    return true;
                else
                    return false;
            }
            else if(othelloboard[row + 1][column + 1].is_N() == true)
                return false;
            else{
                ++tmp;
            }
            ++column;
            ++row;
            ++rt;
        }
    } else if (next_mover() == COMPUTER){
        int rt = 0;
        while(column < 7 && row < 7){
            if(othelloboard[row + 1][column + 1].is_B() == true){
                if (rt > 0)
                    return true;
                else
                    return false;
            }
            else if(othelloboard[row + 1][column + 1].is_N() == true)
                return false;
            else{
                ++tmp;
            }
            ++column;
            ++row;
            ++rt;
        }
    }
    return false;
}
bool oboard::searchLDown_diagonol(int &tmp, int row, int column)const{ // search left, down diagonol
    tmp = 0;
    if(next_mover() == HUMAN){
        int rt = 0;
        while(column > 0 && row < 7){
            if(othelloboard[row + 1][column - 1].is_W() == true){
                if (rt > 0)
                    return true;
                else
                    return false;
            }
            else if(othelloboard[row + 1][column - 1].is_N() == true)
                return false;
            else{
                ++tmp;
            }
            --column;
            ++row;
            ++rt;
        }
    } else if (next_mover() == COMPUTER){
        int rt = 0;
        while(column > 0 && row < 7){
            if(othelloboard[row + 1][column - 1].is_B() == true){
                if (rt > 0)
                    return true;
                else
                    return false;
            }
            else if(othelloboard[row + 1][column - 1].is_N() == true)
                return false;
            else{
                ++tmp;
            }
            --column;
            ++row;
            ++rt;
        }
    }
    return false;
}
bool oboard::search_all(int row, int column) const{  // searches all possible directions for a  spot on the board, if we have a flank for that spot we return true
    int garb = 0;
    int dtmp = row; int utmp = row; int rtmp = column; int ltmp = column;
    int RUPRow = row; int RUPColumn = column; int LUPRow = row; int LUPColumn = column;
    int right_downDiag_row = row; int right_downDiag_column = column; int left_DownDiag_row = row; int left_DownDiag_column = column;

    if((!is_edgeNotCorner(row, column)) && (!is_corner(row, column))){
      
        if(searchUp(garb, row, column) == true){
          return true;
        }
        if(searchDown(garb, row, column) == true){
            return true;
        } 
        if(searchRight(garb, row, column) == true){
           return true;
        } 
        if(searchLeft(garb, row, column) == true){
            return true;
        } 
        if(searchRUP_diagonol(garb, row, column) == true){
            return true;
        }
        if(searchLUP_diagonol(garb, row, column) == true){ 
            return true;
        }
        if(searchRDown_diagonol(garb, row, column) == true){
            return true;
        }  
        if(searchLDown_diagonol(garb, row, column) == true){
            return true;
        }          
    }
    else if(is_edgeNotCorner(row, column) == true){
        if(row == 0){ // if the space is in row 0
            if(searchDown(garb, row, column) == true){
               return true;
            } 
            if(searchRight(garb, row, column) == true){
               return true;
            } 
            if(searchLeft(garb, row, column) == true){
                return true;
            } 
            if(searchRDown_diagonol(garb, row, column) == true){
                return true;
            }  
            if(searchLDown_diagonol(garb, row, column) == true){
                return true;
            }          
        } // end of if the space is in row 0

        else if (row == 7){
            if(searchUp(garb, row, column) == true){
               return true;
            }
            if(searchRight(garb, row, column) == true){
                return true;  
            } 
            if(searchLeft(garb, row, column) == true){
                return true;
            } 
            if(searchRUP_diagonol(garb, row, column) == true){
                return true;
            }   
            if(searchLUP_diagonol(garb, row, column) == true){
               return true;
            }
        } // end of is the space is in row 7
        else if(column == 0){
            if(searchUp(garb, row, column) == true){
                return true;
            }
            if(searchDown(garb, row, column) == true){
                return true;
            } 
            if(searchRight(garb, row, column) == true){
                return true;
            } 
            if(searchRUP_diagonol(garb, row, column) == true){
               return true;
            }
            if(searchRDown_diagonol(garb, row, column) == true){
                return true;
            }  


        } // end of if the space is in column 0 
        else if (column == 7){
            if(searchLeft(garb, row, column) == true){
                return true;
            } 
            if(searchLUP_diagonol(garb, row, column) == true){ 
                return true;
            } 
        
            if(searchLDown_diagonol(garb, row, column) == true){
                return true;
            }
            if(searchUp(garb, row, column) == true){
               return true;
            }
            if(searchDown(garb, row, column) == true){
                return true;
            } 
        }
    }
    else if(is_corner(row, column) == true){
        if((row == 0) && (column == 0)){
            if(searchDown(garb, row, column) == true){
               return true;
            } 
            if(searchRight(garb, row, column) == true){
               return true;
            } 
            if(searchRDown_diagonol(garb, row, column) == true){
                return true;
            }  
        }
        else if((row == 0) && (column == 7)){
            if(searchDown(garb, row, column) == true){
                return true;
            }
            if(searchLDown_diagonol(garb, row, column) == true){
                return true;
            }
            if(searchLeft(garb, row, column) == true){
                return true;
            }           
        }
        else if((row == 7) &&(column == 0)){
            if(searchRight(garb, row, column) == true){
               return true;
            } 
            if(searchRUP_diagonol(garb, row, column) == true){
                return true;
            }
            if(searchUp(garb, row, column) == true){
               return true;
            }
        }
        else if((row == 7) && (column == 7)){
            if(searchUp(garb, row, column) == true){
               return true;
            }
            if(searchLeft(garb, row, column) == true){
               return true;
            } 
            if(searchLUP_diagonol(garb, row, column) == true){ 
                return true;
            }
        }
    }
    return false;
} 
bool oboard::is_edgeNotCorner(int row, int column) const{ // search five ways here, if a piece is an edge 
    if (((row == 0) || (column == 0) || (row == 7) || (column == 7)) && (!is_corner(row, column))){
        return true;  
    }  
    return false;
}
bool oboard::is_corner(int row, int column) const{ // function to determine if a piece is in a corner, search three ways
    if((row == 0) && (column == 0))
        return true;
    else if((row == 0) && (column == 7))
        return true;
    else if((row == 7) &&(column == 0))
        return true;
    else if((row == 7) && (column == 7))
        return true;

    return false;
}
bool oboard::novalid_moves() const{
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if(othelloboard[i][j].is_N()){
               if(search_all(i, j)){
                   return false;
                }
            }
        }
    }
    return true;
}
int oboard::wscore() const{ // calculates white score
    int score = 0;
    for(size_t i = 0; i < 8; ++i){
        for(size_t j = 0; j < 8; ++j){
            if(othelloboard[i][j].is_W())
                ++score;
        }
    }
    return score;
}
int oboard::bscore() const{ // calculates black score
    int score = 0;
    for(size_t i = 0; i < 8; ++i){
        for(size_t j = 0; j < 8; ++j){
            if(othelloboard[i][j].is_B())
                ++score;
        }
    }
    return score;
}
void oboard::display_message(const std::string& message) const{
    if(message != "Illegal move.\n"){
        cout << "White: " << wscore() << "    " << "Blue: " << bscore() << endl; // prints score
        cout << "XX - pass   Q - quit" << endl;
    }
    game::display_message(message);
}
game::who oboard::winning()const{
    int value = evaluate( ); 

	if (value > 0)
	    return COMPUTER;
	else if (value < 0)
	    return HUMAN;
	else
	    return NEUTRAL;

}


} // end of namespace