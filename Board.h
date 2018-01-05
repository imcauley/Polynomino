#include <vector>
using namespace std;

class Board
{
private:
  int num_rows;
  int num_cols;
  int num_elements;
public:
  vector <char> board;

  void resize(int rows, int cols);

  char find(int row, int col);
  void put(int row, int col, char value);

};
