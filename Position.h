//---------- Position.h ----------------//
// Position class -
// represents a position within a grid  //
#ifndef __POSITION
#define __POSITION
#include <iostream>
#include <vector>

using namespace std;

typedef enum{DOWN, LEFT, UP, RIGHT, NONE} direction;

direction next_direction(direction d);

class Position { // could be a struct since all attributes are public
  public:
   int row; // row index
   int col; // column index

   Position():row(0),col(0) {};
   Position(int r, int c):row(r),col(c) {};

   void input(istream &in); // expects two ints separated by whitespace

   Position Neighbor(direction d) const; // returns the neighbor in direction d

   bool operator==(const Position &other) const;

   void display(ostream &out) const; // outputs (row,col)


};

ostream & operator<<(ostream &out,const Position &P);

istream & operator>>(istream &in, Position &P);

const Position NULLPOS(-1,-1);

typedef vector<vector<Position> > PosTable;

#endif
