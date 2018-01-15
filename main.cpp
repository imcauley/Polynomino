/*
Isaac McAuley
January 2018
main.cpp

Implentation Details:
The program works with a brute force algorithm. The board
  is saved as a board object that peice objects can be
  placed onto.

A solution is found by attempting to place each piece
onto each index of the board.

The program attemps to put the zero index (top left) on
  every index of the board. Every piece can be rotated,
  or flipped (mirrored) so each nonsymmetrical piece can
  be placed 8 different ways.

The program is implemented recrusively with a "tree strcuture" ie. Each piece placement on each node is a node and the leaves are base cases.
Base Case:
  There is no more pieces to place
Recursive Case:
  There is one or more pieces to place

*/

#include "./headers/Solver.h"
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
  Solver solve = Solver(argv[1]);
  if(solve.solve())
  {
    solve.print_solved();
  }
  else
  {
    cout << "No solution for this board" << endl;
  }
  return 0;
}
