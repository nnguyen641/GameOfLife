// Nathan Nguyen
// 2370739
// nnguyen1@chapman.edu
// CPSC350 - 01
// Assignment 3

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <exception>
#include <string>
#include <stdio.h>
#include "board.h"
#include "mode.h"

using namespace std;

class game{
  public:
    game(); //default constructor
    ~game(); // destructor
    
    // methods
    void play(Board *b, Board *c, char mode);

  private:
    int genNum; //keep track of generation number

};

#endif
