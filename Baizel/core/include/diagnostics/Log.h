#ifndef BAIZEL_LOG_H
#define BAIZEL_LOG_H

#include <iostream>
#include <stdarg.h>
#include <fstream>
#include <string>
#include <vector>

namespace baizel
{
	class cLog final
	{
	public:
		static void SetOutFile(const std::string& asPath);
		static void CloseFile();

		static void Log(const std::string& asFormat, ...);
		static void Warning(const std::string& asFormat, ...);
		static void Error(const std::string& asFormat, ...);

		static std::string GetFormatedString(const std::string& asFormat, va_list apArgs);

	private:
		static std::ofstream sOut;
	};
}

#endif // BAIZEL_LOG_H