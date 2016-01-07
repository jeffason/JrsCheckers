/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// GamePiece.cpp
//
// DESCRIPTION:
//	Implementation for our basic GamePiece which belongs to a GameBoard
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GamePiece.h"

namespace jrs{

GamePiece::GamePiece( int _player_owner_id, const Vec2D& _orientation, const Vec2D _legal_moves[], wchar_t _draw_symbol )
{
	m_PlayerOwnerID = _player_owner_id;
	m_Orientation = _orientation;
	m_LegalMoves.assign(_legal_moves, _legal_moves + ARRAY_SIZE(_legal_moves));
	m_DrawSymbol = _draw_symbol;
}

}