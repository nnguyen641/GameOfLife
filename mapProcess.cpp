// Nathan Nguyen
// 2370739
// nnguyen1@chapman.edu
// CPSC350 - 01
// Assignment 3

#include "mapProcess.h"

// Default Constructor
mapProcess::mapProcess(){
    m_choice = '\0';
    m_mapFile = "";
    m_row = 0;
    m_col = 0;
    m_density = 0.0;
    
}

// Overloaded Constructor
mapProcess::mapProcess(string inputFile){
    m_mapFile = inputFile;
}

// destructor
mapProcess::~mapProcess(){
    // intentionally left blank
}


// Purpose: Reads a file from the filename
// Parameters: input as a string
// Returns: An board representing the board of that file
Board * mapProcess::readFile(string input){
  //creates an input stream to read from a file
  std::ifstream myfileIN;

  //string where the line from the file is put
  std::string line;
  std::istringstream iss; // string stream used for parsing line

  int numRow;
  int numColumns;
  Board *b;

  //opens the input file for reading
  myfileIN.open(input, ios::in);
  // checks if there is a fail opening the file --> bad input
  if(myfileIN.fail()){
    cout << "bad file input" << endl;
    exit(-1);
  }

  //checks if the input and output file is open
  if (myfileIN.is_open()){
      // get number of rows
      std::getline(myfileIN, line, '\n');
      iss.str(line);
      if (!(iss >> numRow)) {
      cout<< "expected number of rows" << endl; return (Board *)nullptr;
    }

      // get number of columns
      std::getline(myfileIN, line, '\n');
      cout << line << endl; // for testing purposes only  - remove when done
      std::istringstream iss(line);
      if (!(iss >> numColumns)) {
      cout << "expected number of columns" << endl; return (Board *)nullptr;
    }

      // construct new board
      b = new Board(numRow, numColumns);

      // Begin reading stream here
      //for loop to go through each line of the file

      for(int i = 0; i < numRow ; ++i){
        std::getline(myfileIN, line, '\n'); // this line contains all the char in a row
        for(int j = 0; j< numColumns; ++j){
          b->setAt(i,j, line[j]);
        }
      }

      //closes  files after done using them
      myfileIN.close();
  } else {
    cout << "Problem opening file" << endl;
      exit(1);
  }

  return b;

}

// Purpose: Makes a randomized map given number of rows, columns, and population density
// Parameters: row as an int, column as an int, density as a double
// Returns: An board representing a randomized board
Board * mapProcess::makeMap(int row, int col, double density){
  srand(time(NULL));
    
  Board *b = new Board(row, col);

  double pop = ((double)row*(double)col*density);
  int population = (int)pop;
  int randomRow;
  int randomColumn;

    for (int ii=0; ii< row; ii++){
      for (int jj=0; jj< col; jj++){
        b->setAt(ii, jj, '-');
      }
    }

    for(int i=0 ; i < population; ++i){
      randomRow = rand() % row;
      randomColumn = rand() % col;
      if(b->getAt(randomRow, randomColumn) == '-'){
        b->setAt(randomRow, randomColumn, 'X');
      }else{
        --i;
      }
    }

    return b;
}

