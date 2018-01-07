#include "../headers/Block.h"

Block::Block(int x, int y)
{
  this->x = x;
  this->y = y;
}

int Block::get_x()
{
  return x;
}

int Block::get_y()
{
  return y;
}
