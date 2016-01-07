/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// AbstractFactory.h
//
// DESCRIPTION:
//	This factory singleton is used to instantiate polymorphic objects from their class names
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <map>
#include <memory>

#include "Factory.h"

// this must be called for each class that we want to support instantiation by class name
#define REGISTER_CLASS_FACTORY(Class) AbstractFactory::Instance().RegisterFactory(L#Class, unique_ptr<Factory>(new Class::Class##Factory()));

namespace jrs{

class AbstractFactory
{
public:
	
	//
	// Methods
	//

	// singleton accessor
	static AbstractFactory& Instance()
	{
		static AbstractFactory instance;
		return instance;
	}

	// factory register/unregister
	inline void RegisterFactory(const std::wstring& _class_name, std::unique_ptr<Factory> _factory)
	{ 
		m_Factories[_class_name] = std::unique_ptr<Factory>(std::move(_factory));
	}
	inline void UnregisterFactory(const std::wstring& _class_name)
	{ 
		m_Factories[_class_name] = nullptr;
	}
  
	std::shared_ptr<BaseObject> create(const std::wstring& _class_name)
	{
		if ( m_Factories[_class_name] )
		{ 
			return m_Factories[_class_name]->create(); 
		}
		else
		{ 
			return nullptr; 
		}
	}

private:
	
	//
	// Methods
	//
	AbstractFactory(void) {}
	
	~AbstractFactory(void) {}


	//
	// Members
	//
	std::map< std::wstring, std::unique_ptr<Factory> > m_Factories;
};

}