#ifndef BAIZEL_LOG_H
#define BAIZEL_LOG_H

#include <iostream>
#include <stdarg.h>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

namespace baizel
{
	class cLog final
	{
	public:
		static void SetOutFile(const std::string& asPath, char alSeparator = '/');
		static void CloseFile();

		static void Log(const std::string& asFormat, ...);
		static void Warning(const std::string& asFormat, ...);
		static void Error(const std::string& asFormat, ...);
		static void LogToFile(const std::string& asFormat, ...);
		static void WarningToFile(const std::string& asFormat, ...);
		static void ErrorToFile(const std::string& asFormat, ...);

		static std::string GetFormatedString(const std::string& asFormat, va_list apArgs);
		static const std::string& GetLastLog();

	private:
		static bool CreateDirectories(const std::string& asPath, char alSeparator = '/');
		static void OpenFile(const std::string& asPath);

	private:
		static std::ofstream sOut;
		static std::string ssLastLog;
	};
}

#endif // BAIZEL_LOG_H