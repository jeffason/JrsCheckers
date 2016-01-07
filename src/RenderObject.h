/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// RenderObject.h
//
// DESCRIPTION:
//	Abstract base class for objects that need a render call each frame
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "tickable.h"
#include "BaseObject.h"

namespace jrs{

class RenderObject : public Tickable, public BaseObject
{
public:
	
	//
	// Methods
	//

	RenderObject(void) {}
	virtual ~RenderObject(void) {}

	virtual void Tick( float _delta_time )
	{
		Render();
	}

	virtual void Render() = 0;
};

}