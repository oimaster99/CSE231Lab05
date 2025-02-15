/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKing.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void King::display(ogstream* pgout) const
{
    pgout->drawKing(position.getLocation(), !fWhite);
}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
set<Move> King::getMoves(const Board& board) const
{
    Delta movement[] =
    {
      {-1, 1 }, {0, 1 }, {1, 1 },
      {-1, 0 }, {1, 0 },
      {-1, -1}, {0, -1}, {1, -1}
    };

    set<Move> moves = getMoveCalc(movement, sizeof(movement) / sizeof(movement[0]), board);

    //King CASTLE move
    if (!isMoved) 
    {
        Position positionSpace(position.getRow(), 5);
        Position positionMove(position.getRow(), 6);
        Position positionRook(position.getRow(), 7);

        if ((board[positionMove].getType() == SPACE && board[positionSpace].getType() == SPACE)
            && (board[positionRook].isMoved() == false && board[positionRook].getType() == ROOK))
        {
            Move move;
            move.setSource(getPosition());
            move.setDest(positionMove);
            move.setIsWhite(isWhite());
            move.setCastle(true);
            moves.insert(move);
        }
    }

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