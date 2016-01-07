/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Tickable.h
//
// DESCRIPTION:
//	Abstract base class for objects that require a Tick() call each frame.  Registration is handled
//	automatically with the Application's Engine.
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace jrs{

class Tickable
{
public:
	Tickable(void);
	virtual ~Tickable(void);

	virtual void Tick( float _delta ) = 0;
};

}