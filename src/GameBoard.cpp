/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// GameBoard.cpp
//
// DESCRIPTION:
//	Implementation for our base GameBoard object which is initialized based on config
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GameBoard.h"

#include <assert.h>
#include <sstream>

#include "Config.h"
#include "Logger.h"

namespace jrs{

GameBoard::GameBoard(void)
{
	m_EmptySpaceSymbol = GConfig->GetSettingString(L"GameBoard",L"EmptySpaceSymbol")[0];
}

GameBoard::~GameBoard(void)
{
}

void GameBoard::Initialize()
{
	int size_x = GConfig->GetSettingInt(L"GameBoard",L"SizeX");
	int size_y = GConfig->GetSettingInt(L"GameBoard",L"SizeY");
	assert(size_x > 0 && size_y > 0);
	m_SizeX = size_x;
	m_SizeY = size_y;
	m_GameBoardStatus.resize(m_SizeX * m_SizeY, nullptr);
}

void GameBoard::Tick(float _delta_time)
{
	RenderObject::Tick(_delta_time);
}

void GameBoard::Render()
{
	std::wstringstream out_stream;
	int count = 0;
	for ( auto status : m_GameBoardStatus )
	{
		wchar_t draw_symbol;
		if ( status == nullptr )
		{
			draw_symbol = m_EmptySpaceSymbol;
		}
		else
		{
			draw_symbol = status->GetDrawSymbol();
		}

		out_stream << draw_symbol << ' ';
		count++;

		// newline when we reach the end of line
		if ( !(count % m_SizeX) )
			out_stream << "\n";
	}

	LOG_MESSAGE(out_stream.str().c_str());
}

GameBoard::GameBoardStatusIter GameBoard::GetGameBoardStatusAt( const Vec2D& _pos )
{
	if ( !IsPositionInBounds(_pos) )
		return m_GameBoardStatus.end();

	int index = GetIndexFrom2DPosition( _pos );
	assert(index >= 0 && (unsigned)index < m_GameBoardStatus.size()); // sanity check
	
	// return iterator at index
	return std::next(m_GameBoardStatus.begin(), index);
}

}