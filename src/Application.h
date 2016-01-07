/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Application.h
//
// DESCRIPTION:
//	Our core application singleton which manages global access to our polymorphic Engine and our
//  global application configuration.
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <memory>
#include <Windows.h>

namespace jrs{

class Config;
class Engine;

class Application
{
public:
	
	//
	// Methods
	//

	// singleton accessor
	static Application& Instance()
	{
		static Application instance;
		return instance;
	}
	
	inline std::shared_ptr<Config> GetConfig()
	{
		return m_Config;
	}

	inline std::shared_ptr<Engine> GetEngine()
	{
		return m_Engine;
	}
	
	//
	// Application::ConsoleHandlerRoutine
	//
	// DESCRIPTION: 
	// handles console events like exit
	//
	// RETURN:
	// true - application exit with no prompt
	// false - application exit error
	static BOOL WINAPI ConsoleHandlerRoutine(DWORD _type);

	//
	// Application::Initialize
	//
	// DESCRIPTION: 
	// initializes the application based on config settings
	//
	// RETURN:
	// true - application initialized properly
	// false - application initialization failed
	bool Initialize(const std::wstring &_config_path);

	//
	// Application::Run
	//
	// DESCRIPTION: 
	// runs application based on initialization configuration
	//
	// RETURN:
	// int - application error code
	int Run();

private:

	//
	// Methods
	//
	Application();	
	~Application(void);
    Application(Application const&);
    void operator=(Application const&);


	//
	// Members
	//
	std::shared_ptr<Config> m_Config;
	std::shared_ptr<Engine> m_Engine;
	
	//signal when application should close
	static bool m_bCloseApplicationStateFlag; 
};

}
