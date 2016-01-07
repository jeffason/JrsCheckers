/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// GameBoard.h
//
// DESCRIPTION:
//	Base GameBoard type which manages GamePieces and board status
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vector>
#include <memory>

#include "Core.h"
#include "GamePiece.h"
#include "RenderObject.h"

namespace jrs{

class GameBoard : public RenderObject
{
public:
	
	//
	// Methods
	//
	GameBoard(void);
	virtual ~GameBoard(void);
	
	// resets game board to initial play state, gametype-specific implementations are in derived types
	virtual void Initialize();
	virtual void Tick(float _delta_time);
	virtual void Render();

protected:

	typedef std::vector< std::shared_ptr<GamePiece> > GameBoardStatus;
	typedef GameBoardStatus::iterator GameBoardStatusIter;
	
	//
	// Methods
	//
	GameBoardStatusIter GetGameBoardStatusAt( const Vec2D& _pos );
	inline bool IsPositionInBounds( const Vec2D& _pos )
	{
		return _pos.x >= 0 && _pos.x < m_SizeX && _pos.y >= 0 && _pos.y < m_SizeY; 
	}
	inline int GetIndexFrom2DPosition( const Vec2D& _pos )
	{
		return _pos.x + (_pos.y * m_SizeX);
	}

	//
	// Members
	//
	int m_SizeX;
	int m_SizeY;

private:

	//
	// Members
	//
	GameBoardStatus m_GameBoardStatus;
	wchar_t m_EmptySpaceSymbol;
};

}