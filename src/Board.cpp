/*
Isaac McAuley
January 2018
Board.cpp
*/

#include "../headers/Board.h"
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
  cout << endl;
  for(int i = 0; i < num_rows; i++)
  {
    for(int j = 0; j < num_cols; j++)
    {
      cout << find(i, j);
    }
    cout << endl;
  }
  cout << endl;
}

int Board::get_rows()
{
  return num_rows;
}
int Board::get_cols()
{
  return num_cols;
}


/*
place_piece(Piece* piece, int x, int y)

Takes in a piece pointer and coordinates and attempts to place piece on that coordinate.

If the function cannot place the piece it will return False and not place any of the blocks on the board.

*/
bool Board::place_piece(Piece* piece, int x, int y)
{
  bool can_place = true;
  int curr_x;
  int curr_y;
  char letter = piece->get_name();


  for(unsigned int i = 0; i < piece->get_piece().size() && can_place; i++)
  {
    curr_x = (piece->get_piece()[i])->get_x() + x;
    curr_y = (piece->get_piece()[i])->get_y() + y;

    if(curr_x < 0 || curr_x >= num_rows ||
       curr_y < 0 || curr_y >= num_cols ||
       find(curr_x, curr_y) != '#')
    {
      can_place = false;
    }

  }

  if(can_place)
  {
    for(unsigned int i = 0; i < piece->get_piece().size(); i++)
    {
      curr_x = (piece->get_piece()[i])->get_x() + x;
      curr_y = (piece->get_piece()[i])->get_y() + y;
      put(curr_x, curr_y, letter);
    }
  }
  return can_place;
}

/*
Used for the backtracking part of the alogirthm
*/
void Board::delete_piece(Piece* piece)
{
  char letter = piece->get_name();

  for(int i = 0; i < num_rows; i++)
  {
    for(int j = 0; j < num_cols; j++)
    {
      if(find(i, j) == letter) put(i, j, '#');
    }
  }
}
