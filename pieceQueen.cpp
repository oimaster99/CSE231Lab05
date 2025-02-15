/***********************************************************************
 * Source File:
 *    QUEEN
 * Author:
 *    <your name here>
 * Summary:
 *    The queen class
 ************************************************************************/

#include "pieceQueen.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Queen::display(ogstream* pgout) const
{
    pgout->drawQueen(position.getLocation(), !fWhite);
}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
set<Move> Queen::getMoves(const Board& board) const
{
    Delta movement[] =
    {
       {-1, 1 }, {0, 1 }, {1, 1},
      {-1, 0 },          {1, 0},
      {-1, -1}, {0, -1}, {1, -1}
    };

    return getMoveSlideCalc(movement, sizeof(movement) / sizeof(movement[0]), board);

    /*for (int i = 0; i < 8; i++)
    {
        int r = position.getRow() + movement[i].dRow;
        int c = position.getCol() + movement[i].dCol;
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
    }*/
}