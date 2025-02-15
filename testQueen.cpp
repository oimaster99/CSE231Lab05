/***********************************************************************
 * Source File:
 *    TEST QUEEN
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the queen
 ************************************************************************/

#include "testQueen.h"
#include "pieceQueen.h"     
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
 * 3     p p p           3
 * 2     p(q)p           2
 * 1     p p p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_blocked()
{
	// SETUP
	BoardEmpty board;
	Queen queen(7, 7, false);
	queen.fWhite = true;
	queen.position.set(2, 1);
	board.board[2][1] = &queen;
	White white0(PAWN);
	board.board[2][0] = &white0;
	White white1(PAWN);
	board.board[1][1] = &white1;
	White white2(PAWN);
	board.board[2][2] = &white2;
	White white3(PAWN);
	board.board[3][1] = &white3;
	White white4(PAWN);
	board.board[3][0] = &white3;
	White white5(PAWN);
	board.board[3][2] = &white3;
	White white6(PAWN);
	board.board[1][0] = &white3;
	White white7(PAWN);
	board.board[1][2] = &white3;
	set <Move> moves;

	// EXERCISE
	moves = queen.getMoves(board);

	// VERIFY
	assertUnit(moves.size() == 0);

	// TEARDOWN
	board.board[2][1] == nullptr; //white queen
	board.board[2][0] == nullptr; //white pawns
	board.board[1][1] == nullptr;
	board.board[2][2] == nullptr;
	board.board[3][1] == nullptr;
	board.board[3][0] == nullptr;
	board.board[3][2] == nullptr;
	board.board[1][0] == nullptr;
	board.board[1][2] == nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .         .   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   .   .   .         4
 * 3     . . .           3
 * 2   . .(q). . . . .   2
 * 1     . . .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToEnd()
{
	// SETUP
	BoardEmpty board;
	Queen queen(7, 7, false);
	queen.fWhite = true;
	queen.position.set(2, 1);

	set<Position> expectedMoves = {
		{2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7},
		{1, 2}, {0, 3}, {3, 2}, {4, 3}, {5, 4}, {6, 5}, {7, 6},
		{1, 1}, {0, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1},
		{1, 0}, {2, 0}, {3, 0}
	};

	set <Move> moves;

	// EXERCISE
	moves = queen.getMoves(board);

	// VERIFY
	assertUnit(moves.size() == expectedMoves.size());

	// TEARDOWN
	board.board[2][1] == nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .         p   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   p   .   .         4
 * 3     . . .           3
 * 2   p .(q). . . . p   2
 * 1     p p p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToBlock()
{
	// SETUP
	BoardEmpty board;
	Queen queen(7, 7, false);
	queen.fWhite = true;
	queen.position.set(2, 1);
	board.board[2][1] = &queen;
	White white0(PAWN);
	board.board[2][7] = &white0;
	White white1(PAWN);
	board.board[0][3] = &white1;
	White white2(PAWN);
	board.board[0][1] = &white2;
	White white3(PAWN);
	board.board[1][0] = &white3;
	White white4(PAWN);
	board.board[2][0] = &white4;
	White white5(PAWN);
	board.board[3][0] = &white5;
	White white6(PAWN);
	board.board[7][1] = &white6;
	White white7(PAWN);
	board.board[7][6] = &white7;

	set<Position> expectedMoves = {
		{2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6},
		{1, 2}, {3, 2}, {4, 3}, {5, 4}, {6, 5},
		{1, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}
	};

	set <Move> moves;

	// EXERCISE
	moves = queen.getMoves(board);

	// VERIFY
	assertUnit(moves.size() == expectedMoves.size());

	// TEARDOWN
	board.board[2][1] == nullptr; //white queen
	board.board[2][7] == nullptr; //white pawns
	board.board[0][3] == nullptr;
	board.board[0][1] == nullptr;
	board.board[1][0] == nullptr;
	board.board[2][0] == nullptr;
	board.board[3][0] == nullptr;
	board.board[7][1] == nullptr;
	board.board[7][6] == nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .         P   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   P   .   .         4
 * 3     . . .           3
 * 2   P .(q). . . . P   2
 * 1     P P P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToCapture()
{
	// SETUP
	BoardEmpty board;
	Queen queen(7, 7, false);
	queen.fWhite = true;
	queen.position.set(2, 1);
	board.board[2][1] = &queen;
	Black black0(PAWN);
	board.board[2][7] = &black0;
	Black black1(PAWN);
	board.board[0][3] = &black1;
	Black black2(PAWN);
	board.board[0][1] = &black2;
	Black black3(PAWN);
	board.board[1][0] = &black3;
	Black black4(PAWN);
	board.board[2][0] = &black4;
	Black black5(PAWN);
	board.board[3][0] = &black5;
	Black black6(PAWN);
	board.board[7][1] = &black6;
	Black black7(PAWN);
	board.board[7][6] = &black7;

	set<Position> expectedMoves = {
		{2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7},
		{1, 2}, {0, 3}, {3, 2}, {4, 3}, {5, 4}, {6, 5}, {7, 6},
		{1, 1}, {0, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1},
		{1, 0}, {2, 0}, {3, 0}
	};

	set <Move> moves;

	// EXERCISE
	moves = queen.getMoves(board);

	// VERIFY
	assertUnit(moves.size() == expectedMoves.size());

	// TEARDOWN
	board.board[2][1] == nullptr; //white queen
	board.board[2][7] == nullptr; //black pawns
	board.board[0][3] == nullptr;
	board.board[0][1] == nullptr;
	board.board[1][0] == nullptr;
	board.board[2][0] == nullptr;
	board.board[3][0] == nullptr;
	board.board[7][1] == nullptr;
	board.board[7][6] == nullptr;
}


/*************************************
 * GET TYPE : queen
 * Input:
 * Output: QUEEN
 **************************************/
void TestQueen::getType()
{
	// SETUP
	const Queen queen(7, 7, false);
	PieceType pt = SPACE;

	// EXERCISE
	pt = queen.getType();

	// VERIFY
	assertUnit(pt == QUEEN);
}
