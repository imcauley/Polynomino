/*
Author: Isaac McAuley
Date: Jan 5 2018
File: Piece.cpp
*/

#include "Piece.h"
#include <iostream>
using namespace std;

Piece::Piece(char name, int size)
{
  this->name = name;
  this->size = size;

  width = length = 1;
  matrix.resize(1);
  matrix[0].resize(1);
  blocks.resize(size);
}

void Piece::add_block(int x, int y)
{
  Block* new_block = new Block(x, y);
  blocks.push_back(new_block);

  if(x + 1 > width)
  {
    width = x + 1;
    matrix.resize(width);
  }
  if(y + 1 > length)
  {
    length = y + 1;
    for(int i = 0; i < width; i++)
    {
      matrix[i].resize(length);
    }
  }

  matrix[x][y] = true;

  return;
}
char Piece::get_name()
{
  return name;
}

void Piece::print_peice()
{
  std::cout << width << ' ' << length << '\n';
  for(int i  = 0; i < width; i++)
  {
    for(int j = 0; j < length; j++)
    {
      if(matrix[i][j])
      {
        cout << 'A';
      }
      else
      {
        cout << ' ';
      }
    }
    cout << endl;
  }
}
