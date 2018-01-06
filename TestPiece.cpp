#include "acutest.h"
#include "Piece.h"
#include <iostream>
#include <vector>

void test_init(void);
void test_one_block(void);
void test_multiple_blocks(void);

void test_init(void)
{
  Piece new_piece = Piece('A', 0);
  TEST_CHECK(new_piece.get_name() == 'A');
  return;
}

void test_one_block(void)
{
  Piece new_piece = Piece('A', 1);
  new_piece.add_block(0,0);
  TEST_CHECK(new_piece.get_piece().size() == 1);
  TEST_CHECK(new_piece.get_piece()[0]->get_x() == 0);
  TEST_CHECK(new_piece.get_piece()[0]->get_y() == 0);
}

void test_multiple_blocks(void)
{
  Piece new_piece = Piece('A', 1);
  for(int i = 0; i < 5; i++)
  {
    new_piece.add_block(0,i);
  }
  TEST_CHECK(new_piece.get_piece().size() == 5);
  TEST_CHECK(new_piece.get_piece()[4]->get_y() == 4);
}

TEST_LIST = {
  {"init", test_init},
  {"1 block", test_one_block},
  {"5 blocks", test_multiple_blocks}
};
