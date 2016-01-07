/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// AIPlayer.h
//
// DESCRIPTION:
//	This player variation provides an AI-controlled implementation that automatically processes
//	when it becomes this player's turn in the game state.
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "player.h"

namespace jrs{

class AIPlayer : public Player
{
public:

	//
	// Methods
	//
	AIPlayer(void);
	virtual ~AIPlayer(void);

	virtual void HandlePlayerInput();

};

}