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

/*
rotate(Piece* piece)

Parameters and Return:
  Put in a peice pointer and get back a new piece that is rotated 90 (deg)

Details:
  Works using a linear transformation.
  Each block's coordinates are multiplied by this matrix:
  [0  -1]   ==   [cos(90)  -sin(90)]
  [1   0]        [sin(90)   cos(90)]

  This rotates the piece but also puts the x coordinates into the second quadrent so the piece must be shifted.

  So the coordinates are added with this vector:
  [ piece.height ]
  [      0       ]

  Because the new width is the height and it needs to be moved over one piece width.
*/
Piece* Piece::rotate_piece()
{
  Piece* rotated = new Piece(get_name(),0);
  int x_prime;
  int y_prime;

  for(int i = 0; i < get_piece().size(); i++)
  {
    x_prime = get_piece()[i]->get_y();
    x_prime *= (-1);
    x_prime += length - 1;

    y_prime = get_piece()[i]->get_x();

    rotated->add_block(x_prime, y_prime);
  }

  return rotated;
}
