test: Piece.o Block.o Board.o
	g++ -Wall -o test ./tests/TestPiece.cpp Piece.o Block.o Board.o -Wall
	./test

clean:
	rm *.o

Board.o: Piece.o
	g++ -Wall -c ./src/Board.cpp Piece.o

Piece.o: Block.o
	g++ -Wall -c ./src/Piece.cpp Block.o

Block.o:
	g++ -Wall -c ./src/Block.cpp
