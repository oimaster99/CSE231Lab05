 /***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKnight.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Knight::display(ogstream* pgout) const
{
    pgout->drawKnight(position.getLocation(), !fWhite);
}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
set<Move> Knight::getMoves(set <Move>& moves, const Board& board) const
{
    Delta movement[] =
    {
       {-1, 2}, {1, 2}, {-1, -2}, {1, -2},
       {-2, 1}, {2, 1}, {-2, -1}, {2, -1}
    };

    return getMoveCalc(movement, sizeof(movement) / sizeof(movement[0]), board);
   /* for (int i = 0; i < sizeof(movement) / sizeof(movement[0]); i++)
    {
        int r = position.getRow();
        int c = position.getCol();
        int steps = 0;
        //Position possibleMove = Position(c, r);
        while (steps < movement[i].maxSteps)
        {
            r += movement[i].row;
            c += movement[i].col;
            Position possibleMove = Position(c, r);

            if (!possibleMove.isValid())
                break; // Stop if out of bounds

            if (board[possibleMove].getType() == SPACE)
            {
                moves.insert(Move(position, possibleMove, isWhite()));
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

            steps++;

            // If it's a jumping piece (like a knight), stop after one move
            if (movement[i].maxSteps == 1)
                break;*/


        /*if (possibleMove.isValid())
        {
            if (board[possibleMove].getType() == SPACE)
            {
                moves.insert(Move(position, possibleMove, isWhite()));
            }
            else if (board[possibleMove].isWhite() != this->isWhite())
            {
                moves.insert(Move(position, possibleMove, isWhite(), board[possibleMove].getType()));
            };*/
     //   }
   // }
}