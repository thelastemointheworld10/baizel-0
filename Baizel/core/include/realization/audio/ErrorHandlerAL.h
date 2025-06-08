#ifndef BAIZEL_ERRORHANDLERAL_H
#define BAIZEL_ERRORHANDLERAL_H

#include <AL/al.h>
#include <AL/alc.h>

#include <engine/Log.h>

namespace baizel
{
	#define alCall(aFunction, ...) alCallImpl(__FILE__, __LINE__, aFunction, __VA_ARGS__); 
	#define alcCall(aFunction, apDevice, ...) alcCallImpl(__FILE__, __LINE__, apDevice, aFunction, __VA_ARGS__); 

	bool CheckErrorsAL(const char* asFilename, std::uint_fast32_t alLine);
	bool CheckErrorsALC(const char* asFilename, std::uint_fast32_t alLine, ALCdevice* apDevice);

	//////////////////////////////////////////
	// AL
	//////////////////////////////////////////

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
}

#endif // BAIZEL_ERRORHANDLERAL_H