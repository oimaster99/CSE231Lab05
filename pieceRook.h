/***********************************************************************
 * Header File:
 *    ROOK
 * Author:
*    <your name here>
 * Summary:
 *    The ROOK class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * ROOK
  * The rook.
  ***************************************************/
class Rook : public Piece
{
public:
   Rook(const Position& pos, bool isWhite) : Piece(pos, isWhite) { }
   Rook(int c, int r, bool isWhite) : Piece(c, r, isWhite) { }
   ~Rook() {                }
   PieceType getType()            const { return ROOK; }
   set<Move> getMoves(const Board& board) const;
   void display(ogstream* pgout)  const;
};