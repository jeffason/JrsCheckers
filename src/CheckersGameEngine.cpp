/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CheckersGameEngine.cpp
//
// DESCRIPTION:
//	Implementation for Checkers GameEngine type
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "CheckersGameEngine.h"

#include <memory>

#include "CheckersGameBoard.h"
#include "Logger.h"

namespace jrs{

CheckersGameEngine::CheckersGameEngine(void)
{
}


CheckersGameEngine::~CheckersGameEngine(void)
{
}

void CheckersGameEngine::Initialize()
{
	GameEngine::Initialize();

	// create and initialize our CheckersGameBoard type
	m_GameBoard = std::make_shared<CheckersGameBoard>();
	m_GameBoard->Initialize();
}

void CheckersGameEngine::ShowEndGameSummary()
{
	//TODO: need to say which player wins, etc.
	LOG_MESSAGE(L"Thanks for playing!");
}

}