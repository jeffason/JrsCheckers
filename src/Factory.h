/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Factory.h
//
// DESCRIPTION:
//	Abstract Factory base to provide create method for dynamic instantiation by class name
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>

#include "BaseObject.h"

// declares inner class for default factory object creation
#define DECLARE_DEFAULT_FACTORY(Class) class Class##Factory : public Factory \
{ \
public: \
   Class##Factory(){} \
   virtual ~Class##Factory(){} \
   std::shared_ptr<BaseObject> create(){ return std::shared_ptr<BaseObject>(std::static_pointer_cast<Class>(std::make_shared<Class>())); } \
}

namespace jrs{

class Factory
{
public:
	Factory(void) {}
	virtual ~Factory(void) {}

   //override in concrete factory
   virtual std::shared_ptr<BaseObject> create() = 0;
};

}