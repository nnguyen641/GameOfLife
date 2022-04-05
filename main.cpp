// Nathan Nguyen
// 2370739
// nnguyen1@chapman.edu
// CPSC350 - 01
// Assignment 3

#include <iostream>
#include "game.h"
#include "mode.h"
#include "mapProcess.h"
#include <unistd.h>

using namespace std;

int main(int argc, const char * argv[]) {
    Board *b;
    Board *next;
    Board *prev;
    game *g = new game();

    char userChoice;
    char modeChoice;
    char betweenChoice;
    bool run = true;
    bool gameRun = true;
    unsigned int numRow = 0;
    unsigned int numColumns = 0;
    double popDensity = 0.0;
    string fileName;
    string outputFile;
    mapProcess *mp = new mapProcess();
    string enter;
    std::ofstream fileOut;
    string str;
    
    cout << "Welcome to the Game of Life" << endl;
    cout << "Would you like to provide a map file or do random assignment (M/R): " << endl;
    cin >> userChoice;

    while(run){

      if(userChoice == 'R'){
        cout << "You choose Random Assignment" << endl;
        cout << "enter the number of rows: " << endl;
        cin >> numRow;
        cout << "enter the number of columns: " << endl;
        cin >> numColumns;
        cout << "enter the population density (0.0-1.0): " << endl;
        cin >> popDensity;
        if(popDensity > 1.0){
          cout << "try again! enter the population density" << endl;
          cin >> popDensity;
        } else if (popDensity < 0.0){
          cout << "try again! enter the population density" << endl;
          cin >> popDensity;
        }
        cout << "Generation 0" << endl;
        //call map process
        b = new Board(numRow, numColumns);
        b = mp->makeMap(numRow, numColumns, popDensity); //creates a random map
        next = new Board(numRow, numColumns);
        next->copyBoard(b);
        prev = new Board(b->getRow(), b->getColumn());
        prev->copyBoard(b);
        b->print();

        //run simulation

        run = false;

      }else if (userChoice == 'M'){
        cout << "You choose Map File" << endl;
        cout << "Enter the file name: " << endl;
        cin >> fileName;

  //read file with MapProcess
        b = new Board();
        b = mp->readFile(fileName);
        b->print();
        next = new Board(b->getRow(), b->getColumn());
        next->copyBoard(b);
        prev = new Board(b->getRow(), b->getColumn());
        prev->copyBoard(b);
        run = false;
        
      }else {
        //incorrect input
        cout << "You entered the wrong character. try again" << endl;
        cin >> userChoice;
      }
    }

    //check for boundarymode (three if statements)
    modeChoice = ' ';
    while ((modeChoice != 'C') && (modeChoice != 'M') &&  (modeChoice != 'D') ) {
      cout << "Which Boundary mode do you want to use? Classic(C), Mirror(M), or Donut(D)" << endl;
      cin >> modeChoice;

      if ((modeChoice != 'C') && (modeChoice != 'M') &&  (modeChoice != 'D') ){
        cout << "You entered the wrong character. try again" << endl;
      }
    }
    
    //ask if they want a...
      //brief pause between generations
      //want to have to press enter key to display next generation (print to console)
      //want to output everything to a file
        //prompt for an output file

    betweenChoice = ' ';
    while ((betweenChoice != 'P') && (betweenChoice != 'E') &&  (betweenChoice != 'O') ) {
      cout << "Between each generation would you like a brief pause (P)" << endl;
      cout << "OR would you like to press the enter key to display the next generation (E)" << endl;
      cout << "OR would you like to write out all generations to an output file (O)" << endl;
      cin >> betweenChoice;

      if ((betweenChoice != 'P') && (betweenChoice != 'E') &&  (betweenChoice != 'O') ){
        cout << "You entered the wrong character. try again" << endl;
        cin >> betweenChoice;
      }
    }
    
    if(betweenChoice == 'O'){
      cout << "Please enter an output file name" << endl;
      cin >> outputFile;

      fileOut.open(outputFile, ios::out | ios::trunc);
      // checks if there is a fail opening the file
      if(fileOut.fail()){
        cout << "Bad file input" << endl;
        exit(-1);
      }
      b->printToFile(&fileOut, 1);
        
    }
    
    //run Game
      //if infinite keep running (while loop)
      //if oscillating
        //check if board is equal three times (break from loop) (game class)
          //use compare method in board, increment how many times it is equal (board)
        //stop and ask user to enter to exit (main)
      //if empty then stop and ask the user to press enter to exit (call from board, break from loop)

    int generation = 1;
    int counter = 0;
    while(gameRun){

      g->play(b, next, modeChoice); // play one round
        
        if(generation > 1 && (counter == 2)){
          prev->copyBoard(b);
        }
        
        if (b->isEmpty()){
            cout << "The board is empty. Please press enter." << endl;
            if(betweenChoice == 'P' || betweenChoice == 'O'){
                cin.ignore();
            }
            getline(cin, str);
            if(str == ""){
               gameRun = false;
               return 0;
            } else {
              cout << "Oops. Try pressing enter instead." << endl;
              getline(cin, str);
            }
        } else if ((generation > 1) && (b->compare(next) == true)) {
            cout << "The generations current and next generation are the same. Please press enter." << endl;
            if(betweenChoice == 'P' || betweenChoice == 'O'){
                cin.ignore();
            }
            getline(cin, str);
            if(str == ""){
                gameRun = false;
                return 0;
          } else {
            cout << "Oops. Try pressing enter instead." << endl;
            getline(cin, str);
          }
      } else if( (generation > 1) && prev->compare(next) == true){
           cout << "The generations are oscilating. Press enter to exit.";
          if(betweenChoice == 'P' || betweenChoice == 'O'){
              cin.ignore();
          }
           getline(cin, str);
           if(str == ""){
               gameRun = false;
               return 0;
           } else {
             cout << "Oops. Try pressing enter instead." << endl;
             getline(cin, str);
           }
        }
        
        generation++;
        counter++;
        
        b->copyBoard(next);
        cout << "Generation: " << generation << endl;
        b->print();
      
      if(betweenChoice == 'P'){
          sleep(3);
      }else if(betweenChoice == 'E'){
        //want to have to press enter key to display next generation (print to console)
          cout << "Press enter to continue:" << endl;
          if(generation == 2){
              cin.ignore();
          }
          getline(cin, str);
          if(str == ""){
              continue;
          }
      }else if(betweenChoice == 'O'){
        b->printToFile(&fileOut, generation);
      }
      
    }
    
    delete mp;
    delete b;
    delete next;
    delete g;
    return 0;
}
