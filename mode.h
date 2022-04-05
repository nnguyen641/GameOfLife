// Nathan Nguyen
// 2370739
// nnguyen1@chapman.edu
// CPSC350 - 01
// Assignment 3

#ifndef mode_h
#define mode_h

#include <iostream>
#include <exception>
#include "mapProcess.h"
#include "board.h"

using namespace std;

class mode{
public:
    
    // default constructor
    mode();
    // overloaded constructor
    mode(char m, Board b);
    // destructor
    ~mode();
    
    //Methods
    
    static int checkClassic(int row, int col, Board *b);
    static int checkMirror(int row, int col, Board *b);
    static int checkDonut(int row, int col, Board *b);
    static int checkNeighbor(char c);
    static void ruleCheck(int sum, Board *c, char a, int row, int column);
    
private:
    char modeCase;
    
};

#endif
