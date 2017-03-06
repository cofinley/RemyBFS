#ifndef __MAZE
#define __MAZE

#include <iostream>
#include <fstream>
#include <string>
#include "Position.h"
#include <queue>
// Note the use of the STL queue ADT
// Be aware that it uses push instead of enqueue
// and pop instead of dequeue; front is the same as our Queue classes
// We will only consider square mazes

using namespace std;

typedef enum{OPEN,WALL,VISITED} state;


typedef vector<vector<state> > stateTable;

class Maze
{
  public:
   //start <- s, exit <- e, size <- n
   Maze(int max, Position s, Position e);
   Maze(bool verbose); // input data from cin

   int getSize();
   Position getStart();
   Position getExit();
   bool isStart(Position P);
   bool isExit(Position P);
   state getState(Position P);
   bool isOpen(Position P);
   void visit(Position P);
   void display() const;
   
  private:
   int size;
   Position start;
   Position exitpos;

   stateTable M;
};


#endif
