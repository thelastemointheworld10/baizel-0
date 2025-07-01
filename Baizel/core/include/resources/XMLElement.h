#ifndef BAIZEL_XMLELEMENT_H
#define BAIZEL_XMLELEMENT_H

#include <map>

#include <resources/XMLNode.h>

namespace baizel
{
	using tAttributesMap = std::map<std::string, std::string>;
	using tAttributesMapIt = tAttributesMap::const_iterator;

	class cXMLElement final : public cXMLNode
	{
	public:
		cXMLElement(const std::string& asName, cXMLNode* apParent);

		void SetAttributeString(const std::string& asName, const std::string& asValue);
		void SetAttributeInt(const std::string& asName, int alValue);
		void SetAttributeFloat(const std::string& asName, float afValue);
		void SetAttributeDouble(const std::string& asName, double afValue);
		void SetAttributeBool(const std::string& asName, bool abValue);

		const std::string& GetAttributeString(const std::string& asName, const std::string& asDefault = " ");
		int GetAttributeInt(const std::string& asName, int alDefault = 0);
		float GetAttributeFloat(const std::string& asName, float afDefault = 0.0f);
		double GetAttributeDouble(const std::string& asName, double afDefault = 0.0);
		bool GetAttributeBool(const std::string& asName, bool abDefault = false);

		void SetAttributesMap(const tAttributesMap& aAttributesMap);
		const tAttributesMap& GetAttributesMap() const;

		void SetName(const std::string& asName);
		const std::string& GetName() const;

	private:
		void SetAttribute(const std::string& asName, const std::string& asValue);
		const std::string& GetAttribute(const std::string& asName);

	private:
		tAttributesMap mmapAttributes = tAttributesMap();
		std::string msName = "";
	};
}

#endif // BAIZEL_XMLELEMENT_H