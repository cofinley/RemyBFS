#include <iostream>
#include "Position.h"
#include "Maze.h"
#include "mazeShortestPath.h"

using namespace std;

int main(int argc, char *argv[])
{
  int maze_size, dimension;
    
  if (argc == 1) {
    Maze RatHaus(false); // no prompts
    RatHaus.display();
    cout << "\n";
    printShortestPath(RatHaus);

  } else {
    cout << "Welcome to the Rat in the Maze program, where we will find a\n"
	 << "path from the start cell to the end cell of a maze so that Remy\n"
	 << "may escape.  You will first enter the data specifying the maze.\n"
	 << "After that, if escape is possible, we show an escape path using\n"
	 << " DFS and then a shortest possible path\n" << endl;
    Maze RatHaus(true);
    RatHaus.display();
    cout << "\n";
    printShortestPath(RatHaus);
  }
  cout << "\n\n";

  return 0;
}
