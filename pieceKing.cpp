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

    //Kingside CASTLE move
    if (!isMoved()) 
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

    //Queenside CASTLE move
    if (!isMoved())
    {
        Position positionSpace1(position.getRow(), 3);
        Position positionMove(position.getRow(), 2);
        Position positionSpace2(position.getRow(), 1);
        Position positionRook(position.getRow(), 0);

        if ((board[positionMove].getType() == SPACE && board[positionSpace1].getType() == SPACE)
            && (board[positionRook].getType() == ROOK && board[positionSpace2].getType() == SPACE)
            && board[positionRook].isMoved() == false)
        {
            // add castling to the possible moves
            Move move;
            move.setSource(getPosition());
            move.setDest(positionMove);
            move.setIsWhite(isWhite());
            move.setCastle(false);
            moves.insert(move);
        }
    }

    return moves;

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