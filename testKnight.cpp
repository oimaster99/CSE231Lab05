/***********************************************************************
 * Source File:
 *    TEST KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the knight
 ************************************************************************/

#include "testKnight.h"
#include "pieceKnight.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      

 /*************************************
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6                     6
  * 5                     5
  * 4                     4
  * 3             p   .   3
  * 2           P         2
  * 1              (n)    1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestKnight::getMoves_end()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   knight.fWhite = true;
   knight.position.set(6, 0);
   board.board[6][0] = &knight;
   Black black(PAWN);
   board.board[4][1] = &black;
   White white(PAWN);
   board.board[5][2] = &white;
   set <Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);  // many possible moves
   assertUnit(moves.find(Move("g1e2p")) != moves.end());
   assertUnit(moves.find(Move("g1h3")) != moves.end());

   // TEARDOWN
   board.board[6][0] = nullptr; // white knight
   board.board[4][1] = nullptr; // black pawn
   board.board[5][2] = nullptr; // white pawn
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (n)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_blocked()
{
	// SETUP
	BoardEmpty board;
	Knight knight(7, 7, false /*white*/);
	knight.fWhite = true;
	knight.position.set(3, 4);
	board.board[3][4] = &knight;
	White white0(PAWN);
	board.board[2][6] = &white0;
	White white1(PAWN);
	board.board[4][6] = &white1;
	White white2(PAWN);
	board.board[1][5] = &white2;
	White white3(PAWN);
	board.board[5][5] = &white3;
	White white4(PAWN);
	board.board[1][3] = &white4;
	White white5(PAWN);
	board.board[5][3] = &white5;
	White white6(PAWN);
	board.board[2][2] = &white6;
	White white7(PAWN);
	board.board[4][2] = &white7;
	set <Move> moves;

	// EXERCISE
	knight.getMoves(moves, board);

	// VERIFY
	assertUnit(moves.size() == 0);

	// TEARDOWN
	board.board[3][4] = nullptr; // white knight
	board.board[2][6] = nullptr; // white pawns
	board.board[4][6] = nullptr;
	board.board[1][5] = nullptr;
	board.board[5][5] = nullptr;
	board.board[1][3] = nullptr;
	board.board[5][3] = nullptr;
	board.board[2][2] = nullptr;
	board.board[4][2] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (n)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_capture()
{
	assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       .   .         7
 * 6     .       .       6
 * 5        (n)          5
 * 4     .       .       4
 * 3       .   .         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_free()
{
	// Create an empty board
	BoardEmpty board;

	// Place a white knight at D4 (3,3 in 0-based indexing)
	Knight knight(Position(3, 3), true);

	// Set to store moves
	set<Move> moves;

	// Call getMoves()
	knight.getMoves(moves, board);

	// Expected valid moves (L-shaped jumps)
	set<Position> expectedMoves = {
	   {2, 5}, {4, 5}, {2, 1}, {4, 1},
	   {1, 4}, {5, 4}, {1, 2}, {5, 2}
	};

	// Check that the number of moves matches expectation
	assertUnit(moves.size() == expectedMoves.size());

	// Check each move is correct
}



/*************************************
 * GET TYPE : knight
 * Input:
 * Output: KNIGHT
 **************************************/
void TestKnight::getType()
{
   // SETUP  
   const Knight knight(7, 7, false /*white*/);
   PieceType pt = SPACE;

   // EXERCISE
   pt = knight.getType();

   // VERIFY
   assertUnit(pt == KNIGHT);
}  // TEARDOWN
