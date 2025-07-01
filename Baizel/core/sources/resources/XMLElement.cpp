#include <resources/XMLElement.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cXMLElement::cXMLElement(const std::string& asName, cXMLNode* apParent) : cXMLNode(apParent)
	{
		msName = asName;
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	void cXMLElement::SetAttributeString(const std::string& asName, const std::string& asValue)
	{
		mmapAttributes[asName] = asValue;
	}

	void cXMLElement::SetAttributeInt(const std::string& asName, int alValue)
	{
		mmapAttributes[asName] = std::to_string(alValue);
	}

	void cXMLElement::SetAttributeFloat(const std::string& asName, float afValue)
	{
		mmapAttributes[asName] = std::to_string(afValue);
	}

	void cXMLElement::SetAttributeDouble(const std::string& asName, double afValue)
	{
		mmapAttributes[asName] = std::to_string(afValue);
	}

	void cXMLElement::SetAttributeBool(const std::string& asName, bool abValue)
	{
		mmapAttributes[asName] = abValue ? "true" : "false";
	}

	const std::string& cXMLElement::GetAttributeString(const std::string& asName, const std::string& asDefault)
	{
		std::string sValue = GetAttribute(asName);

		if (sValue.empty() == false)
			return sValue;
		else
			return asDefault;
	}

	int cXMLElement::GetAttributeInt(const std::string& asName, int alDefault)
	{
		std::string sValue = GetAttribute(asName);

		if (sValue.empty() == false)
			return std::stoi(sValue);
		else
			return alDefault;
	}

	float cXMLElement::GetAttributeFloat(const std::string& asName, float afDefault)
	{
		std::string sValue = GetAttribute(asName);

		if (sValue.empty() == false)
			return std::stof(sValue);
		else
			return afDefault;
	}

	double cXMLElement::GetAttributeDouble(const std::string& asName, double afDefault)
	{
		std::string sValue = GetAttribute(asName);

		if (sValue.empty() == false)
			return std::stod(sValue);
		else
			return afDefault;
	}

	bool cXMLElement::GetAttributeBool(const std::string& asName, bool abDefault)
	{
		std::string sValue = GetAttribute(asName);

		if (sValue.empty() == false)
			return sValue == "true";
		else
			return abDefault;
	}

	void cXMLElement::SetAttributesMap(const tAttributesMap& aAttributesMap)
	{
		mmapAttributes = aAttributesMap;
	}

	const tAttributesMap& cXMLElement::GetAttributesMap() const
	{
		return mmapAttributes;
	}

	void cXMLElement::SetName(const std::string& asName)
	{
		msName = asName;
	}

	const std::string& cXMLElement::GetName() const
	{
		return msName;
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	void cXMLElement::SetAttribute(const std::string& asName, const std::string& asValue)
	{
		mmapAttributes[asName] = asValue;
	}

	const std::string& cXMLElement::GetAttribute(const std::string& asName)
	{
		tAttributesMapIt it = mmapAttributes.find(asName);
		if (it != mmapAttributes.end()) // found
		{
			return it->second;
		}
		else // not found
		{
			static const std::string skEmptyString = "";
			return skEmptyString;
		}
	}

	// -----------------------------------------------------------------------
}