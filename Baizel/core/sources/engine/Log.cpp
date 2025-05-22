#include <engine/Log.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// GLOBAL FUNCTIONS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	void PrintFormated(std::string asPrefix, const char* asFormat, va_list apArgs)
	{
		va_list pArgsCopy;

		va_copy(pArgsCopy, apArgs);
		int lSize = vsnprintf(nullptr, 0, asFormat, pArgsCopy) + 1; // length of formated string
		va_end(pArgsCopy);

		std::vector<char> vBuffer(lSize);
		vsnprintf(vBuffer.data(), lSize, asFormat, apArgs);

		std::cerr << asPrefix << vBuffer.data() << std::endl;
	}

	void Log(const char* asFormat, ...)
	{
		if (asFormat == nullptr)
			return;

		va_list pArgs;

		va_start(pArgs, asFormat);
		PrintFormated("", asFormat, pArgs);
		va_end(pArgs);
	}

	void Warning(const char* asFormat, ...)
	{
		if (asFormat == nullptr)
			return;

		va_list pArgs;

		va_start(pArgs, asFormat);
		PrintFormated("[WARN] ", asFormat, pArgs);
		va_end(pArgs);
	}

	void Error(const char* asFormat, ...)
	{
		if (asFormat == nullptr)
			return;

		va_list pArgs;

		va_start(pArgs, asFormat);
		PrintFormated("[ERROR] ", asFormat, pArgs);
		va_end(pArgs);
	}

	void Fatal(const char* asFormat, ...)
	{
		if (asFormat == nullptr)
			return;

		va_list pArgs;

		va_start(pArgs, asFormat);
		PrintFormated("[FATAL] ", asFormat, pArgs);
		va_end(pArgs);
	}

	// -----------------------------------------------------------------------
}