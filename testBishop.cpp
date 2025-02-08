/***********************************************************************
 * Source File:
 *    TEST BISHOP
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for a bishop
 ************************************************************************/


#include "testBishop.h"
#include "pieceBishop.h"     
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
 * 3     p   p           3
 * 2      (b)            2
 * 1     p   p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_blocked()
{
	// SETUP
	BoardEmpty board;
	Bishop bishop(7, 7, false /*white*/);
	bishop.fWhite = true;
	bishop.position.set(2, 1);
	board.board[2][1] = &bishop;
	White white0(PAWN);
	board.board[1][0] = &white0;
	White white1(PAWN);
	board.board[1][2] = &white1;
	White white2(PAWN);
	board.board[3][0] = &white2;
	White white3(PAWN);
	board.board[3][2] = &white3;
	set <Move> moves;

	// EXERCISE
	bishop.getMoves(moves, board);

	// VERIFY
	assertUnit(moves.size() == 0);

	// TEARDOWN
	board.board[2][1] == nullptr; //white bishop
	board.board[1][0] == nullptr; //white pawns
	board.board[1][2] == nullptr;
	board.board[3][0] == nullptr;
	board.board[3][2] == nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 .   7
 * 6               .     6
 * 5             .       5
 * 4   .       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     .   .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToEnd()
{
    // SETUP
	BoardEmpty board;

	Bishop bishop(Position(2, 1), true);
	set<Move> moves;

	set<Position> expectedMoves = {
		{0, 3},
		{1, 2}, {3, 2}, {4, 3}, {5, 4}, {6, 5}, {7, 6},
		{1, 0}, {3, 0}
	};

	// EXERCISE
	bishop.getMoves(moves, board);

	// VERIFY
	assertUnit(moves.size() == expectedMoves.size());
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 p   7
 * 6               .     6
 * 5             .       5
 * 4   p       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     p   p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToBlock()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 P   7
 * 6               .     6
 * 5             .       5
 * 4   P       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     P   P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToCapture()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * GET TYPE : bishop
 * Input:
 * Output: BISHOP
 **************************************/
void TestBishop::getType()
{
   // SETUP
	const Bishop bishop(7, 7, false);
	PieceType pt = SPACE;

	// EXERCISE
	pt = bishop.getType();

	// VERIFY
	assertUnit(pt == BISHOP);
}
