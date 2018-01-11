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

void test_init()
{
  Solver solve = Solver("./input/2.txt");
  solve.print_solved();
}

TEST_LIST = {
  {"init", test_init}
};
