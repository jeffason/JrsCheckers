/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Engine.h
//
// DESCRIPTION:
//	Base engine class used to drive various types of applications
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <list>

#include "Application.h"
#include "Factory.h"
#include "Tickable.h"

#define GEngine Application::Instance().GetEngine()

namespace jrs{

class Engine : public BaseObject
{
public:
	// declare factory for dynamic instantiation by class name via AbstractFactory
	DECLARE_DEFAULT_FACTORY(Engine);

	Engine(void) : m_bInitialized(false) { }
	virtual ~Engine(void) { }

	void RegisterTickable(const std::shared_ptr<Tickable> _tickable);
	void UnregisterTickable(const std::shared_ptr<Tickable> _tickable);

	//
	// Engine::TickFrame
	//
	// DESCRIPTION: 
	// processes one full frame tick for the engine
	//
	// RETURN:
	// true - engine has more work to do
	// false - engine is finished running
	virtual bool TickFrame();
	virtual void Initialize() 
	{ 
		m_bInitialized =  true;
	}

	char GetUserKeyPress();
	virtual void ClearScreen();

private:
	std::list< std::shared_ptr<Tickable> > m_Tickables;
	bool m_bInitialized;
};

}