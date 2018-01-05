#include "acutest.h"
#include "Piece.h"
#include <iostream>
#include <vector>

void test_init(void);

void test_init(void)
{
  Piece new_piece = Piece('A', 5);
  TEST_CHECK(new_piece.get_name() == 'A');
  return;
}

void test_blocks(void)
{
  char expected [2][2] = {{'A','\0'},{'A','\0'}};

  Piece new_piece = Piece('A', 5);
  new_piece.add_block(0, 0);
  new_piece.add_block(0, 1);

  TEST_CHECK(new_piece.get_piece() == expected);
  return;
}

TEST_LIST = {
  {"init", test_init}
};
