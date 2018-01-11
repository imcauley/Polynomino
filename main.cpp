/*
Isaac McAuley
January 2018
main.cpp

Implentation Details:
The program works with a brute force algorithm. The board is saved as a board object that peice objects can be placed onto.

A solution is found by attempting to place each piece onto each index of the board.

The program attemps to put the zero index (top left) on every index of the board. Every piece can be rotated, or flipped (mirrored) so each nonsymmetrical piece can be placed 8 different ways.

The program is implemented recrusively with a "tree strcuture" ie. Each piece placement on each node is a node and the leaves are base cases.
Base Cases:
  All peices fit on board: return true
  Placement error: return false
  All peices to fit in a spot return false: false
Recursive Case:
  Piece fits: move onto next indicie

*/

//#include "./headers/Board.h"
//#include "./headers/Piece.h"
#include "./headers/Solver.h"
#include <iostream>
#include <fstream>
using namespace std;

Board* read_file(vector<Piece*>* peices);

int main()
{
  vector<Piece*>* pieces = new vector<Piece*>();
  Board* main_board = read_file(pieces);


  return 0;
}


Board* read_file(vector<Piece*>* pieces)
{
  ifstream inFile;

  int rows = 0;
  int cols = 0;
  int num_elements = 0;

  int block_x;
  int block_y;
  int piece_size;
  char piece_name = 'Z';

  inFile.open("test_file.txt");

  if(inFile)
  {
    inFile >> rows >> cols >> num_elements;
    cout << rows << cols << num_elements << endl;
  }

  Board* board = new Board(rows, cols, num_elements);

  for(int i = 0; i < num_elements; i++)
  {
    inFile >> piece_size;

    Piece* new_piece = new Piece(piece_name, piece_size);

    for(int j = 0; j < piece_size; j++)
    {
      inFile >> block_x;
      inFile >> block_y;

      new_piece->add_block(block_x, block_y);
    }

    pieces->push_back(new_piece);

    piece_name--;
  }
    return board;
}
