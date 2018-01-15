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
  bool solve(vector<Piece*> pieces, int num_elements);
public:
  Solver(string filename);
  ~Solver();
  bool solve();
  void print_solved();
};
