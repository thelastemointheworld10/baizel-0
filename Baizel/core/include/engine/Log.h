#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <stdarg.h>
#include <string>
#include <vector>

namespace baizel
{
	void PrintFormated(std::string asPrefix, const char* asFormat, va_list apArgs);

	void Log(const char* asFormat, ...);
	void Warning(const char* asFormat, ...);
	void Error(const char* asFormat, ...);
	void Fatal(const char* asFormat, ...);
}

#endif // LOG_H