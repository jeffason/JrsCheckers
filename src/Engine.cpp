/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Engine.cpp
//
// DESCRIPTION:
//	Implementation for our base Engine object
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Engine.h"

#include <conio.h>

namespace jrs{

void Engine::RegisterTickable(const std::shared_ptr<Tickable> _tickable)
{
	m_Tickables.push_back(_tickable);
}

void Engine::UnregisterTickable(const std::shared_ptr<Tickable> _tickable)
{
	auto it = std::find(m_Tickables.begin(), m_Tickables.end(), _tickable);
	m_Tickables.erase(it);
}

bool Engine::TickFrame()
{
	// ensure engine is fully initialized
	if ( !m_bInitialized )
	{
		Initialize();
	}

	// clear screen each frame
	ClearScreen();
	for ( auto tickable : m_Tickables )
	{
		// TODO: implement precision timer and pass valid delta time values
		tickable->Tick(0.f);
	}

	// TODO: need to support "exit app" signals and shutdown gracefully
	return true;
}

char Engine::GetUserKeyPress()
{
	return _getch();
}

void Engine::ClearScreen()
{
	// TODO: this isn't a good way to clear the screen but would like to eventually replace
	//		 our ascii-based rendering solution with a nice GUI anyway
	system("cls");
}

}