/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// GamePiece.h
//
// DESCRIPTION:
//	Base GamePiece functionality for representation of pieces on the GameBoard
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vector>

#include "Core.h"

namespace jrs{

class GamePiece
{
public:
	GamePiece( int _player_owner_id, const Vec2D& _orientation, const Vec2D _legal_moves[], wchar_t _draw_symbol );
	virtual ~GamePiece(void) { }

	virtual bool HasLegalMovesAvailable() { return false; }
	inline wchar_t GetDrawSymbol() { return m_DrawSymbol; }

private:
	GamePiece(void) { }

	// which player owns this piece?
	int m_PlayerOwnerID;
	
	// which way the piece is facing which legal moves are based on
	Vec2D m_Orientation;

	// legal moves a piece can make assuming default orientation (0,1)
	std::vector<Vec2D> m_LegalMoves;

	// what character represents this piece when rendered?
	wchar_t m_DrawSymbol;
};

}