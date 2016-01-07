/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// HumanPlayer.h
//
// DESCRIPTION:
//	Human variation of Player type which requires actual human user input to drive moves when the
//	game state indicates it is this player's turn
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "player.h"

namespace jrs{

class HumanPlayer :	public Player
{
public:
	HumanPlayer(void);
	virtual ~HumanPlayer(void);

	virtual void HandlePlayerInput();
};

}