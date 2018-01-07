#include <vector>
using namespace std;
#include "Piece.h"

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
  bool place_piece(Piece::Piece* piece, int x, int y);
  void delete_piece(Piece* piece);
};
