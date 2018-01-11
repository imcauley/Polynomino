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

void test_init()
{
  Solver solve = Solver("./input/2.txt");
}

void test_two_cubes()
{
  Solver solve = Solver("./input/3.txt");
  TEST_CHECK(solve.solve() == true);
}

TEST_LIST = {
  {"init", test_init},
  {"2 cubes", test_two_cubes}
};
