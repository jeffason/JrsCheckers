/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Player.cpp
//
// DESCRIPTION:
//	Implementation for our base Player functionality
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Player.h"

#include "GameEngine.h"

namespace jrs{

Player::Player(void)
{
	m_PlayerIndex = -1;
	m_bIsWinner = false;
}


Player::~Player(void)
{
}

void Player::Tick(float _delta_time)
{
	// when it's our turn, handle and process any input (or AI)
	// TODO: GameEngine must actually recognize when it is this players turn
	if ( GGameEngine->IsPlayersTurn(m_PlayerIndex) )
	{
		HandlePlayerInput();
	}
}

void Player::FinishPlayerTurn()
{
	// our turn is over, let the game continue to the next player's turn
	// TODO: GameEngine must actually manage player turn cycle
	GGameEngine->NextPlayersTurn();
}

bool Player::HasLegalMovesAvailable()
{
	for ( auto game_piece: m_GamePieces )
	{
		if ( game_piece->HasLegalMovesAvailable() )
			return true;
	}

	return false;
}

}