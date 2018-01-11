PolySolver: clean Piece.o Block.o Board.o Solver.o
	g++ -Wall -o PolySolver ./main.cpp Piece.o Block.o Board.o Solver.o

TestSolver: clean Piece.o Block.o Board.o Solver.o
	g++ -Wall -g -o TestSolver ./tests/TestSolver.cpp Piece.o Block.o Board.o Solver.o -Wall
	./TestSolver

TestPiece: clean Piece.o Block.o Board.o
	g++ -Wall -o TestPiece ./tests/TestPiece.cpp Piece.o Block.o Board.o -Wall
	./TestPiece

clean:
	-rm ./PolySolver
	-rm ./TestPiece
	-rm *.o

Solver.o: Board.o
	g++ -g -Wall -c ./src/Solver.cpp Board.o

Board.o: Piece.o
	g++ -Wall -c ./src/Board.cpp Piece.o

Piece.o: Block.o
	g++ -Wall -c ./src/Piece.cpp Block.o

Block.o:
	g++ -Wall -c ./src/Block.cpp
