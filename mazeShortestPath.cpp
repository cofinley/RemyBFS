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
	direction dir;
	Position theStart, theExit;

	// fill in the remaining code
	current, theStart = X.getStart();
	theExit = X.getExit();

	Q.push(theStart);

	while (!Q.empty())
	{
		current = Q.front(); // ??? "serve an element from the queue into current"

		// iterate over possible neighbor directions
		for (dir = DOWN; next_direction(dir) != NONE; dir = next_direction(dir))
		{
			cout << "Direction: " << dir << endl;
			if (X.isOpen(current.Neighbor(dir)))
			{
				neighbor = current.Neighbor(dir);
				// if the current position is P and Q is an open
				// neighbor of P, then at the time we visit Q and append
				// it to the queue, we set pred[Q.row][Q.col] to the Position P.
				pred[neighbor.col][neighbor.row] = current;

				if (X.isExit(neighbor))
				{
					// print path
					cout << "Exit found" << endl;
					printPredecessorPath(pred, neighbor);
				}
				else
				{
					Q.push(neighbor);
				}
			}
		}
    if (Q.empty())
		{
			cout << "No way out!" << endl;
			break;
		}
	}
}

