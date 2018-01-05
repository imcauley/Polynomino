#include "Block.h"
#include <vector>

using namespace std;

class Piece
{
private:
  char name;
  int size;

  int width;
  int length;
  vector<Block*> blocks;
  vector<vector<bool> > matrix;
public:
  Piece(char name, int size);
  char get_name();

  void add_block(int x, int y);

  void print_peice();
};
