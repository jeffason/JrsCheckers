/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Logger.cpp
//
// DESCRIPTION:
//	Implementation for our Logger
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Logger.h"

#include <stdarg.h>

namespace jrs{

void Logger::WriteLine(const wchar_t *_format, ...)
{
	va_list argptr;
    va_start(argptr, _format);
	vfwprintf(stdout, _format, argptr);
    va_end(argptr);
	wprintf(L"\n\n");
}

}