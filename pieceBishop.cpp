/***********************************************************************
 * Source File:
 *    BISHOP
 * Author:
 *    <your name here>
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceBishop.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Bishop::display(ogstream* pgout) const
{

}


/**********************************************
 * BISHOP : GET POSITIONS
 *********************************************/
set<Move> Bishop::getMoves(set <Move>& moves, const Board& board) const
{
    ColRowP movement[] =
    {
       {-1, 1}, {1, 1}, {-1, -1}, {1, -1},
    };
    for (int i = 0; i < 4; i++)
    {
        int r = position.getRow() + movement[i].row;
        int c = position.getCol() + movement[i].col;
        Position possibleMove = Position(c, r);

        while (possibleMove.isValid() && board[possibleMove].getType() == SPACE)
        {
            moves.insert(Move(position, possibleMove, isWhite()));
            //move.setSource(getPosition());
            //move.setDest(possibleMove);
            //move.setIsWhite(isWhite());

            // adjust the position we're moving to
            r += movement[i].row;
            c += movement[i].col;
            possibleMove = Position(c, r);
        }

        if (possibleMove.isValid())
        {
            if (board[possibleMove].getType() == SPACE)
            {
                moves.insert(Move(position, possibleMove, isWhite()));
            }
            else if (board[possibleMove].isWhite() != this->isWhite())
            {
                moves.insert(Move(position, possibleMove, isWhite(), board[possibleMove].getType()));
            }
        }
    }
    return moves;
}
