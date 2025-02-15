/***********************************************************************
 * Header File:
 *    KING
 * Author:
*    <your name here>
 * Summary:
 *    The KING class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * KING
  * The king, aka the "Crown"
  ***************************************************/
class King : public Piece
{
public:
   King(const Position& pos, bool isWhite) : Piece(pos, isWhite) { }
   King(int c, int r, bool isWhite) : Piece(c, r, isWhite) { }
   ~King() {                }
   PieceType getType()            const { return KING; }
   set<Move> getMoves(const Board& board) const;
   void display(ogstream* pgout)  const;
};