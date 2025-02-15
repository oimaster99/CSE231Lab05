/***********************************************************************
 * Header File:
 *    BISHOP
 * Author:
*    <your name here>
 * Summary:
 *    The BISHOP class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * BISHOP
  * The bishop.
  ***************************************************/
class Bishop : public Piece
{
public:
   Bishop(const Position& pos, bool isWhite) : Piece(pos, isWhite) { }
   Bishop(int c, int r, bool isWhite) : Piece(c, r, isWhite) { }
   ~Bishop() {                }
   PieceType getType()            const { return BISHOP; }
   set<Move> getMoves(const Board& board) const;
   void display(ogstream* pgout)  const;
};