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
set<Move> Piece::getMoveCalc(Delta movement[], int numMoves, const Board& board) const
{
    set<Move> moves;

    for (int i = 0; i < numMoves; i++)
    {
        Position possibleMove(position, movement[i]);

        if (possibleMove.isValid())
        {
            if (board[possibleMove].isWhite() != isWhite() || board[possibleMove].getType() == SPACE)
            {
                Move move;
                move.setSource(getPosition());
                move.setDest(possibleMove);
                move.setIsWhite(isWhite());
                if (board[possibleMove].getType() != SPACE)
                {
                    move.setCapture(board[possibleMove].getType());
                }
                moves.insert(move);
            }
        }
    }
    return moves;

        // Keep sliding until we reach maxSteps (1 for jumps, higher for sliders)
       /* while (steps < movement[i].maxSteps)
        {
            

            if (!possibleMove.isValid())
                break; // Stop if out of bounds

            if (board[possibleMove].isWhite() != isWhite() || board[possibleMove].getType() == SPACE)
            {
                Move move;
                move.setSource(getPosition());
                move.setDest(possibleMove);
                move.setIsWhite(isWhite());
                if (board[possibleMove].getType() != SPACE) 
                {
                    move.setCapture(board[possibleMove].getType());
                }
                moves.insert(move);
            }
            else
            {
                // If the piece is enemy, capture it, then stop sliding
                if (board[possibleMove].isWhite() != this->isWhite())
                {
                    moves.insert(Move(position, possibleMove, isWhite(), board[possibleMove].getType()));
                }
                break; // Stop at first piece
            }

            r += movement[i].row;
            c += movement[i].col;
            steps++;

            // If it's a jumping piece (like a knight), stop after one move
            if (movement[i].maxSteps == 1)
                break;
        }
    }
    return moves;*/
}

set<Move> Piece::getMoveSlideCalc(const Delta movement[], int numMoves, const Board& board) const 
{
    set<Move> moves;

    for (int i = 0; i < numMoves; i++) 
    {
        Position possibleMove(position, movement[i]);

        while (possibleMove.isValid() && board[possibleMove].getType() == SPACE) 
        {
            Move move;
            move.setSource(getPosition());
            move.setDest(possibleMove);
            move.setIsWhite(isWhite());
            moves.insert(move);

            possibleMove = Position(possibleMove.getLocation(), movement[i]);
        }

        if (possibleMove.isValid() && board[possibleMove].isWhite() != fWhite && board[possibleMove].getType() != SPACE) 
        {
            Move move;
            move.setSource(getPosition());
            move.setDest(possibleMove);
            move.setIsWhite(isWhite());
            move.setCapture(board[position].getType());
            moves.insert(move);
        }
    }
    return moves;
}