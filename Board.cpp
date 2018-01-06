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
