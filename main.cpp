#include "Board.h"
#include "Piece.h"
#include <iostream>
#include <fstream>
using namespace std;

void read_file();

int main()
{
  Board thing;
  thing.resize(8, 9);
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 9; j++)
    {
      thing.put(i,j,'A');
    }
  }

  thing.put(0, 6, 'B');

  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 9; j++)
    {
      cout << thing.find(i,j);
    }
    cout << endl;
  }

  read_file();
  //cout << thing.board[6 * (9) + 7] << endl;
  return 0;
}


void read_file()
{
  ifstream inFile;

  int rows;
  int cols;
  int num_elements;
  vector<Piece*> pieces;

  int block_x;
  int block_y;
  int piece_size;
  char piece_name = 'Z';

  inFile.open("test_file.txt");

  if(inFile)
  {
    inFile >> rows >> cols >> num_elements;
    cout << rows << cols << num_elements << endl;
  }

  /*
  Piece piece2 = Piece('B', 6);
  pieces.push_back(&piece2);
  cout << pieces[0]->get_name() << endl;
  */


  for(int i = 0; i < num_elements; i++)
  {
    inFile >> piece_size;

    Piece* new_piece = new Piece(piece_name, piece_size);

    for(int j = 0; j < piece_size; j++)
    {
      inFile >> block_x;
      inFile >> block_y;

      new_piece->add_block(block_x, block_y);
    }

    pieces.push_back(new_piece);

    piece_name--;
  }

    Piece test = *pieces[0];
    test.print_peice();
    return;
}
