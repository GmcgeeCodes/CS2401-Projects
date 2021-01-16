/*****************************************************
This is a sample of what the main should like for the first phase of the
Othello game.
	John Dolan	Ohio University		Fall 2019
*************************************************************/
#include<iostream>
#include "oboard.h"
#include "game.h"
#include "bpiece.h"
using namespace std;
using namespace main_savitch_14;

int main(){
   oboard mygame;
   oboard::who winner;
   winner = mygame.play();
   switch(winner){
      case oboard::HUMAN:
         cout << "White wins" <<endl;
      break;
      case oboard::COMPUTER:
         cout << "Blue wins" <<endl;
      break;
      case oboard::NEUTRAL:
         cout << "Tie" << endl; 
      break;
   }
   cout << "Final Score " << endl;
   cout << "White: " << mygame.wscore() <<"  " << "Black: " << mygame.bscore() << endl;
return 0;
}
