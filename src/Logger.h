/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Logger.h
//
// DESCRIPTION:
//	Global logger helper class to write text to various output streams
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>

#define LOG_MESSAGE(s, ...) Logger::Instance().WriteLine(s, __VA_ARGS__);

namespace jrs{

class Logger
{
public:
	
	//
	// Methods
	//

	// singleton accessor
	static Logger& Instance()
	{
		static Logger instance;
		return instance;
	}

	void WriteLine(const wchar_t *_format, ...);

private:
	
	//
	// Methods
	//
	Logger(void) { }
	~Logger(void) { }	
    Logger(Logger const&);
    void operator=(Logger const&);
};

}