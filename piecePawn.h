/***********************************************************************
 * Header File:
 *    PAWN
 * Author:
*    <your name here>
 * Summary:
 *    The PAWN class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * PAWN
  * The pawn.
  ***************************************************/
class Pawn : public Piece
{
public:
   Pawn(const Position& pos, bool isWhite) : Piece(pos, isWhite) { }
   Pawn(int c, int r, bool isWhite) : Piece(c, r, isWhite) { }
   ~Pawn() {                }
   PieceType getType()            const { return PAWN; }
   set<Move> getMoves(const Board& board) const;
   void display(ogstream* pgout)  const;
};