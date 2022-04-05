// Nathan Nguyen
// 2370739
// nnguyen1@chapman.edu
// CPSC350 - 01
// Assignment 3

#include "board.h"

// Default Constructor
Board::Board(){}

// Overloaded Constructor
Board::Board(int row, int column){
    rowNum = row;
    columnNum = column;

  curr = new char*[row];
  for (int i = 0; i < row; ++i){
    curr[i] = new char[column];
  }
}

// Destructor
Board::~Board(){
    for(int i = 0; i < rowNum; ++i){
        delete [] curr[i];
    }
    delete [] curr;
}

// Purpose: Get the value of a cell at a specific index
// Parameters: row as an int, column as an int
// Returns: A char representing the value of the cell
char Board::getAt(int row, int column){
    if(row > rowNum){
        cout << "GET AT BOUNDS ERROR" << endl;
    }
    return curr[row][column];
}

// Purpose: Get the value of a cell that is north of the passed in cell
// Parameters: row as an int, column as an int
// Returns: A char representing the value of the north cell
char Board::getAtNorth(int row, int column){
    return getAt(row-1, column);
}

// Purpose: Get the value of a cell that is northeast of the passed in cell
// Parameters: row as an int, column as an int
// Returns: A char representing the value of the northeast cell
char Board::getAtNorthEast(int row, int column){
    return getAt(row-1, column+1);
}

// Purpose: Get the value of a cell that is east of the passed in cell
// Parameters: row as an int, column as an int
// Returns: A char representing the value of the east cell
char Board::getAtEast(int row, int column){
    return getAt(row, column+1);
}

// Purpose: Get the value of a cell that is southeast of the passed in cell
// Parameters: row as an int, column as an int
// Returns: A char representing the value of the southeast cell
char Board::getAtSouthEast(int row, int column){
    return getAt(row+1, column+1);
}

// Purpose: Get the value of a cell that is south of the passed in cell
// Parameters: row as an int, column as an int
// Returns: A char representing the value of the south cell
char Board::getAtSouth(int row, int column){
    return getAt(row+1, column);
}

// Purpose: Get the value of a cell that is west of the passed in cell
// Parameters: row as an int, column as an int
// Returns: A char representing the value of the west cell
char Board::getAtWest(int row, int column){
    return getAt(row, column-1);
}

// Purpose: Get the value of a cell that is northwest of the passed in cell
// Parameters: row as an int, column as an int
// Returns: A char representing the value of the northwest cell
char Board::getAtNorthWest(int row, int column){
    return getAt(row-1, column-1);
}

// Purpose: Get the value of a cell that is southwest of the passed in cell
// Parameters: row as an int, column as an int
// Returns: A char representing the value of the southwest cell
char Board::getAtSouthWest(int row, int column){
    return getAt(row+1, column-1);
}

// Purpose: Copies another board into the current board instance
// Parameters: *b as a pointer to the board b
// Returns: void
void Board::copyBoard(Board *b){
    for(int i = 0; i< rowNum ; ++i){
            for(int j = 0; j< columnNum; ++j){
              curr[i][j] = b->getAt(i, j);
            }
          }
}

// Purpose: Clears the current board instance
// Parameters: none
// Returns: void
void Board::clear(){
    for(int i = 0; i< rowNum ; ++i){
      for(int j = 0; j< columnNum; ++j){
        curr[i][j] = '\0';
      }
    }
}

// Purpose: Compares another board to the current board instance
// Parameters: *b as a pointer to board b
// Returns: A bool representing whether two boards are equal
bool Board::compare(Board *b){
  for(int i = 0; i< rowNum ; ++i){
    for(int j = 0; j< columnNum; ++j){
      if(curr[i][j] != b->getAt(i,j)){
        return false;
      }
    }
  }
  return true;
}

// Purpose: Set the value of the specific cell
// Parameters: row as an int, column as an int, c as a char
// Returns: void
void Board::setAt(int row, int column, char c){
    curr[row][column] = c;
}

// Purpose: Prints the current board instance
// Parameters: none
// Returns: void
void Board::print(){
  for(int i = 0; i< rowNum ; ++i){
    for(int j = 0; j< columnNum; ++j){
      cout << curr[i][j];
    }
    cout << endl;
  }
}

// Purpose: Prints the board instance to a file
// Parameters: *pfile as file stream, generation as an int
// Returns: void
void Board::printToFile(std::ofstream *pfile, int generation){
    //parameter 1 is ofstrem
    //append
    
    *pfile << "Generation: " << generation << endl;

  for(int i = 0; i< rowNum ; ++i){
    for(int j = 0; j< columnNum; ++j){
      *pfile << curr[i][j];
    }
    *pfile << endl;
  }
}

// Purpose: Checks whether the current board instance is empty
// Parameters: non
// Returns: A bool representing whether the board is empty
bool Board::isEmpty(){

    for(int i = 0; i< rowNum ; ++i){
      for(int j = 0; j< columnNum; ++j){
        if(curr[i][j] != '-'){
                return false;
            }
      }
    }
    return true;
}

// Purpose: Get the value of the number of rows
// Parameters: none
// Returns: An unsigned int representing the number of rows
unsigned int Board::getRow(){
    return rowNum;
}

// Purpose: Get the value of the number of columns
// Parameters: none
// Returns: An unsigned int representing the number of columns
unsigned int Board::getColumn(){
    return columnNum;
}
