#include <impl/diagnostics/ErrorHandlerAL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	bool cErrorHandlerAL::CheckErrorsAL(const char* asFilename, std::uint_fast32_t alLine)
	{
		if (alcGetCurrentContext() == nullptr)
			return false;

		ALenum lError = alGetError();
		if (lError == AL_NO_ERROR)
			return true;

		std::string sErrorCode;
		switch (lError)
		{
		case AL_INVALID_NAME:
			sErrorCode = "bad name(ID) was passed to an OpenAL function";
			break;
		case AL_INVALID_ENUM:
			sErrorCode = "invalid enum value was passed to an OpenAL function";
			break;
		case AL_INVALID_VALUE:
			sErrorCode = "invalid value was passed to an OpenAL function";
			break;
		case AL_INVALID_OPERATION:
			sErrorCode = "requested operation is not valid";
			break;
		case AL_OUT_OF_MEMORY:
			sErrorCode = "requested operation resulted in OpenAL running out of memory";
			break;
		default:
			sErrorCode = "unknown AL error";
		}
		cLog::Error("OpenAL Soft in file %s on line %d : %s", asFilename, alLine, sErrorCode);

		return false;
	}

	bool cErrorHandlerAL::CheckErrorsALC(const char* asFilename, std::uint_fast32_t alLine, ALCdevice* apDevice)
	{
		if (apDevice == nullptr)
			return false;

		ALCenum lError = alcGetError(apDevice);
		if (lError == ALC_NO_ERROR)
			return true;

		std::string sErrorCode;
		switch (lError)
		{
		case ALC_INVALID_VALUE:
			sErrorCode = "Invalid value was passed to an OpenAL function";
			break;
		case ALC_INVALID_DEVICE:
			sErrorCode = "Bad device was passed to an OpenAL function";
			break;
		case ALC_INVALID_CONTEXT:
			sErrorCode = "Bad context was passed to an OpenAL function";
			break;
		case ALC_INVALID_ENUM:
			sErrorCode = "Unknown enum value was passed to an OpenAL function";
			break;
		case ALC_OUT_OF_MEMORY:
			sErrorCode = "Unknown enum value was passed to an OpenAL function";
			break;
		default:
			sErrorCode = "Unknown ALC error";
		}
		cLog::Error("OpenAL Soft in file %s on line %d : %s", asFilename, alLine, sErrorCode);

		return false;
	}

	// -----------------------------------------------------------------------
}