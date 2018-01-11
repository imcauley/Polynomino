/*
Isaac McAuley
January 2018
Solver.cpp
*/

#include "../headers/Solver.h"
#include <fstream>
#include <iostream>

Solver::Solver(string filename)
{
  ifstream inFile;

  int rows = 0;
  int cols = 0;

  int block_x;
  int block_y;
  int piece_size;
  char piece_name = 'Z';

  inFile.open(filename);

  if(inFile)
  {
    inFile >> rows >> cols >> start_num;
    board = new Board(rows, cols, start_num);

    for(int i = 0; i < start_num; i++)
    {
      inFile >> piece_size;

      Piece* new_piece = new Piece(piece_name, piece_size);

      for(int j = 0; j < piece_size; j++)
      {
        inFile >> block_x;
        inFile >> block_y;

        new_piece->add_block(block_x, block_y);
      }

      start_pieces.push_back(new_piece);
      piece_name--;
    }
  }
  return;
}

void Solver::print_solved()
{
  board->print_board();
  cout << start_pieces.size();
}

bool Solver::solve()
{
  bool solved = solve(start_pieces, start_pieces.size());
  board->print_board();
  return solved;

}

bool Solver::solve(vector<Piece*> pieces, int num_elements)
{
  Piece* current;
  if(num_elements == 0)
  {
    return true;
  }
  else
  {
    for(int r = 0; r < board->get_rows(); r++)
    {
      for(int c = 0; c < board->get_cols(); c++)
      {
        for(int p = 0; p < pieces.size(); p++)
        {
          current = pieces[p];
          if(board->place_piece(current, r, c))
          {
            pieces.erase(pieces.begin() + p);
            bool solved = solve(pieces, num_elements--);
            if(solved)
            {
              return true;
            }
            else
            {
              pieces.push_back(current);
              board->delete_piece(current);
            }
          }

        }
      }
    }
  }

  return false;
}
