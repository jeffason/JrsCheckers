/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CheckersGameEngine.h
//
// DESCRIPTION:
//	Engine type that drives our Checkers game
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "gameengine.h"

namespace jrs{

class CheckersGameEngine : public GameEngine
{
public:
	// declare factory for dynamic instantiation by class name via AbstractFactory
	DECLARE_DEFAULT_FACTORY(CheckersGameEngine);

	//
	// Methods
	//
	CheckersGameEngine(void);
	virtual ~CheckersGameEngine(void);

	virtual void Initialize();
	virtual void ShowEndGameSummary();
};

}