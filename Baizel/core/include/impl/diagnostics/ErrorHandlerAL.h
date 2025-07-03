#ifndef BAIZEL_ERRORHANDLERAL_H
#define BAIZEL_ERRORHANDLERAL_H

#include <AL/al.h>
#include <AL/alc.h>

#include <diagnostics/Log.h>

namespace baizel
{
	#define alCall(aFunction, ...) cErrorHandlerAL::alCallImpl(__FILE__, __LINE__, aFunction, __VA_ARGS__); 
	#define alcCall(aFunction, apDevice, ...) cErrorHandlerAL::alcCallImpl(__FILE__, __LINE__, apDevice, aFunction, __VA_ARGS__); 

	class cErrorHandlerAL final
	{
	public:
		template <typename Func, typename... Args>
		static auto alCallImpl(const char* asFilename,
			std::uint_fast32_t alLine,
			Func aFunc,
			Args... aArgs) -> typename
			std::enable_if<std::is_same_v<void, decltype(aFunc(aArgs...))>, bool>::type
		{
			aFunc(aArgs...);
			return CheckErrorsAL(asFilename, alLine);
		}

		template <typename Func, typename... Args>
		static auto alCallImpl(const char* asFilename,
			std::uint_fast32_t alLine,
			Func aFunc,
			Args... aArgs) -> typename
			std::enable_if<!std::is_same_v<void, decltype(aFunc(aArgs...))>, decltype(aFunc(aArgs...))>::type
		{
			auto Ret = aFunc(aArgs...);
			CheckErrorsAL(asFilename, alLine);
			return Ret;
		}

		template <typename Func, typename... Args>
		static auto alcCallImpl(const char* asFilename,
			std::uint_fast32_t alLine,
			ALCdevice* apDevice,
			Func aFunc,
			Args... aArgs) -> typename
			std::enable_if<std::is_same_v<void, decltype(aFunc(aArgs...))>, bool>::type
		{
			aFunc(aArgs...);
			return CheckErrorsALC(asFilename, alLine, apDevice);
		}

		template <typename Func, typename... Args>
		static auto alcCallImpl(const char* asFilename,
			std::uint_fast32_t alLine,
			ALCdevice* apDevice,
			Func aFunc,
			Args... aArgs) -> typename
			std::enable_if<!std::is_same_v<void, decltype(aFunc(aArgs...))>, decltype(aFunc(aArgs...))>::type
		{
			auto Ret = aFunc(aArgs...);
			CheckErrorsALC(asFilename, alLine, apDevice);
			return Ret;
		}

		template <typename Func, typename... Args>
		static auto alcCallImpl(const char* asFilename,
			std::uint_fast32_t alLine,
			ALCdevice* apDevice,
			Func aFunc,
			Args... aArgs) -> typename
			std::enable_if<std::is_same_v<void, decltype(aFunc(apDevice, aArgs...))>, bool>::type
		{
			aFunc(apDevice, aArgs...);
			return CheckErrorsALC(asFilename, alLine, apDevice);
		}

		template <typename Func, typename... Args>
		static auto alcCallImpl(const char* asFilename,
			std::uint_fast32_t alLine,
			ALCdevice* apDevice,
			Func aFunc,
			Args... aArgs) -> typename
			std::enable_if<!std::is_same_v<void, decltype(aFunc(apDevice, aArgs...))>, decltype(aFunc(apDevice, aArgs...))>::type
		{
			auto Ret = aFunc(apDevice, aArgs...);
			CheckErrorsALC(asFilename, alLine, apDevice);
			return Ret;
		}

	private:
		static bool CheckErrorsAL(const char* asFilename, std::uint_fast32_t alLine);
		static bool CheckErrorsALC(const char* asFilename, std::uint_fast32_t alLine, ALCdevice* apDevice);
	};
}

#endif // BAIZEL_ERRORHANDLERAL_H