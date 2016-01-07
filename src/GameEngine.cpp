/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// GameEngine.cpp
//
// DESCRIPTION:
//	Implementation for our base GameEngine object
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GameEngine.h"

#include <assert.h>
#include <conio.h>

#include "Config.h"
#include "Logger.h"

namespace jrs{

GameEngine::GameEngine(void)
{
	m_MaxPlayers = m_NumHumanPlayers = m_ActiveTurnPlayerIndex =-1;
	m_GameBoard = nullptr;
}


GameEngine::~GameEngine(void)
{
}

void GameEngine::Initialize()
{
	Engine::Initialize();
	m_MaxPlayers = GConfig->GetSettingInt(L"GameEngine", L"MaxPlayers");
	assert(m_MaxPlayers > 0);

	// figure out how many human players our game has
	char buffer[] = "0";
	while( m_NumHumanPlayers < 1 || m_NumHumanPlayers > m_MaxPlayers )
	{
		LOG_MESSAGE(L"Please enter the number of human players for this game between the range 1-%d", m_MaxPlayers);
		buffer[0] = GetUserKeyPress();
		m_NumHumanPlayers = atoi(buffer);
	}

	LOG_MESSAGE(L"Thanks! This game is being setup for %d human players and %d AI players.", m_NumHumanPlayers, 
		m_MaxPlayers - m_NumHumanPlayers );
}

bool GameEngine::TickFrame()
{
	Engine::TickFrame();

	if ( IsGameOver() )
	{
		ShowEndGameSummary();
		return false; // all done!
		//TODO: offer player opportunity to play again
	}

	return true;
}

bool GameEngine::IsGameOver()
{
	// TODO: need to implement game state control logic
	//bool b_stale_mate = true; // stale mate if no players have moves left
	//for ( auto player : m_Players )
	//{
	//	if ( player->IsWinner() )
	//		return true;

	//	b_stale_mate = b_stale_mate && player->HasLegalMovesAvailable();
	//}

	//return b_stale_mate;

	return false;
}

}