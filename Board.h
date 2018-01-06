#include <vector>
using namespace std;

class Board
{
private:
  int num_rows;
  int num_cols;
  int num_elements;
public:
  Board(int rows, int cols, int elements);
  vector <char> board;
  char find(int row, int col);
  void put(int row, int col, char value);
  void print_board();
};
