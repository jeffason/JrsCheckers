/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Config.cpp
//
// DESCRIPTION:
//	Implementation for our global config manager
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <tchar.h>
#include <Windows.h>

#include "Config.h"

#define MAX_CONFIG_VALUE_SIZE 256
#define MISSING_VALUE TEXT("")

namespace jrs{

std::wstring Config::GetSettingString( const std::wstring &_section_name, const std::wstring &_var_name)
{
	TCHAR read_buffer[MAX_CONFIG_VALUE_SIZE] = {0};
	GetPrivateProfileString (_section_name.c_str(), 
		_var_name.c_str(), 
		MISSING_VALUE, 
		read_buffer, 
		sizeof(read_buffer), 
		m_ConfigPath.c_str());

	return read_buffer;
}

int Config::GetSettingInt( const std::wstring &_section_name, const std::wstring &_var_name )
{
	return _wtoi( GetSettingString(_section_name, _var_name).c_str() );
}

wchar_t Config::GetSettingChar( const std::wstring &_section_name, const std::wstring &_var_name )
{
	return GetSettingString( _section_name, _var_name )[0];
}

}