#include <diagnostics/Log.h>

namespace baizel
{
	std::ofstream cLog::sOut;

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Resource Management
	//////////////////////////////////////////

	void cLog::SetOutFile(const std::string& asPath)
	{
		sOut.open(asPath, std::ios::out | std::ios::trunc);
		if (sOut.is_open())
		{
			Log("Log file %s opened", asPath);
		}
		else
		{
			Error("Failed to open log file %s", asPath);
		}
	}

	void cLog::CloseFile()
	{
		sOut.close();
	}
	
	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	void cLog::Log(const std::string& asFormat, ...)
	{
		if (asFormat.c_str() == nullptr)
			return;

		va_list pArgs;

		va_start(pArgs, asFormat.c_str());

		std::string sMessage = GetFormatedString(asFormat.c_str(), pArgs);
		std::cerr << sMessage << std::endl;
		if (sOut.is_open())
			sOut << sMessage << std::endl;

		va_end(pArgs);
	}

	void cLog::Warning(const std::string& asFormat, ...)
	{
		if (asFormat.c_str() == nullptr)
			return;

		va_list pArgs;

		va_start(pArgs, asFormat.c_str());

		std::string sMessage = "[WARNING] " + GetFormatedString(asFormat.c_str(), pArgs);
		std::cerr << sMessage << std::endl;
		if (sOut.is_open())
			sOut << sMessage << std::endl;

		va_end(pArgs);
	}

	void cLog::Error(const std::string& asFormat, ...)
	{
		if (asFormat.c_str() == nullptr)
			return;

		va_list pArgs;

		va_start(pArgs, asFormat.c_str());

		std::string sMessage = "[ERROR] " + GetFormatedString(asFormat.c_str(), pArgs);
		std::cerr << sMessage << std::endl;
		if (sOut.is_open())
			sOut << sMessage << std::endl;

		va_end(pArgs);
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	std::string cLog::GetFormatedString(const std::string& asFormat, va_list apArgs)
	{
		va_list pArgsCopy;

		va_copy(pArgsCopy, apArgs);
		int lSize = vsnprintf(nullptr, 0, asFormat.c_str(), pArgsCopy) + 1; // length of the formated string
		va_end(pArgsCopy);

		if (lSize <= 0) return "";

		std::vector<char> vBuffer(lSize);
		vsnprintf(vBuffer.data(), lSize, asFormat.c_str(), apArgs);

		return std::string(vBuffer.begin(), vBuffer.end() - 1);
	}

	// -----------------------------------------------------------------------
}