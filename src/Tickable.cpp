/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Tickable.cpp
//
// DESCRIPTION:
//	Implementation for our base Tickable object
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Tickable.h"

#include "Engine.h"

namespace jrs{

Tickable::Tickable(void)
{
	GEngine->RegisterTickable(std::shared_ptr<Tickable>(this));
}

Tickable::~Tickable(void)
{
	GEngine->UnregisterTickable(std::shared_ptr<Tickable>(this));
}

}