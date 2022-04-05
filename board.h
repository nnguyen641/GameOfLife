// Nathan Nguyen
// 2370739
// nnguyen1@chapman.edu
// CPSC350 - 01
// Assignment 3

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <exception>
#include <string>
#include <stdio.h>
#include <fstream>
#include <sstream>

using namespace std;

class Board{
  public:
    Board(); //default constructor
    ~Board(); // destructor
    Board(int row, int column); // overloaded constructor

    // accessors
    unsigned int getRow();
    unsigned int getColumn();
    
    // methods
    char getAt(int row, int column);
    char getAtNorth(int row, int column);
    char getAtSouth(int row, int column);
    char getAtWest(int row, int column);
    char getAtEast(int row, int column);
    char getAtNorthWest(int row, int column);
    char getAtNorthEast(int row, int column);
    char getAtSouthWest(int row, int column);
    char getAtSouthEast(int row, int column);

    void copyBoard(Board *b);
    
    void clear();

    bool compare(Board *b);
    
    void setAt(int row, int column, char c);
    
    void print();
    
    void printToFile(std::ofstream *pfile, int generation);

    bool isEmpty();
    
  private:
    int rowNum; //number of rows
    int columnNum; //number of columns

    char **curr;
    
};

#endif
