#include "Board.h"
#include <vector>

using namespace std;

void Board::resize(int rows, int cols)
{
  num_cols = cols;
  num_rows = rows;
  board.resize(cols * rows);
  return;
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
