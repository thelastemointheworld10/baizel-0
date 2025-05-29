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
			PrintFormated("", asFormat, pArgs);
			va_end(pArgs);
		}

		inline static void Warning(const char* asFormat, ...)
		{
			if (asFormat == nullptr)
				return;

			va_list pArgs;

			va_start(pArgs, asFormat);
			PrintFormated("[WARNING] ", asFormat, pArgs);
			va_end(pArgs);
		}

		inline static void Error(const char* asFormat, ...)
		{
			if (asFormat == nullptr)
				return;

			va_list pArgs;

			va_start(pArgs, asFormat);
			PrintFormated("[ERROR] ", asFormat, pArgs);
			va_end(pArgs);
		}

		inline static void Fatal(const char* asFormat, ...)
		{
			if (asFormat == nullptr)
				return;

			va_list pArgs;

			va_start(pArgs, asFormat);
			PrintFormated("[FATAL] ", asFormat, pArgs);
			va_end(pArgs);
		}

		// -----------------------------------------------------------------------

	private:
		//////////////////////////////////////////////////////////////////////////
		// PRIVATE METHODS
		//////////////////////////////////////////////////////////////////////////

		// -----------------------------------------------------------------------

		//////////////////////////////////////////
		// Core Functionality
		//////////////////////////////////////////

		inline static void PrintFormated(std::string asPrefix, const char* asFormat, va_list apArgs)
		{
			va_list pArgsCopy;

			va_copy(pArgsCopy, apArgs);
			int lSize = vsnprintf(nullptr, 0, asFormat, pArgsCopy) + 1; // length of formated string
			va_end(pArgsCopy);

			std::vector<char> vBuffer(lSize);
			vsnprintf(vBuffer.data(), lSize, asFormat, apArgs);

			std::cerr << asPrefix << vBuffer.data() << std::endl;
		}

		// -----------------------------------------------------------------------
	};
}

#endif // BAIZEL_LOG_H