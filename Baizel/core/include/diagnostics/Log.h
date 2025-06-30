#ifndef BAIZEL_LOG_H
#define BAIZEL_LOG_H

#include <iostream>
#include <stdarg.h>
#include <string>
#include <vector>

namespace baizel
{
	class cLog final
	{
	public:
		//////////////////////////////////////////////////////////////////////////
		// PUBLIC METHODS
		//////////////////////////////////////////////////////////////////////////

		// -----------------------------------------------------------------------

		//////////////////////////////////////////
		// Core Functionality
		//////////////////////////////////////////

		inline static void Log(const char* asFormat, ...)
		{
			if (asFormat == nullptr)
				return;

			va_list pArgs;

			va_start(pArgs, asFormat);
			std::cerr << GetFormatedString(asFormat, pArgs) << std::endl;
			va_end(pArgs);
		}

		inline static void Warning(const char* asFormat, ...)
		{
			if (asFormat == nullptr)
				return;

			va_list pArgs;

			va_start(pArgs, asFormat);
			std::cerr << "[WARNING] " << GetFormatedString(asFormat, pArgs) << std::endl;
			va_end(pArgs);
		}

		inline static void Error(const char* asFormat, ...)
		{
			if (asFormat == nullptr)
				return;

			va_list pArgs;

			va_start(pArgs, asFormat);
			std::cerr << "[ERROR] " << GetFormatedString(asFormat, pArgs) << std::endl;
			va_end(pArgs);
		}

		inline static void Fatal(const char* asFormat, ...)
		{
			if (asFormat == nullptr)
				return;

			va_list pArgs;

			va_start(pArgs, asFormat);
			std::cerr << "[FATAL] " << GetFormatedString(asFormat, pArgs) << std::endl;
			va_end(pArgs);
		}

		//////////////////////////////////////////
		// Accessors
		//////////////////////////////////////////

		inline static std::string GetFormatedString(const char* asFormat, va_list apArgs)
		{
			va_list pArgsCopy;

			va_copy(pArgsCopy, apArgs);
			int lSize = vsnprintf(nullptr, 0, asFormat, pArgsCopy) + 1; // length of formated string
			va_end(pArgsCopy);

			std::vector<char> vBuffer(lSize);
			vsnprintf(vBuffer.data(), lSize, asFormat, apArgs);

			return std::string(vBuffer.begin(), vBuffer.end());
		}

		// -----------------------------------------------------------------------
	};
}

#endif // BAIZEL_LOG_H