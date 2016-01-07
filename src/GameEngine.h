/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// GameEngine.h
//
// DESCRIPTION:
//	Base GameEngine type which manages the GameBoard
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vector>
#include <memory>

#include "engine.h"
#include "Player.h"
#include "GameBoard.h"

// TODO: should cache the dynamic_pointer_cast and globally share the cached value 
//		 instead of recomputing every time
#define GGameEngine std::dynamic_pointer_cast<GameEngine>(GEngine)

namespace jrs{

class GameEngine : public Engine
{
public:
	// declare factory for dynamic instantiation by class name via AbstractFactory
	DECLARE_DEFAULT_FACTORY(GameEngine);

	//
	// Methods
	//
	GameEngine(void);
	virtual ~GameEngine(void);

	virtual void Initialize();

	inline bool IsPlayersTurn( int _player_index ) 
	{
		return m_ActiveTurnPlayerIndex == _player_index;
	}

	inline void NextPlayersTurn()
	{
		m_ActiveTurnPlayerIndex = (m_ActiveTurnPlayerIndex + 1) % m_MaxPlayers;
	}

	virtual bool TickFrame();
	virtual bool IsGameOver();
	virtual void ShowEndGameSummary()
	{
	}

protected:
	
	//
	// Members
	//
	std::shared_ptr<GameBoard> m_GameBoard;

private:

	//
	// Members
	//
	std::vector< std::shared_ptr<Player> > m_Players;
	int m_MaxPlayers;
	int m_NumHumanPlayers;
	int m_ActiveTurnPlayerIndex;
};

}