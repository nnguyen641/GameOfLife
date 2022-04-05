// Nathan Nguyen
// 2370739
// nnguyen1@chapman.edu
// CPSC350 - 01
// Assignment 3

#include "game.h"

// default constructor
game::game(){
  genNum = 0;
    
}

// destructor
game::~game(){

}

// Purpose: Plays one generation of the current board and copies the new generation to a new board
// Parameters: *b as a pointer to the current board, *c as a pointer to the next board, mode as a char to determine which rules are being used
// Returns: void
void game::play(Board *b, Board *c, char mode){
  int sum = 0;
  char a;

  if(mode == 'C'){
    for(int i = 0; i < b->getRow(); ++i){
      for(int j = 0 ; j < b->getColumn(); ++j){
        sum = mode::checkClassic(i, j, b);
        a = b->getAt(i, j);
        mode::ruleCheck(sum, c, a, i, j);
      }
    }
  }else if(mode == 'M'){
    for(int i = 0; i < b->getRow(); ++i){
      for(int j = 0 ; j < b->getColumn(); ++j){
        sum = mode::checkMirror(i, j, b);
        a = b->getAt(i, j);
        mode::ruleCheck(sum, c, a, i, j);
      }
    }
  }else if(mode == 'D'){
    for(int i = 0; i < b->getRow(); ++i){
      for(int j = 0 ; j < b->getColumn(); ++j){
        sum = mode::checkDonut(i, j, b);
        a = b->getAt(i, j);
        mode::ruleCheck(sum, c, a, i, j);
      }
    }
  }

}
