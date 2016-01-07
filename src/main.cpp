// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <sstream>

#include "AbstractFactory.h"
#include "Application.h"
#include "CheckersGameEngine.h"

// default application config that is used if one is not supplied on the command-line
#define DEFAULT_CONFIG_FILE L"checkers.ini"

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace jrs;
	using namespace std;

	// initialize our factory objects for dynamic instantiation
	// TODO: move this initialization to the corresponding .cpp files instead?
	REGISTER_CLASS_FACTORY(CheckersGameEngine);

	// initialize our application based on config (using command-line supplied, or default)
	wstring app_config;
	if ( argc > 1 )
	{
		app_config = argv[1];
	}
	else
	{
		TCHAR cwd[_MAX_PATH] = {0};
		GetCurrentDirectory(_MAX_PATH,cwd);
		wstringstream wss;
		wss << cwd << L"\\" << DEFAULT_CONFIG_FILE;
		app_config = wss.str();
	}

	bool b_success = false;
	b_success = Application::Instance().Initialize(app_config);
	if ( !b_success ) 
	{
		assert(false);
		return 1;
	}

	// run application
	return Application::Instance().Run();
}

