/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CheckersGameBoard.cpp
//
// DESCRIPTION:
//	Implementation for our Checkers GameBoard type
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "CheckersGameBoard.h"
#include "Config.h"

namespace jrs{

CheckersGameBoard::CheckersGameBoard(void)
{
	//TODO: pull this from config once we get multiple .ini value parsing working
	// all checkers pieces are uniformly limited to these moves based on each piece's orientation
	m_LegalMovesForGamePieces[0] = Vec2D(-1,1);
	m_LegalMovesForGamePieces[1] = Vec2D(1,1);

	std::wstring test = GConfig->GetSettingString(L"CheckersGameBoard", L"PlayerOnePieceSymbol");
	m_PlayerOnePieceSymbol = GConfig->GetSettingString(L"CheckersGameBoard", L"PlayerOnePieceSymbol")[0];
	m_PlayerTwoPieceSymbol = GConfig->GetSettingString(L"CheckersGameBoard", L"PlayerTwoPieceSymbol")[0];
}


CheckersGameBoard::~CheckersGameBoard(void)
{
}

void CheckersGameBoard::Initialize()
{
	GameBoard::Initialize();

	// default piece orientation for each player
	Vec2D orientation_player_one(1,0), orientation_player_two(-1,0);
	int num_rows_per_player = (m_SizeY - 2) / 2;
	for ( int i = num_rows_per_player - 1; i >= 0; i-- )
	{
		int row_player_one = i;
		int row_player_two = m_SizeY - 1 - i;
		for ( int j = 0; j < m_SizeX; j++)
		{
			// fill every other space for each player on each of their respective rows

			// which player index owns this piece?
			int player_owner_index = (j % 2) ^ (i % 2);

			// grab the iterator for this position on the board
			Vec2D position(j, player_owner_index == 1 ? row_player_two : row_player_one);
			GameBoardStatusIter board_space = GetGameBoardStatusAt(position);

			// setup the piece in this position
			(*board_space).reset( new GamePiece(player_owner_index, player_owner_index == 1 ? orientation_player_two : 
				orientation_player_one, m_LegalMovesForGamePieces, player_owner_index == 1 ? m_PlayerTwoPieceSymbol : m_PlayerOnePieceSymbol) );
		}
	}
}

}