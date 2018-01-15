/*
Isaac McAuley
January 2018
Solver.cpp
*/

#include "../headers/Solver.h"
#include <vector>
#include <fstream>
#include <iostream>

Solver::Solver(const string filename)
{
  ifstream inFile;

  int rows = 0;
  int cols = 0;

  int block_x;
  int block_y;
  int piece_size;
  char piece_name = 'A';

  inFile.open(filename.c_str());

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
      piece_name++;
    }
  }
  return;
}

Solver::~Solver()
{
  for(unsigned int i = 0; i < start_pieces.size(); i++)
  {
    delete start_pieces[i];
  }
  delete board;
}

void Solver::print_solved()
{
  cout << endl;
  board->print_board();
  cout << endl;
}

bool Solver::solve()
{
  bool solved = solve(start_pieces, start_pieces.size());
  return solved;

}

bool Solver::solve(vector<Piece*> pieces, int num_elements)
{
  Piece* current;
  Piece* set_current;

  bool solved = false;

  if(num_elements == 0)
  {
    return true;
  }
  else
  {
    for(unsigned int p = 0; p < pieces.size(); p++)
    {
      current = pieces[p];
      pieces.erase(pieces.begin() + p);
      vector<Piece*>* set = new std::vector<Piece*>();

      current->get_set(set);
      for(unsigned int n = 0; n < set->size(); n++)
      {
        set_current = (*set)[n];

        for(int x = 0; x < board->get_rows(); x++)
        {
          for(int y = 0; y < board->get_cols(); y++)
          {
            if(board->place_piece(set_current, x, y))
            {
              solved = solve(pieces, num_elements - 1);
              if(solved)
              {
                delete set;
                return true;
              }
              else
              {
                board->delete_piece(set_current);
              }
            }
          }
        }

      }
      delete set;
      pieces.insert(pieces.begin() + p, current);
    }

    //pieces.erase(pieces.begin() + 0);
    //return solve(pieces, pieces.size());
  }
  return false;
}
