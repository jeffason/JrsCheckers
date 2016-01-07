/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CheckersGameBoard.h
//
// DESCRIPTION:
//	Our specialized GameBoard type managed by our CheckersGameEngine
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "gameboard.h"

namespace jrs{

class CheckersGameBoard : public GameBoard
{
public:

	//
	// Methods
	//
	CheckersGameBoard(void);
	virtual ~CheckersGameBoard(void);

	// resets game board to initial play state
	virtual void Initialize();

private:
	// defines what possible moves are for a checkers game piece
	Vec2D m_LegalMovesForGamePieces[2];

	wchar_t m_PlayerOnePieceSymbol;
	wchar_t m_PlayerTwoPieceSymbol;
};

}