// Nathan Nguyen
// 2370739
// nnguyen1@chapman.edu
// CPSC350 - 01
// Assignment 3


#include "mode.h"

// default constructor
mode::mode(){
    modeCase = '\0';
}

// destructor
mode::~mode(){
    // intentionally left blank
}

// Purpose: Checks a board using the classic mode rules and returns the sum of occupied neighbor cells
// Parameters: row as an int, column as an int, *b as a pointer to a board
// Returns: An int representing the sum of occupied neighbor cells
int mode::checkClassic(int row, int column, Board *b){
    char currChar1;
    char currChar2;
    char currChar3;
    char currChar4;
    char currChar5;
    char currChar6;
    char currChar7;
    char currChar8;
    int sum = 0;

    // Corner 1
    if(row == 0 && column == 0){
        currChar1 = b->getAtSouth(row, column);
        currChar2 = b->getAtEast(row, column);
        currChar3 = b->getAtSouthEast(row, column);
        sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3);
        
        return sum;
    }
    
    // Corner 2
    if(row == 0 && (column == b->getColumn()-1)){
        currChar1 = b->getAtSouth(row, column);
        currChar2 = b->getAtWest(row, column);
        currChar3 = b->getAtSouthWest(row, column);
        sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3);
        
        return sum;
    }
    
    // Corner 3
    if((row == b->getRow()-1) && (column == b->getColumn()-1)){
        currChar1 = b->getAtNorth(row, column);
        currChar2 = b->getAtWest(row, column);
        currChar3 = b->getAtNorthWest(row, column);
        sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3);
        
        return sum;
    }
    
    // Corner 4
    if((row == b->getRow()-1) && column == 0){
        currChar1 = b->getAtNorth(row, column);
        currChar2 = b->getAtEast(row, column);
        currChar3 = b->getAtNorthEast(row, column);
        sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3);
      
        return sum;
    }
    
    // In between on top row
    if((row==0) && (column >0) && (column < b->getColumn()-1)){
        currChar1 = b->getAtEast(row, column);
        currChar2 = b->getAtWest(row, column);
        currChar3 = b->getAtSouth(row, column);
        currChar4 = b->getAtSouthEast(row, column);
        currChar5 = b->getAtSouthWest(row, column);
        
        sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5);
        
        return sum;
    }
    
    // In between on bottom row
    if((row == b->getRow()-1) && (column >0) && (column < b->getColumn()-1)){
        currChar1 = b->getAtEast(row, column);
        currChar2 = b->getAtWest(row, column);
        currChar3 = b->getAtNorth(row, column);
        currChar4 = b->getAtNorthEast(row, column);
        currChar5 = b->getAtNorthWest(row, column);
        
        sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5);
        
        return sum;
        
    }
    
    // In between left column
    if((column == 0) && (row >0) && (row < b->getRow()-1)){
        currChar1 = b->getAtSouth(row, column);
        currChar2 = b->getAtEast(row, column);
        currChar3 = b->getAtNorth(row, column);
        currChar4 = b->getAtSouthEast(row, column);
        currChar5 = b->getAtNorthEast(row, column);
        
        sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5);
        
        return sum;
        
    }
    
    // In between right column
    if((column == b->getColumn()-1) && (row > 0) && (row < b->getRow()-1)){
        currChar1 = b->getAtWest(row, column);
        currChar2 = b->getAtSouth(row, column);
        currChar3 = b->getAtNorth(row, column);
        currChar4 = b->getAtSouthWest(row, column);
        currChar5 = b->getAtNorthWest(row, column);
        
        sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5);
        
        return sum;
       
    }
    
    if((row > 0) && (row < b->getRow()-1) && (column > 0) && (column < b->getColumn()-1)){
        currChar1 = b->getAtEast(row, column);
        currChar2 = b->getAtWest(row, column);
        currChar3 = b->getAtNorth(row, column);
        currChar4 = b->getAtNorthEast(row, column);
        currChar5 = b->getAtNorthWest(row, column);
        currChar6 = b->getAtSouth(row, column);
        currChar7 = b->getAtSouthEast(row, column);
        currChar8 = b->getAtSouthWest(row, column);

        sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5) + checkNeighbor(currChar6) + checkNeighbor(currChar7) + checkNeighbor(currChar8);
        
        return sum;
        
    }
    
    return sum;
}

// Purpose: Checks a board using the mirror mode rules and returns the sum of occupied neighbor cells
// Parameters: row as an int, column as an int, *b as a pointer to a board
// Returns: An int representing the sum of occupied neighbor cells
int mode::checkMirror(int row, int col, Board *b){

  int sum = checkClassic(row, col, b);
  char c1;
  char c2;
  char c3;
  //check edge cases and add neighbors to sum
  if(row == 0 && col == 0){
    //top left corner
    c1 = b->getAt(row, col);
    c2 = b->getAtEast(row, col);
    c3 = b->getAtSouth(row, col);

    sum += (3*checkNeighbor(c1)) + checkNeighbor(c2) + checkNeighbor(c3);

  }else if((row== b->getRow()-1) && (col == 0)){
    //bottom left corner
    c1 = b->getAt(row, col);
    c2 = b->getAtEast(row, col);
    c3 = b->getAtNorth(row, col);

    sum += (3*checkNeighbor(c1)) + checkNeighbor(c2) + checkNeighbor(c3);
  }else if ((row == 0) && (col == b->getColumn()-1)){
    //top right corner
    c1 = b->getAt(row, col);
    c2 = b->getAtWest(row, col);
    c3 = b->getAtSouth(row, col);

    sum += (3*checkNeighbor(c1)) + checkNeighbor(c2) + checkNeighbor(c3);

  }else if((row== b->getRow()-1) && (col == b->getColumn()-1)){
    //bottom right corner
    c1 = b->getAt(row, col);
    c2 = b->getAtWest(row, col);
    c3 = b->getAtNorth(row, col);

    sum += (3*checkNeighbor(c1)) + checkNeighbor(c2) + checkNeighbor(c3);

  }else if(((row==0) || (row== b->getRow()-1)) && (col >0) && (col < b->getColumn()-1) ){
    //top and bottom edge cases, no corners
    c1 = b->getAt(row, col);
    c2 = b->getAtWest(row, col);
    c3 = b->getAtEast(row, col);

    sum += checkNeighbor(c1) + checkNeighbor(c2) + checkNeighbor(c3);
  }else if (((col == b->getColumn()-1) || (col == 0))&& (row >0) && (row< b->getRow()-1)) {
    //left and right edge cases
    c1 = b->getAt(row, col);
    c2 = b->getAtNorth(row, col);
    c3 = b->getAtSouth(row, col);

    sum += checkNeighbor(c1) + checkNeighbor(c2) + checkNeighbor(c3);
  }

  return sum;
}

