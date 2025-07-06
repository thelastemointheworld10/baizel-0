#include <impl/resources/XMLDocumentTiXML.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Resource Management
	//////////////////////////////////////////

	bool cXMLDocumentTiXML::SaveFile(const std::string& asPath)
	{
		InsertTinyXMLChildren();

		if (mDocument.SaveFile(asPath.c_str()) != XML_SUCCESS)
		{
			cLog::Error("Failed to save XML document! Name: %s Desc: %s",
				mDocument.ErrorName() , mDocument.ErrorStr());

			return false;
		}

		cLog::Log("XML document saved '%s'", asPath.c_str());

		return true;
	}

	bool cXMLDocumentTiXML::LoadFile(const std::string& asPath)
	{
		if (mDocument.LoadFile(asPath.c_str()) != XML_SUCCESS)
		{
			cLog::Error("Failed to load XML document! Name: %s Desc: %s",
				mDocument.ErrorName(), mDocument.ErrorStr());
		
			return false;
		}

		cLog::Log("XML document loaded '%s'", asPath.c_str());
		InsertXMLChildren();

		return true;
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	void cXMLDocumentTiXML::InsertTinyXMLChildren()
	{
		const tNodeList& lstChildren = GetChildren();
		tNodeListIt it = lstChildren.begin();
		for (; it != lstChildren.end(); ++it)
		{
			mDocument.InsertEndChild(CreateTiXMLElement((*it)->ToElement()));
		}
	}

	void cXMLDocumentTiXML::InsertXMLChildren()
	{
		const XMLElement* pChild = mDocument.FirstChildElement();

		while (pChild != nullptr)
		{
			mlstChildren.push_back(CreateXMLElement(nullptr, pChild));
			pChild = pChild->NextSiblingElement();
		}
	}

	XMLElement* cXMLDocumentTiXML::CreateTiXMLElement(cXMLElement* apSource)
	{
		XMLElement* pDest = mDocument.NewElement(apSource->GetName().c_str());
		pDest->SetText(apSource->GetValueString().c_str());
		
		InsertAttributesTiXML(apSource, pDest);
		InsertChildrenTiXML(apSource, pDest);

		return pDest;
	}

	cXMLElement* cXMLDocumentTiXML::CreateXMLElement(cXMLElement* apParent, const XMLElement* apSource)
	{
		cXMLElement* pDest = new cXMLElement(apSource->Name(), apParent);

		InsertChildrenXML(apSource, pDest);
		InsertAttributesXML(apSource, pDest);

		const char* sText = apSource->GetText();
		if (sText)
			pDest->SetValueString(sText);

		return pDest;
	}

	void cXMLDocumentTiXML::InsertAttributesTiXML(cXMLElement* apSource, XMLElement* apDest) const
	{
		const tAttributesMap& mapAttributes = apSource->GetAttributesMap();
		tAttributesMapIt it = mapAttributes.begin();
		for (; it != mapAttributes.end(); ++it)
		{
			cLog::Log("Found attribute: %s = '%s'",
				it->first,
				it->second);
			apDest->SetAttribute(it->first.c_str(), it->second.c_str());
		}
	}

	void cXMLDocumentTiXML::InsertChildrenTiXML(cXMLNode* apSource, XMLNode* apDest)
	{
		const tNodeList& lstChildren = apSource->GetChildren();
		tNodeListIt it = lstChildren.begin();

		if (!lstChildren.empty())
		{
			// for more beautiful output
			apDest->InsertEndChild(mDocument.NewText("\n    "));
		}

		for (; it != lstChildren.end(); ++it)
		{
			apDest->InsertEndChild(CreateTiXMLElement((*it)->ToElement()));
		}
	}

	void cXMLDocumentTiXML::InsertAttributesXML(const XMLElement* apSource, cXMLElement* apDest)
	{
		const XMLAttribute* pAttr = apSource->FirstAttribute();
		while (pAttr != nullptr)
		{
			//cLog::Log("XML Attribute found: %s='%s'",
			//	pAttr->Name(),
			//	pAttr->Value());

			apDest->SetAttributeString(pAttr->Name(), pAttr->Value());
			pAttr = pAttr->Next();
		}
	}

	void cXMLDocumentTiXML::InsertChildrenXML(const XMLElement* apSource, cXMLElement* apDest)
	{
		const XMLElement* pChild = apSource->FirstChildElement();
		while (pChild != nullptr)
		{
			apDest->AddChild(CreateXMLElement(apDest, pChild));
			pChild = pChild->NextSiblingElement();
		}
	}

	// -----------------------------------------------------------------------
}