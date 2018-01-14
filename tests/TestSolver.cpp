/*
Isaac McAuley
January 2018
TestSolver.cpp
*/

#include "acutest.h"
#include "../headers/Solver.h"
#include <iostream>
#include <vector>


void test_init(void);
void test_two_cubes();
void test_longs();
void test_rotate();
void test_back_track();
void test_full();
void test_equals();

void test_init()
{
  Solver solve = Solver("./input/2.txt");
  TEST_CHECK(solve.solve() == true);

}

void test_two_cubes()
{
  Solver solve = Solver("./input/3.txt");
  TEST_CHECK(solve.solve() == true);
}

void test_longs()
{
  Solver solve = Solver("./input/4.txt");
  TEST_CHECK(solve.solve() == true);
}

void test_rotate()
{
  Solver solve = Solver("./input/5.txt");
  TEST_CHECK(solve.solve() == true);
}

void test_back_track()
{
  Solver solve = Solver("./input/6.txt");
  TEST_CHECK(solve.solve() == true);
}

void test_full()
{
  Solver solve = Solver("./input/8.txt");
  TEST_CHECK(solve.solve() == true);
}

void test_equals()
{
  Piece* piece1 = new Piece('A', 4);
  Piece* piece2 = new Piece('B', 4);

  piece1->add_block(1,0);
  piece1->add_block(0,1);
  piece1->add_block(1,1);
  piece1->add_block(2,1);

  piece2->add_block(1,0);
  piece2->add_block(0,1);
  piece2->add_block(1,1);
  piece2->add_block(2,1);

  TEST_CHECK(piece1->isEqualTo(piece2) == true);
}

TEST_LIST = {
  {"init", test_init},
  {"2 cubes", test_two_cubes},
  {"test I's", test_longs},
  {"rotate I", test_rotate},
  {"backtrack", test_back_track},
  {"full", test_full}
};
