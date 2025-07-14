#include <diagnostics/Log.h>

namespace baizel
{
	std::ofstream cLog::sOut{};
	std::string cLog::ssLastLog{};

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Resource Management
	//////////////////////////////////////////

	void cLog::SetOutFile(const std::string& asPath, char alSeparator)
	{
		if (CreateDirectories(asPath, alSeparator))
			OpenFile(asPath);

		Log("Log file created: %s", asPath);
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

		ssLastLog = GetFormatedString(asFormat.c_str(), pArgs);
		std::cerr << ssLastLog << std::endl;

		va_end(pArgs);
	}

	void cLog::Warning(const std::string& asFormat, ...)
	{
		if (asFormat.c_str() == nullptr)
			return;

		va_list pArgs;
		va_start(pArgs, asFormat.c_str());

		ssLastLog = "[WARNING] " + GetFormatedString(asFormat.c_str(), pArgs);
		std::cerr << ssLastLog << std::endl;

		va_end(pArgs);
	}

	void cLog::Error(const std::string& asFormat, ...)
	{
		if (asFormat.c_str() == nullptr)
			return;

		va_list pArgs;
		va_start(pArgs, asFormat.c_str());

		ssLastLog = "[ERROR] " + GetFormatedString(asFormat.c_str(), pArgs);
		std::cerr << ssLastLog << std::endl;

		va_end(pArgs);
	}

	void cLog::LogToFile(const std::string& asFormat, ...)
	{
		Log(asFormat);
		sOut << ssLastLog << std::endl;
	}

	void cLog::WarningToFile(const std::string& asFormat, ...)
	{
		Warning(asFormat);
		sOut << ssLastLog << std::endl;
	}

	void cLog::ErrorToFile(const std::string& asFormat, ...)
	{
		Error(asFormat);
		sOut << ssLastLog << std::endl;
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

	const std::string& cLog::GetLastLog()
	{
		return ssLastLog;
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Resource Management
	//////////////////////////////////////////

	bool cLog::CreateDirectories(const std::string& asPath, char alSeparator)
	{
		std::filesystem::path Dir = asPath.substr(0, asPath.find_last_of(alSeparator));
		if (std::filesystem::exists(Dir) == false)
		{
			Warning("Log path '%s' does not exists! Trying to create it", asPath);

			if (std::filesystem::create_directories(Dir) == false)
			{
				Error("Failed to create log directories: %s", Dir.string());
				return false;
			}
		}

		return true;
	}

	void cLog::OpenFile(const std::string& asPath)
	{
		sOut.open(asPath);
		if (sOut.is_open() == false)
			Error("Failed to open log file %s", asPath);
	}

	// -----------------------------------------------------------------------
}