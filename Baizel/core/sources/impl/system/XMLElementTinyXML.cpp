#include <impl/system/XMLElementTinyXML.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cXMLElementTinyXML::cXMLElementTinyXML(iXMLDocument* apDocument)
	{
		cXMLDocumentTinyXML* pTinyXMLDoc = dynamic_cast<cXMLDocumentTinyXML*>(apDocument);
		mpDocument = &pTinyXMLDoc->GetDocument();
	}

	cXMLElementTinyXML::~cXMLElementTinyXML()
	{
		if (mpDocument != nullptr && mpElement != nullptr)
			mpDocument->DeleteNode(mpElement);
		if (mpDocument != nullptr && mpRoot != nullptr)
			mpDocument->DeleteNode(mpRoot);
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	void cXMLElementTinyXML::SetName(const std::string& asElement)
	{
		mpElement = mpDocument->NewElement(asElement.c_str());
	}

	XMLElement* cXMLElementTinyXML::GetElement()
	{
		return mpElement;
	}

	////////////////////////
	// Values
	////////////////////////

	void cXMLElementTinyXML::SetValue(const std::string& asValue) const
	{
		mpElement->SetText(asValue.c_str());
	}

	void cXMLElementTinyXML::SetValue(int alValue) const
	{
		mpElement->SetText(alValue);
	}

	void cXMLElementTinyXML::SetValue(unsigned int alValue) const
	{
		mpElement->SetText(alValue);
	}

	void cXMLElementTinyXML::SetValue(int64_t alValue) const
	{
		mpElement->SetText(alValue);
	}

	void cXMLElementTinyXML::SetValue(uint64_t alValue) const
	{
		mpElement->SetText(alValue);
	}

	void cXMLElementTinyXML::SetValue(float afValue) const
	{
		mpElement->SetText(afValue);
	}

	void cXMLElementTinyXML::SetValue(double afValue) const
	{
		mpElement->SetText(afValue);
	}

	void cXMLElementTinyXML::SetValue(bool abValue) const
	{
		mpElement->SetText(abValue);
	}

	std::string cXMLElementTinyXML::GetStrValue()
	{
		const char* sOut = mpElement->GetText();
		if (sOut == nullptr)
		{
			cLog::Error("Failed to get text from element!");
			return "error";
		}
		else
		{
			return std::string(sOut);
		}
	}

	int cXMLElementTinyXML::GetIntValue()
	{
		int lOut = 0;
		XMLError lResult = mpElement->QueryIntText(&lOut);
		XMLCheckResult(lResult);

		return lOut;
	}

	unsigned int cXMLElementTinyXML::GetUintValue()
	{
		unsigned int lOut = 0;
		XMLError lResult = mpElement->QueryUnsignedText(&lOut);
		XMLCheckResult(lResult);

		return lOut;
	}

	int64_t cXMLElementTinyXML::GetInt64Value()
	{
		int64_t lOut = 0;
		XMLError lResult = mpElement->QueryInt64Text(&lOut);
		XMLCheckResult(lResult);

		return lOut;
	}

	uint64_t cXMLElementTinyXML::GetUint64Value()
	{
		uint64_t lOut = 0;
		XMLError lResult = mpElement->QueryUnsigned64Text(&lOut);
		XMLCheckResult(lResult);

		return lOut;
	}

	float cXMLElementTinyXML::GetFloatValue()
	{
		float fOut = 0.0f;
		XMLError lResult = mpElement->QueryFloatText(&fOut);
		XMLCheckResult(lResult);

		return fOut;
	}

	double cXMLElementTinyXML::GetDoubleValue()
	{
		double fOut = 0.0;
		XMLError lResult = mpElement->QueryDoubleText(&fOut);
		XMLCheckResult(lResult);

		return fOut;
	}

	bool cXMLElementTinyXML::GetBoolValue()
	{
		bool bOut = false;
		XMLError lResult = mpElement->QueryBoolText(&bOut);
		XMLCheckResult(lResult);

		return bOut;
	}

	////////////////////////
	// Attributes
	////////////////////////

	void cXMLElementTinyXML::SetAttribute(const std::string& asName, const std::string& asValue) const
	{
		mpElement->SetAttribute(asName.c_str(), asValue.c_str());
	}

	void cXMLElementTinyXML::SetAttribute(const std::string& asName, int alValue) const
	{
		mpElement->SetAttribute(asName.c_str(), alValue);
	}

	void cXMLElementTinyXML::SetAttribute(const std::string& asName, unsigned int alValue) const
	{
		mpElement->SetAttribute(asName.c_str(), alValue);
	}

	void cXMLElementTinyXML::SetAttribute(const std::string& asName, int64_t alValue) const
	{
		mpElement->SetAttribute(asName.c_str(), alValue);
	}

	void cXMLElementTinyXML::SetAttribute(const std::string& asName, uint64_t alValue) const
	{
		mpElement->SetAttribute(asName.c_str(), alValue);
	}

	void cXMLElementTinyXML::SetAttribute(const std::string& asName, float afValue) const
	{
		mpElement->SetAttribute(asName.c_str(), afValue);
	}

	void cXMLElementTinyXML::SetAttribute(const std::string& asName, double afValue) const
	{
		mpElement->SetAttribute(asName.c_str(), afValue);
	}

	void cXMLElementTinyXML::SetAttribute(const std::string& asName, bool abValue) const
	{
		mpElement->SetAttribute(asName.c_str(), abValue);
	}

	std::string cXMLElementTinyXML::GetStrAttribute(const std::string& asName)
	{
		const char* sOut = mpElement->Attribute(asName.c_str());
		if (sOut == nullptr)
		{
			cLog::Error("Failed to get text from element!");
			return "error";
		}
		else
		{
			return std::string(sOut);
		}
	}

	int cXMLElementTinyXML::GetIntAttribute(const std::string& asName)
	{
		int lOut = 0;
		XMLError lResult = mpElement->QueryIntAttribute(asName .c_str(), &lOut);
		XMLCheckResult(lResult);

		return lOut;
	}

	unsigned int cXMLElementTinyXML::GetUintAttribute(const std::string& asName)
	{
		unsigned int lOut = 0;
		XMLError lResult = mpElement->QueryUnsignedAttribute(asName.c_str(), &lOut);
		XMLCheckResult(lResult);

		return lOut;
	}

	int64_t cXMLElementTinyXML::GetInt64Attribute(const std::string& asName)
	{
		int64_t lOut = 0;
		XMLError lResult = mpElement->QueryInt64Attribute(asName.c_str(), &lOut);
		XMLCheckResult(lResult);

		return lOut;
	}

	uint64_t cXMLElementTinyXML::GetUint64Attribute(const std::string& asName)
	{
		uint64_t lOut = 0;
		XMLError lResult = mpElement->QueryUnsigned64Attribute(asName.c_str(), &lOut);
		XMLCheckResult(lResult);

		return lOut;
	}

	float cXMLElementTinyXML::GetFloatAttribute(const std::string& asName)
	{
		float fOut = 0.0f;
		XMLError lResult = mpElement->QueryFloatAttribute(asName.c_str(), &fOut);
		XMLCheckResult(lResult);

		return fOut;
	}

	double cXMLElementTinyXML::GetDoubleAttribute(const std::string& asName)
	{
		double fOut = 0.0;
		XMLError lResult = mpElement->QueryDoubleAttribute(asName.c_str(), &fOut);
		XMLCheckResult(lResult);

		return fOut;
	}

	bool cXMLElementTinyXML::GetBoolAttribute(const std::string& asName)
	{
		bool bOut = false;
		XMLError lResult = mpElement->QueryBoolAttribute(asName.c_str(), &bOut);
		XMLCheckResult(lResult);

		return bOut;
	}

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	void cXMLElementTinyXML::InsertFirst(iXMLElement* apElement) const
	{
		cXMLElementTinyXML* pElementTinyXML = dynamic_cast<cXMLElementTinyXML*>(apElement);
		mpElement->InsertFirstChild(pElementTinyXML->GetElement());
	}

	void cXMLElementTinyXML::InsertEnd(iXMLElement* apElement) const
	{
		cXMLElementTinyXML* pElementTinyXML = dynamic_cast<cXMLElementTinyXML*>(apElement);
		mpElement->InsertEndChild(pElementTinyXML->GetElement());
	}

	void cXMLElementTinyXML::Find(const std::string& asName)
	{
		if (mpRoot == nullptr)
			FindRoot();

		mpElement = mpRoot->FirstChildElement(asName.c_str());
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PROTECTED METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	void cXMLElementTinyXML::FindRoot()
	{
		mpRoot = mpDocument->FirstChild();
	}

	// -----------------------------------------------------------------------
}