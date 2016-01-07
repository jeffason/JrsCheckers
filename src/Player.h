/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Player.h
//
// DESCRIPTION:
//	Abstract base for different concrete game player types
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "GamePiece.h"
#include "tickable.h"

#include <vector>
#include <memory>

namespace jrs{

class Player : public Tickable
{
public:

	//
	// Methods
	//
	Player(void);
	virtual ~Player(void);

	virtual void Tick(float _delta_time);
	virtual void HandlePlayerInput() = 0;
	void FinishPlayerTurn();

	inline bool IsWinner()
	{
		return m_bIsWinner;
	}

	inline void TriggerPlayerWins()
	{
		m_bIsWinner = true;
	}

	bool HasLegalMovesAvailable();

private:

	//
	// Members
	//
	std::vector< std::shared_ptr<GamePiece> > m_GamePieces;
	int m_PlayerIndex;
	bool m_bIsWinner;
};

}