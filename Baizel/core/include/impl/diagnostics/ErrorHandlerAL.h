#ifndef BAIZEL_ERRORHANDLERAL_H
#define BAIZEL_ERRORHANDLERAL_H

#include <AL/al.h>
#include <AL/alc.h>

#include <diagnostics/Log.h>

namespace baizel
{
	#define alCall(aFunction, ...) alCallImpl(__FILE__, __LINE__, aFunction, __VA_ARGS__); 
	#define alcCall(aFunction, apDevice, ...) alcCallImpl(__FILE__, __LINE__, apDevice, aFunction, __VA_ARGS__); 

	//////////////////////////////////////////////////////////////////////////
	// GLOBAL FUNCTIONS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// AL
	//////////////////////////////////////////

	inline bool CheckErrorsAL(const char* asFilename, std::uint_fast32_t alLine)
	{
		if (alcGetCurrentContext() == nullptr)
			return true;

		ALenum lError = alGetError();
		if (lError != AL_NO_ERROR)
		{
			std::string sErrorCode;

			switch (lError)
			{
			case AL_INVALID_NAME:
				sErrorCode = "tBad name(ID) was passed to an OpenAL function";
				break;
			case AL_INVALID_ENUM:
				sErrorCode = "Invalid enum value was passed to an OpenAL function";
				break;
			case AL_INVALID_VALUE:
				sErrorCode = "Invalid value was passed to an OpenAL function";
				break;
			case AL_INVALID_OPERATION:
				sErrorCode = "Requested operation is not valid";
				break;
			case AL_OUT_OF_MEMORY:
				sErrorCode = "Requested operation resulted in OpenAL running out of memory";
				break;
			default:
				sErrorCode = "Unknown AL error";
			}
			cLog::Error("OpenAL Soft in file %s on line %d : %s", asFilename, alLine, sErrorCode);

			return false;
		}

		return true;
	}

	template <typename Func, typename... Args>
	auto alCallImpl(const char* asFilename,
		std::uint_fast32_t alLine,
		Func aFunc,
		Args... aArgs) -> typename
		std::enable_if<std::is_same<void, decltype(aFunc(aArgs...))>::value, bool>::type
	{
		aFunc(aArgs...);
		return CheckErrorsAL(asFilename, alLine);
	}

	template <typename Func, typename... Args>
	auto alCallImpl(const char* asFilename,
		std::uint_fast32_t alLine,
		Func aFunc,
		Args... aArgs) -> typename
		std::enable_if<!std::is_same<void, decltype(aFunc(aArgs...))>::value, decltype(aFunc(aArgs...))>::type
	{
		auto Ret = aFunc(aArgs...);
		CheckErrorsAL(asFilename, alLine);
		return Ret;
	}

	//////////////////////////////////////////
	// ALC
	//////////////////////////////////////////

	inline bool CheckErrorsALC(const char* asFilename, std::uint_fast32_t alLine, ALCdevice* apDevice)
	{
		if (apDevice == nullptr)
			return true;

		ALCenum lError = alcGetError(apDevice);
		if (lError != ALC_NO_ERROR)
		{
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

		return true;
	}

	template <typename Func, typename... Args>
	auto alcCallImpl(const char* asFilename,
		std::uint_fast32_t alLine,
		ALCdevice* apDevice,
		Func aFunc,
		Args... aArgs) -> typename
		std::enable_if<std::is_same<void, decltype(aFunc(aArgs...))>::value, bool>::type
	{
		aFunc(aArgs...);
		return CheckErrorsALC(asFilename, alLine, apDevice);
	}

	template <typename Func, typename... Args>
	auto alcCallImpl(const char* asFilename,
		std::uint_fast32_t alLine,
		ALCdevice* apDevice,
		Func aFunc,
		Args... aArgs) -> typename
		std::enable_if<!std::is_same<void, decltype(aFunc(aArgs...))>::value, decltype(aFunc(aArgs...))>::type
	{
		auto Ret = aFunc(aArgs...);
		CheckErrorsALC(asFilename, alLine, apDevice);
		return Ret;
	}

	template <typename Func, typename... Args>
	auto alcCallImpl(const char* asFilename,
		std::uint_fast32_t alLine,
		ALCdevice* apDevice,
		Func aFunc,
		Args... aArgs) -> typename
		std::enable_if<std::is_same<void, decltype(aFunc(apDevice, aArgs...))>::value, bool>::type
	{
		aFunc(apDevice, aArgs...);
		return CheckErrorsALC(asFilename, alLine, apDevice);
	}

	template <typename Func, typename... Args>
	auto alcCallImpl(const char* asFilename,
		std::uint_fast32_t alLine,
		ALCdevice* apDevice,
		Func aFunc,
		Args... aArgs) -> typename
		std::enable_if<!std::is_same<void, decltype(aFunc(apDevice, aArgs...))>::value, decltype(aFunc(apDevice, aArgs...))>::type
	{
		auto Ret = aFunc(apDevice, aArgs...);
		CheckErrorsALC(asFilename, alLine, apDevice);
		return Ret;
	}

	// -----------------------------------------------------------------------
}

#endif // BAIZEL_ERRORHANDLERAL_H