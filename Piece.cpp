/*
Isaac McAuley
January 2018
Piece.cpp

A piece is a group of blocks within a 2D matrix.

Use of a piece:
  instantiate it with it's blocks, letter ID (name), and number of blocks.

  get a representation of the piece where it tells the board where new blocks need to go.
*/

#include "Piece.h"
#include <iostream>
using namespace std;

/*
Inputs:
  name: a character that the peice will be represented by
  size: the number of blocks in the peice
  blocks: a vector of blocks decribing the blocks that make up the piece
*/
Piece::Piece(char name, int size)
{
  this->name = name;
  this->size = size;

  width = length = 1;
  blocks.resize(0);
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

vector<Block*> Piece::get_piece()
{
    return blocks;
}

char Piece::get_name()
{
  return name;
}

void Piece::print_peice()
{

}
