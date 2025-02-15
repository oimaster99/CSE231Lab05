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
    pgout->drawPawn(position.getLocation(), !fWhite);
}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
set<Move> Pawn::getMoves(const Board& board) const
{
    set<Move> moves;
    Position movement(getPosition(), isWhite() ? Delta({ 1, 0 }) : Delta({ -1, 0 }));

    if (movement.isValid() && board[movement].getType() == SPACE)
    {
        Move move;
        move.setSource(getPosition());
        move.setDest(movement);
        move.setIsWhite(isWhite());

        if (movement.getRow() == (isWhite() ? 7 : 0))
        {
            move.setPromotion(QUEEN);
        }
        moves.insert(move);
    }

    if (!isMoved())
    {
        Position posMove(isWhite() ? 3 : 4, getPosition().getCol());
        Position posCheck(isWhite() ? 2 : 5, getPosition().getCol());

        if (board[posMove].getType() == SPACE && board[posCheck].getType() == SPACE)
        {
            Move move;
            move.setSource(getPosition());
            move.setDest(posMove);
            move.setIsWhite(isWhite());
            moves.insert(move);
        }
    }

    int values[2] = { -1, 1 };

    for (auto i : values)
    {
        Position posMove(position.getRow() + (isWhite() ? 1 : -1), position.getCol() + i);
        if (posMove.isValid() && board[posMove].getType() != SPACE && board[posMove].isWhite() != isWhite())
        {
            Move move;
            move.setSource(getPosition());
            move.setDest(posMove);
            move.setIsWhite(isWhite());
            move.setCapture(board[posMove].getType());
            if (posMove.getRow() == 7 || posMove.getRow() == 0)
            {
                move.setPromotion(QUEEN);
            }
            moves.insert(move);
        }
    }

    for (auto i : values)
    {
        Position positionMove(position.getRow() + (isWhite() ? 1 : -1), position.getCol() + i);
        Position positionKill(position.getRow(), position.getCol() + i);

        if (positionMove.isValid() && (position.getRow() == (isWhite() ? 4 : 3)) && board[positionMove].getType() == SPACE &&
            board[positionKill].getType() == PAWN && board[positionKill].isWhite() != isWhite() &&
            board[positionKill].getNMoves() == 1 && board[positionKill].justMoved(board.getCurrentMove()))
        {
            Move move;
            move.setSource(getPosition());
            move.setDest(positionMove);
            move.setIsWhite(isWhite());
            move.setCapture(board[positionKill].getType());
            move.setEnPassant();
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