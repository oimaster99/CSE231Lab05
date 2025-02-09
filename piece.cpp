/***********************************************************************
 * Source File:
 *    PIECE 
 * Author:
 *    <your name here>
 * Summary:
 *    The Piece base class and all the derived classes:
 *       SPACE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
 ************************************************************************/

#include "position.h"  // for POSITION
#include "piece.h"     // for all the PIECE class definitions
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "board.h"     // for BOARD
#include "uiDraw.h"    // for draw*()
#include <cassert>     // because we are paranoid
using namespace std;


/************************************************
 * PIECE : ASSIGN
 ***********************************************/
const Piece & Piece::operator = (const Piece & rhs)
{
	position = rhs.position;
	fWhite = rhs.fWhite;
	nMoves = rhs.nMoves;
	lastMove = rhs.lastMove;
    return *this;
}

/************************************************
 * PIECE : GET MOVES
 * Iterate through the moves decorator to allow a piece to move
 ***********************************************/
void Piece::getMoves(set <Move> & movesSet, const Board & board) const
{
    for (int i = 0; i < sizeof(movement) / sizeof(movement[0]); i++)
    {
        int r = position.getRow();
        int c = position.getCol();
        int steps = 0;

        // Keep sliding until we reach maxSteps (1 for jumps, higher for sliders)
        while (steps < movement[i].maxSteps)
        {
            r += movement[i].row;
            c += movement[i].col;
            Position possibleMove = Position(c, r);

            if (!possibleMove.isValid())
                break; // Stop if out of bounds

            if (board[possibleMove].getType() == SPACE)
            {
                movesSet.insert(Move(position, possibleMove, isWhite()));
            }
            else
            {
                // If the piece is enemy, capture it, then stop sliding
                if (board[possibleMove].isWhite() != this->isWhite())
                {
                    movesSet.insert(Move(position, possibleMove, isWhite(), board[possibleMove].getType()));
                }
                break; // Stop at first piece
            }

            steps++;

            // If it's a jumping piece (like a knight), stop after one move
            if (movement[i].maxSteps == 1)
                break;
        }
    }
}

