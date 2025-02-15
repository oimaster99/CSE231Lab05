/***********************************************************************
 * Source File:
 *    TEST ROOK
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the rook
 ************************************************************************/

#include "testRook.h"
#include "pieceRook.h"     
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
 * 3       p             3
 * 2     p(r)p           2
 * 1       p             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_blocked()
{
    // SETUP
    BoardEmpty board;
    Rook rook(7, 7, false);
    rook.fWhite = true;
    rook.position.set(2, 1);
    board.board[2][1] = &rook;
	White white0(PAWN);
	board.board[2][0] = &white0;
	White white1(PAWN);
	board.board[1][1] = &white1;
	White white2(PAWN);
	board.board[2][2] = &white2;
	White white3(PAWN);
	board.board[3][1] = &white3;
	set <Move> moves;

	// EXERCISE
	moves = rook.getMoves(board);

	// VERIFY
	assertUnit(moves.size() == 0);

	// TEARDOWN
	board.board[2][1] == nullptr; //white rook
	board.board[2][0] == nullptr; //white pawns
	board.board[1][1] == nullptr;
	board.board[2][2] == nullptr;
	board.board[3][1] == nullptr;

}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   . .(r). . . . .   2
 * 1       .             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToEnd()
{
	// SETUP
	BoardEmpty board;

	Rook rook(7, 7, false);
	rook.fWhite = true;
	rook.position.set(2, 1);
	board.board[2][1] = &rook;

	set<Move> moves;

	set<Position> expectedMoves = {
		{2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7},
		{1, 1}, {0, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1},
		{2, 0}
	};

	// EXERCISE
	moves = rook.getMoves(board);

	// VERIFY
	assertUnit(moves.size() == expectedMoves.size());

	// TEARDOWN
	board.board[2][1] == nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   p .(r). . . . p   2
 * 1       p             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToBlock()
{
	// SETUP
	BoardEmpty board;

	Rook rook(7, 7, false);
	rook.fWhite = true;
	rook.position.set(2, 1);
	board.board[2][1] = &rook;
	White white0(PAWN);
	board.board[0][1] = &white0;
	White white1(PAWN);
	board.board[2][0] = &white1;
	White white2(PAWN);
	board.board[7][1] = &white2;
	White white3(PAWN);
	board.board[2][7] = &white3;
	set <Move> moves;

	set<Position> expectedMoves = {
		{2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6},
		{1, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}
	};

	// EXERCISE
	moves = rook.getMoves(board);

	// VERIFY
	assertUnit(moves.size() == expectedMoves.size());

	// TEARDOWN
	board.board[2][1] == nullptr;
	board.board[0][1] == nullptr;
	board.board[2][0] == nullptr;
	board.board[7][1] == nullptr;
	board.board[2][7] == nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   P .(r). . . . P   2
 * 1       P             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToCapture()
{
	// SETUP
	BoardEmpty board;

	Rook rook(7, 7, false);
	rook.fWhite = true;
	rook.position.set(2, 1);
	board.board[2][1] = &rook;
	Black black0(PAWN);
	board.board[0][1] = &black0;
	Black black1(PAWN);
	board.board[2][0] = &black1;
	Black black2(PAWN);
	board.board[7][1] = &black2;
	Black black3(PAWN);
	board.board[2][7] = &black3;
	set <Move> moves;

	set<Position> expectedMoves = {
		{2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7},
		{1, 1}, {0, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1},
		{2, 0}
	};

	// EXERCISE
	moves = rook.getMoves(board);

	// VERIFY
	assertUnit(moves.size() == expectedMoves.size());

	// TEARDOWN
	board.board[2][1] == nullptr;
	board.board[0][1] == nullptr;
	board.board[2][0] == nullptr;
	board.board[7][1] == nullptr;
	board.board[2][7] == nullptr;
}


/*************************************
 * GET TYPE : rook
 * Input:
 * Output: ROOK
 **************************************/
void TestRook::getType()
{
	// SETUP
	const Rook rook(7, 7, false);
	PieceType pt = SPACE;

	// EXERCISE
	pt = rook.getType();

	// VERIFY
	assertUnit(pt == ROOK);
}
