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
  blocks.resize(size);
}

void Piece::add_block(int x, int y)
{
  Block* new_block = new Block(x, y);
  blocks.push_back(new_block);

  if(x + 1 > width)
  {
    width = x + 1;
  }
  if(y + 1 > length)
  {
    length = y + 1;
  }


  return;
}

vector<vector<char>>* Piece::get_piece()
{
    vector<vector<char>> matrix = new vector(width);
    return &matrix;
}

char Piece::get_name()
{
  return name;
}

void Piece::print_peice()
{

}
