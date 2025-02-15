/***********************************************************************
 * Source File:
 *    TEST KING
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the King
 ************************************************************************/

#include "testKing.h"
#include "pieceRook.h"
#include "pieceKing.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       p p p         6
 * 5       p(k)p         5
 * 4       p p p         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blocked()
{
	// SETUP
	BoardEmpty board;
	King king(7, 7, false);
	king.fWhite = true;
	king.position.set(3, 4);
	board.board[3][4] = &king;
	White white0(PAWN);
	board.board[2][5] = &white0;
	White white1(PAWN);
	board.board[3][5] = &white1;
	White white2(PAWN);
	board.board[4][5] = &white2;
	White white3(PAWN);
	board.board[4][4] = &white3;
	White white4(PAWN);
	board.board[4][3] = &white4;
	White white5(PAWN);
	board.board[3][3] = &white5;
	White white6(PAWN);
	board.board[2][3] = &white6;
	White white7(PAWN);
	board.board[2][4] = &white7;

	set <Move> moves;

	// EXERCISE
	moves = king.getMoves(board);

	// VERIFY
	assertUnit(moves.size() == 0);

	// TEARDOWN
	board.board[3][4] == nullptr; //white king
	board.board[2][5] == nullptr; //white pawns
	board.board[3][5] == nullptr;
	board.board[4][5] == nullptr;
	board.board[4][4] == nullptr;
	board.board[4][3] == nullptr;
	board.board[3][3] == nullptr;
	board.board[2][3] == nullptr;
	board.board[2][4] == nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       P P P         6
 * 5       P(k)P         5
 * 4       P P P         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_capture()
{
	// SETUP
	BoardEmpty board;
	King king(7, 7, false);
	king.fWhite = true;
	king.position.set(3, 4);
	board.board[3][4] = &king;
	Black black0(PAWN);
	board.board[2][5] = &black0;
	Black black1(PAWN);
	board.board[3][5] = &black1;
	Black black2(PAWN);
	board.board[4][5] = &black2;
	Black black3(PAWN);
	board.board[4][4] = &black3;
	Black black4(PAWN);
	board.board[4][3] = &black4;
	Black black5(PAWN);
	board.board[3][3] = &black5;
	Black black6(PAWN);
	board.board[2][3] = &black6;
	Black black7(PAWN);
	board.board[2][4] = &black7;

	set <Move> moves;

	set<Position> expectedMoves = {
		{2, 5}, {3, 5}, {4, 5},
		{2, 4}, {4, 4},
		{4, 3}, {3, 3}, {2, 3}
	};

	// EXERCISE
	moves = king.getMoves(board);

	// VERIFY
	assertUnit(moves.size() == expectedMoves.size());

	// TEARDOWN
	board.board[3][4] == nullptr; //white king
	board.board[2][5] == nullptr; //black pawns
	board.board[3][5] == nullptr;
	board.board[4][5] == nullptr;
	board.board[4][4] == nullptr;
	board.board[4][3] == nullptr;
	board.board[3][3] == nullptr;
	board.board[2][3] == nullptr;
	board.board[2][4] == nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       . . .         6
 * 5       .(k).         5
 * 4       . . .         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_free()
{
	// SETUP
	BoardEmpty board;
	King king(7, 7, false);
	king.fWhite = true;
	king.position.set(3, 4);
	board.board[3][4] = &king;

	set <Move> moves;

	set<Position> expectedMoves = {
		{2, 5}, {3, 5}, {4, 5},
		{2, 4}, {4, 4},
		{4, 3}, {3, 3}, {2, 3}
	};

	// EXERCISE
	moves = king.getMoves(board);

	// VERIFY
	assertUnit(moves.size() == expectedMoves.size());

	// TEARDOWN
	board.board[3][4] == nullptr; //white king
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2   . .               2
 * 1  (k).               1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_end()
{
	// SETUP
	BoardEmpty board;
	King king(7, 7, false);
	king.fWhite = true;
	king.position.set(0, 0);
	board.board[0][0] = &king;

	set <Move> moves;

	set<Position> expectedMoves = {
		{0, 1}, {1, 1}, {1, 0}
	};

	// EXERCISE
	moves = king.getMoves(board);

	// VERIFY
	assertUnit(moves.size() == expectedMoves.size());

	// TEARDOWN
	board.board[0][0] == nullptr; //white king
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r   . .(k). . r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastle()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   R   . .(K). . R   8
 * 7         P P P       7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blackCastle()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleKingMoved()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleRookMoved()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * GET TYPE : king
 * Input:
 * Output: KING
 **************************************/
void TestKing::getType()
{
	// SETUP
	const King king(7, 7, false);
	PieceType pt = SPACE;

	// EXERCISE
	pt = king.getType();

	// VERIFY
	assertUnit(pt == KING);
}


