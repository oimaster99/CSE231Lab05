/***********************************************************************
 * Source File:
 *    ROOK
 * Author:
 *    <your name here>
 * Summary:
 *    The rook class
 ************************************************************************/

#include "pieceRook.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Rook::display(ogstream* pgout) const
{

}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Rook::getMoves(set <Move>& moves, const Board& board) const
{
    ColRowP movement[] =
    {
       {-1, 0 }, {1, 0},
      {0, -1 }, {0, 1}
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