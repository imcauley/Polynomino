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
public:
  Piece(char name, int size);
  ~Piece();
  void add_block(int x, int y);

  char get_name();
  vector<Block*> get_piece();
  void get_set(vector<Piece*>* set);

  Piece* rotate_piece();
  Piece* reflect_piece();
  bool isEqualTo(Piece* that);
};
