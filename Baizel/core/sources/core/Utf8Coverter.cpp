#include <core/Utf8Convetrer.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	std::uint8_t cUtf8Converter::Convert(std::uint8_t alChar)
	{
		std::uint8_t lCharCode = static_cast<std::uint8_t>(alChar);
		
		if (alChar < 128)
			return alChar;

		tComplianceMapIt it = smapComplianceTable.find(lCharCode);
		if (it == smapComplianceTable.end())
		{
			//cLog::Log("Char with code %d does not exist in compilance map", lCharCode);
			return static_cast<std::uint8_t>('?');
		}

		//cLog::Log("convert result: %c - %d", static_cast<char>(alChar), alChar);
		return it->second;
	}

	std::string cUtf8Converter::ConvertString(const std::string& asString)
	{
		std::string sResult = "";
		for (char lChar : asString)
		{
			sResult += static_cast<char>(Convert(lChar));
		}

		return sResult;
	}

	// -----------------------------------------------------------------------

	tComplianceMap cUtf8Converter::smapComplianceTable = tComplianceMap
	{
		{192, 0x0410}, {193, 0x0411}, {194, 0x0412}, {195, 0x0413}, // ����
		{196, 0x0414}, {197, 0x0415}, {168, 0x0401}, {198, 0x0416}, // �Ũ�
		{199, 0x0417}, {200, 0x0418}, {201, 0x0419}, {202, 0x041A}, // ����
		{203, 0x041B}, {204, 0x041C}, {205, 0x041D}, {206, 0x041E}, // ����
		{207, 0x041F}, {208, 0x0420}, {209, 0x0421}, {210, 0x0422}, // ����
		{211, 0x0423}, {212, 0x0424}, {213, 0x0425}, {214, 0x0426}, // ����
		{215, 0x0427}, {216, 0x0428}, {217, 0x0429}, {218, 0x042A}, // ����
		{219, 0x042B}, {220, 0x042C}, {221, 0x042D}, {222, 0x042E}, // ����
		{223, 0x042F},                                              // �

		{224, 0x0430}, {225, 0x0431}, {226, 0x0432}, {227, 0x0433}, // ����
		{228, 0x0434}, {229, 0x0435}, {184, 0x0451}, {230, 0x0436}, // ���
		{231, 0x0437}, {232, 0x0438}, {233, 0x0439}, {234, 0x043A}, // ����
		{235, 0x043B}, {236, 0x043C}, {237, 0x043D}, {238, 0x043E}, // ����
		{239, 0x043F}, {240, 0x0440}, {241, 0x0441}, {242, 0x0442}, // ����
		{243, 0x0443}, {244, 0x0444}, {245, 0x0445}, {246, 0x0446}, // ����
		{247, 0x0447}, {248, 0x0448}, {249, 0x0449}, {250, 0x044A}, // ����
		{251, 0x044B}, {252, 0x044C}, {253, 0x044D}, {254, 0x044E}, // ����
		{255, 0x044F}                                               // �
	};
}
