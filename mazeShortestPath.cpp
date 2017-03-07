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
	// Initialize previous (predecessor) position 2D array
	vector< vector<Position> > pred(msize, vector<Position>(msize, NULLPOS)); 

	Position current, neighbor;
	direction dir;
	Position theStart, theExit;

	// fill in the remaining code
	theStart = X.getStart();
	theExit = X.getExit();

	// mark start as visited, push onto queue
	X.visit(theStart);
	Q.push(theStart);

	// book-keeping bool for final break of loop
	bool isFinished = false;

	while (!Q.empty())
	{
		// serve an element from the queue into current
		current = Q.front(); 
		Q.pop();

		// Iterate over all possible neighbor directions
		for (dir = DOWN; dir != NONE; dir = next_direction(dir))
		{
			if (X.isOpen(current.Neighbor(dir)))
			{
				// If neighbor hasn't been visited, visit it
				neighbor = current.Neighbor(dir);
				X.visit(neighbor);
				// if the current position is P and Q is an open
				// neighbor of P, then at the time we visit Q and append
				// it to the queue, we set pred[Q.row][Q.col] to the Position P.
				pred[neighbor.row][neighbor.col] = current;

				if (X.isExit(neighbor))
				{
					// Exit found, print path
					printPredecessorPath(pred, neighbor);
					// Mark book-keeping bool, used in final if statement below
					isFinished = true;
					break;
				}
				else
				{
					// Exit not found, just enqueue the neighbor for later use
					Q.push(neighbor);
				}
			}
		}
	}
	if (Q.empty() && !isFinished)
		// No exit found, queue eventually ran out
		// Book-keeping bool used to make sure this is only called when appropriate
		// (queue runs out either way)
		cout << "No way out!" << endl;
}

