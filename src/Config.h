/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Config.h
//
// DESCRIPTION:
//	Our config manager to manage access to our global application configuration
//
// jrs051413 - created
//
// TODO: 
// * add support for dynamic class var config bindings
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>

#include "Application.h"

#define GConfig Application::Instance().GetConfig()

namespace jrs {

class Config
{
public:

	//
	// Methods
	//
	Config(const std::wstring &_config_path) : m_ConfigPath(_config_path)
	{
	}

	virtual ~Config(void) { }
	
	std::wstring GetSettingString( const std::wstring &_section_name, const std::wstring &_var_name );
	int GetSettingInt( const std::wstring &_section_name, const std::wstring &_var_name );
	wchar_t GetSettingChar( const std::wstring &_section_name, const std::wstring &_var_name );

private:
	std::wstring m_ConfigPath;
};

}