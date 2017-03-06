#include <cassert>
#include <cstdlib>
#include "Maze.h"

Maze::Maze(int max, Position st, Position ex)
  : start(st), exitpos(ex), size(max)
{
  assert(0 < st.row && st.row < size-1 && 0 < ex.row && ex.row < size-1);
  M.reserve(size);
  for (int i = 0; i < size; i++) {
    M[i].reserve(max);
    for (int j = 0; j < size; ++j)
      M[i][j] = WALL;
  }
}

Maze::Maze(bool verbose = false)
// verbose == true means an intro and prompts for input will be printed
{
  int i, j, dimension;
  
  if (verbose) {
    cout << "Welcome to the Rat in the Maze program, where we will find a\n"
	 << "path from the start cell to the end cell of a maze so that Remy\n"
	 << "may escape.  You will first enter the data specifying the maze.\n"
	 << "After that, if escape is possible, we will show an escape path\n"

         << "Enter the number of rows and columns of the maze: " << endl;
  }   
  cin >> dimension;
  size = dimension+2; // add the hedge rows and columns
  if (verbose)
    cout << "Enter the row and column indices of the start: " << endl;
  cin >> start;
  if (verbose)
    cout << "Enter the row and column indices of the exit: " << endl;
  cin >> exitpos;

  M.reserve(size);
  for (i = 0; i < size; i++) {
    M[i].reserve(size);
    for (j = 0; j < size; ++j)
      M[i][j] = WALL;
  }

  if(verbose) {
    cout << "For each row, enter the column indices of the open squares\n";
    cout << "Terminate the row input with a non-positive value" << endl;
  }
  for (i = 1; i <= size-2; i++) {
    if (verbose)
      cout << "Row " << i << ": ";  
    cin >> j;
    assert(j < 1 || 1 <= j && j <= size-2);
    
    while (j > 0){
      M[i][j] = OPEN;
      cin >> j;
      assert(j < 1 || 1 <= j && j <= size-2);
    };
  }
  
  if (!(M[start.row][start.col] == OPEN)) 
    M[start.row][start.col] = OPEN;
}

void Maze::display() const
{
  cout << '\n';
  for (int i=0; i < size;i++) {
    for (int j=0; j < size; j++) {
      if (Position(i,j) == start && start == exitpos)
	cout << 'b'; // for both
      else if (Position(i,j) == start)
	cout << 's';
      else if (Position(i,j) == exitpos)
	cout << 'e';
      else if (M[i][j] == WALL)
	cout << '*';
      else
	cout << '-';
    }
    cout << '\n';
  }
  cout << '\n';
}


Position Maze::getStart() {return start;}

Position Maze::getExit() {return exitpos;}

int  Maze::getSize() {return size;}

state  Maze::getState(Position P) {return M[P.row][P.col];}

bool  Maze::isOpen(Position P) {return OPEN == getState(P);}

void  Maze::visit(Position P)
{
  if (!(0 < P.row && P.row < size-1 && 0 < P.col && P.col < size-1)) {
    cout << "Invalid Position from visit method: " << P << endl;
    exit(1);
  }
  
  M[P.row][P.col] = VISITED;
}

bool  Maze::isStart(Position P) {return P == start;}

bool  Maze::isExit(Position P) {return P == exitpos;}
