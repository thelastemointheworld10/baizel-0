#ifndef BAIZEL_UTF8CONVERTER_H
#define BAIZEL_UTF8CONVERTER_H

#include <unordered_map>
#include <cstdint>

#include <diagnostics/Log.h>

namespace baizel
{
	using tComplianceMap = std::unordered_map<std::uint8_t, std::uint8_t>;
	using tComplianceMapIt = tComplianceMap::const_iterator;

	class cUtf8Converter final
	{
	public:
		static std::uint8_t Convert(std::uint8_t alChar);
		static std::string ConvertString(const std::string& asString);

	protected:
		static tComplianceMap smapComplianceTable;
	};
}

#endif // BAIZEL_UTF8CONVERTER_H