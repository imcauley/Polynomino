#include "Board.h"
#include <vector>
#include <iostream>

using namespace std;

Board::Board(int rows, int cols, int elements)
{
  num_cols = cols;
  num_rows = rows;
  num_elements = elements;
  board.resize(cols * rows);

  for(int i = 0; i < num_rows; i++)
  {
    for(int j = 0; j < num_cols; j++)
    {
      put(i, j, '#');
    }
  }
}

char Board::find(int row, int col)
{
  return board[(row * num_cols) + col];
}

void Board::put(int row, int col, char value)
{
  board[(row * num_cols) + col] = value;
  return;
}

void Board::print_board()
{
  for(int i = 0; i < num_rows; i++)
  {
    for(int j = 0; j < num_cols; j++)
    {
      cout << find(i, j);
    }
    cout << endl;
  }
}

bool Board::place_piece(Piece* piece, int x, int y)
{
  int curr_x;
  int curr_y;
  char letter = piece->get_name();

  for(int i = 0; i < piece->get_piece().size(); i++)
  {
    curr_x = (piece->get_piece()[i])->get_x() + x;
    curr_y = (piece->get_piece()[i])->get_y() + y;

    if(curr_x >= 0 && curr_x < num_rows)
    {
      if(curr_x >= 0 && curr_x < num_rows)
      {
        if(find(curr_x, curr_y) == '#')
        {
          put(curr_x, curr_y, letter);
        }
        else
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }

  return true;
}
