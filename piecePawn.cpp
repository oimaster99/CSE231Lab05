/***********************************************************************
 * Source File:
 *    PAWN
 * Author:
 *    <your name here>
 * Summary:
 *    The knight class
 ************************************************************************/

#include "piecePawn.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Pawn::display(ogstream* pgout) const
{

}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Pawn::getMoves(set <Move>& moves, const Board& board) const
{
    ColRowP movement[] =
    {
       {-1, 2}, {1, 2}, {-1, -2}, {1, -2},
       {-2, 1}, {2, 1}, {-2, -1}, {2, -1}
    };
    for (int i = 0; i < 8; i++) 
    {
        int r = position.getRow() + movement[i].row;
        int c = position.getCol() + movement[i].col;
        Position possibleMove = Position(c, r);

        if (possibleMove.isValid()) 
        {
            if (board[possibleMove].getType() == SPACE)
            {
                moves.insert(Move(position, possibleMove, isWhite()));
            }
            else if (board[possibleMove].isWhite() != this->isWhite())
            {
                moves.insert(Move(position, possibleMove, isWhite(), board[possibleMove].getType()));
            };
        }
    }
}