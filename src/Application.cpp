/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Application.cpp
//
// DESCRIPTION:
//	Implementation for our singleton global Application
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Application.h"
#include "AbstractFactory.h"
#include "Config.h"
#include "Engine.h"
#include "Logger.h"

namespace jrs{

// static initialization
bool Application::m_bCloseApplicationStateFlag = false;

Application::Application()
{
	m_Config = nullptr;
	m_Engine = nullptr;
}
	
Application::~Application(void)
{
	// smart pointers are automatically cleaned up
}

//
// Application::Initialize
//
// DESCRIPTION: 
// initializes the application based on config settings
//
// RETURN:
// true - application initialized properly
// false - application initialization failed
BOOL WINAPI Application::ConsoleHandlerRoutine(DWORD _type)
{
    if (_type == CTRL_CLOSE_EVENT)
    {
		m_bCloseApplicationStateFlag = true;
        return TRUE;
    }

    return FALSE;
}

//
// Application::Initialize
//
// DESCRIPTION: 
// initializes the application based on config settings
//
// RETURN:
// true - application initialized properly
// false - application initialization failed
bool Application::Initialize( const std::wstring &_config_path )
{
	using namespace std;

	// initialize our global config manager
	LOG_MESSAGE(L"Initializing application using config: \"%ls\"", _config_path.c_str());
	m_Config = make_shared<Config>(_config_path);
	
	// initialize the appropriate concrete engine based on config settings
	wstring engine_class_name = m_Config->GetSettingString(L"Application", L"EngineClassName");
	LOG_MESSAGE(L"Creating engine with class name: \"%ls\"", engine_class_name.c_str());
	m_Engine = std::dynamic_pointer_cast<Engine>(AbstractFactory::Instance().create(engine_class_name));

	// register for console close events
	SetConsoleCtrlHandler(Application::ConsoleHandlerRoutine, TRUE);

	// return false if we failed to create a valid config or engine
	return m_Config != nullptr && m_Engine != nullptr;
}

//
// Application::Run
//
// DESCRIPTION: 
// runs application based on initialization configuration
//
// RETURN:
// int - application error code
int Application::Run()
{
	// tick engine until it's finished
	while ( m_Engine && m_Engine->TickFrame() && !m_bCloseApplicationStateFlag ) 
	{
	}
	
	return 0; // success
}

}