/*
Isaac McAuley
January 2018
Solver.h
*/

#include "./Board.h"
#include <vector>
#include <string>

class Solver
{
private:
  Board* board;
  vector<Piece*> start_pieces;
  int start_num;
public:
  Solver(string filename);
  void print_solved();
};
