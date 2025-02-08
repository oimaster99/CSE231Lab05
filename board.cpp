/***********************************************************************
 * Source File:
 *    BOARD 
 * Author:
 *    <your name here>
 * Summary:
 *    A collection of pieces and a small amount of game state
 ************************************************************************/

#include "board.h"
#include "uiDraw.h"
#include "position.h"
#include "piece.h"
#include "pieceSpace.h"
#include "pieceKnight.h"
#include <cassert>
using namespace std;


/***********************************************
 * BOARD : RESET
 *         Just fill the board with the known pieces
 *   +---a-b-c-d-e-f-g-h---+
 *   |                     |
 *   8     N         N     8
 *   7                     7
 *   6                     6
 *   5                     5
 *   4                     4
 *   3                     3
 *   2                     2
 *   1     n         n     1
 *   |                     |
 *   +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void Board::reset(bool fFree)
{
   // free everything
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++) 
      {
          board[c][r] = nullptr;
      }

   board[1][0] = new Knight(Position(1, 0), true);
   board[6][0] = new Knight(Position(1, 0), true);
   board[1][7] = new Knight(Position(1, 0), true);
   board[6][7] = new Knight(Position(1, 0), true);
}

// we really REALLY need to delete this.
Space space(0,0);

/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
const Piece& Board::operator [] (const Position& pos) const
{
   return *board[pos.getCol()][pos.getRow()];
}
Piece& Board::operator [] (const Position& pos)
{
    return *board[pos.getCol()][pos.getRow()];
}

 /***********************************************
 * BOARD : DISPLAY
 *         Display the board
 ***********************************************/
void Board::display(const Position & posHover, const Position & posSelect) const
{
   
}


/************************************************
 * BOARD : CONSTRUCT
 *         Free up all the allocated memory
 ************************************************/
Board::Board(ogstream* pgout, bool noreset) : pgout(pgout), numMoves(0)
{

}


/************************************************
 * BOARD : FREE
 *         Free up all the allocated memory
 ************************************************/
void Board::free()
{
    // free everything
    for (int r = 0; r < 8; r++)
        for (int c = 0; c < 8; c++)
            if (board[c][r]) {
                board[c][r] = nullptr;
            }
        
}


/**********************************************
 * BOARD : ASSERT BOARD
 *         Verify the board is well-formed
 *********************************************/
void Board::assertBoard()
{

}




/**********************************************
 * BOARD : MOVE
 *         Execute a move according to the contained instructions
 *   INPUT move The instructions of the move
 *********************************************/
void Board::move(const Move & move)
{  
    Position source = move.getSource();
    Position dest = move.getDest();
    Piece* p = board[source.getCol()][source.getRow()];
    board[dest.getCol()][dest.getRow()] = p;
    board[source.getCol()][source.getRow()] = new Space(source.getCol(), source.getRow());
    p->setLoc(dest);
    p->setLastMove(numMoves);
    numMoves++;
}



/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(nullptr), moveNumber(0)
{
   pSpace = new Space(0, 0);
}
BoardEmpty::~BoardEmpty() 
{
   delete pSpace;
}

BoardDummy::BoardDummy() : Board(nullptr, true)
{
    numMoves = 0;

    for (int x = 0; x < 8; x++) 
    {
        for (int y = 0; y < 8; y++) 
        {
            board[x][y] = nullptr;
        }
    }

}