// Purpose: Checks a board using the donut mode rules and returns the sum of occupied neighbor cells
// Parameters: row as an int, column as an int, *b as a pointer to a board
// Returns: An int representing the sum of occupied neighbor cells
int mode::checkDonut(int row, int column, Board *b){
    int sum = checkClassic(row, column, b);
    
    char currChar1;
    char currChar2;
    char currChar3;
    char currChar4;
    char currChar5;

    // Corner 1
    if(row == 0 && column == 0){
        currChar1 = b->getAt(0, b->getColumn()-1);
        currChar2 = b->getAt(row+1, b->getColumn()-1);
        currChar3 = b->getAt(b->getRow()-1, b->getColumn()-1);
        currChar4 = b->getAt(b->getRow()-1, column + 1);
        currChar5 = b->getAt(b->getRow()-1, column);
        
        sum += checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5);
    }
    
    // Corner 2
    if(row == 0 && (column == b->getColumn()-1)){
        currChar1 = b->getAt(b->getRow()-1, b->getColumn()-1);
        currChar2 = b->getAt(b->getRow()-1, b->getColumn()-2);
        currChar3 = b->getAt(row, 0);
        currChar4 = b->getAt(row + 1, 0);
        currChar5 = b->getAt(b->getRow()-1, 0);
        
        sum += checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5);
    }
    
    // Corner 3
    if((row == b->getRow()-1) && (column == b->getColumn()-1)){
        currChar1 = b->getAt(0,0);
        currChar2 = b->getAt(0, b->getColumn()-2);
        currChar3 = b->getAt(0, b->getColumn()-1);
        currChar4 = b->getAt(b->getRow()-1, 0);
        currChar5 = b->getAt(b->getRow()-2, 0);
        
        sum += checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5);
    }
    
    // Corner 4
    if((row == b->getRow()-1) && column == 0){
        currChar1 = b->getAt(0,0);
        currChar2 = b->getAt(0, 1);
        currChar3 = b->getAt(0, b->getColumn()-1);
        currChar4 = b->getAt(b->getRow()-1, b->getColumn()-1);
        currChar5 = b->getAt(b->getRow()-2, b->getColumn()-1);
        
        sum += checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5);
    }
    
    // In between on top row
    if((row==0) && (column >0) && (column < b->getColumn()-1)){
        currChar1 = b->getAt(b->getRow()-1, column);
        currChar2 = b->getAt(b->getRow()-1, column-1);
        currChar3 = b->getAt(b->getRow()-1, column+1);

        sum += checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3);
    }
    
    // In between on bottom row
    if((row == b->getRow()-1) && (column >0) && (column < b->getColumn()-1)){
        currChar1 = b->getAt(0, column);
        currChar2 = b->getAt(0, column-1);
        currChar3 = b->getAt(0, column+1);

        sum += checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3);
        
    }
    
    // In between left column
    if((column == 0) && (row >0) && (row < b->getRow()-1)){
        currChar1 = b->getAt(row, b->getColumn()-1);
        currChar2 = b->getAt(row+1, b->getColumn()-1);
        currChar3 = b->getAt(row-1, b->getColumn()-1);

        sum += checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3);
    }
    
    // In between right column
    if((column == b->getColumn()-1) && (row > 0) && (row < b->getRow()-1)){
        currChar1 = b->getAt(row, 0);
        currChar2 = b->getAt(row+1, 0);
        currChar3 = b->getAt(row-1, 0);

        sum += checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3);
       
    }
    
    return sum;
}

// Purpose: Checks whether the character in the specified cell is occupied or not
// Parameters: row as an int, column as an int, *b as a pointer to a board
// Returns: An int representing whether the cell is occupied (0 for no, 1 for yes)
int mode::checkNeighbor(char c){
    switch(c){
        case '-':
            return 0;
            break;
        case 'X':
            return 1;
            break;
        default:
            return -1;
            break;
    }
}

// Purpose: Checks the sum of occupied neighbor cells and determines whether the current cell needs to be occupied or empty
// Parameters: sum as an int, row as an int, column as an int, *c as a pointer to a new board to set the new generation
// Returns: void
void mode::ruleCheck(int sum, Board *c, char a, int row, int column){
  switch(sum){
    case 0:
      c->setAt(row, column, '-');
      break;
    case 1:
      c->setAt(row, column, '-');
      break;
    case 2:
      c->setAt(row, column, a);
      break;
    case 3:
      c->setAt(row, column, 'X');
      break;
    case 4:
      c->setAt(row, column, '-');
      break;
    default:
      c->setAt(row, column, '-');
      break;
  }

}

