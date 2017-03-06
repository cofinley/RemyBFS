#include "mazeShortestPath.h"
#include <queue>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <stack>

using namespace std;

void printPredecessorPath(PosTable pred, Position target)
{
  if (target == NULLPOS)
    return;
  printPredecessorPath(pred, pred[target.row][target.col]);
  cout << target << " ";
}

void printShortestPath(Maze &X)
{
   queue<Position> Q; // positions queue

	 int msize = X.getSize();
   vector< vector<Position> > pred(msize, vector<Position>(msize, NULLPOS)); // previous (predecessor) position
   
	 Position current, neighbor;
   direction d;
   int mazesize;
   Position theStart, theExit;

   // fill in the remaining code


   
}

