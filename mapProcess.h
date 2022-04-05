// Nathan Nguyen
// 2370739
// nnguyen1@chapman.edu
// CPSC350 - 01
// Assignment 3

#ifndef mapProcess_h
#define mapProcess_h

#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "board.h"

using namespace std;

class mapProcess{
    
public:
    
    // default constructor
    mapProcess();
    // overloaded constructor
    mapProcess(string inputFile);
    // destructor
    ~mapProcess();
    
    // methods
    
    Board *readFile(string input); 
    
    Board *makeMap(int row, int col, double density);
    
private:
    
    char m_choice;
    string m_mapFile;
    
    unsigned int m_row;
    unsigned int m_col;
    double m_density;
    
};

#endif /* mapProcess_h */
