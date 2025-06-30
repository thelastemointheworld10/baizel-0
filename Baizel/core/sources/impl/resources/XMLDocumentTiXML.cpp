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

	void cXMLDocumentTiXML::SaveFile(const std::string& asPath)
	{
		cLog::Log("Saving XML Document '%s'", asPath.c_str());

		const tNodeList& lstChildren = GetChildren();
		tNodeListIt it = lstChildren.begin();
		for (; it != lstChildren.end(); ++it)
		{
			mDocument.InsertEndChild(ConvertTinyXMLData((*it)->ToElement()));
		}

		XMLError lResult = mDocument.SaveFile(asPath.c_str());
		XMLCheckResult(lResult);
	}

	void cXMLDocumentTiXML::LoadFile(const std::string& asPath)
	{
		cLog::Log("Loading XML Document '%s'", asPath.c_str());

		XMLError lResult = mDocument.LoadFile(asPath.c_str());
		XMLCheckResult(lResult);
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	XMLElement* cXMLDocumentTiXML::ConvertTinyXMLData(cXMLElement* apSource)
	{
		XMLElement* pDest = mDocument.NewElement(apSource->GetName().c_str());
		pDest->SetText(apSource->GetValueString().c_str());
		
		InsertAttributes(apSource, pDest);
		InsertChildren(apSource, pDest);

		return pDest;
	}

	void cXMLDocumentTiXML::InsertAttributes(cXMLElement* apSource, XMLElement* apDest) const
	{
		const tAttributesMap& mapAttributes = apSource->GetAttributesMap();
		tAttributesMapIt it = mapAttributes.begin();
		for (; it != mapAttributes.end(); ++it)
		{
			apDest->SetAttribute(it->first.c_str(), it->second.c_str());
		}
	}

	void cXMLDocumentTiXML::InsertChildren(cXMLNode* apSource, XMLElement* apDest)
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
			apDest->InsertEndChild(ConvertTinyXMLData((*it)->ToElement()));
		}
	}

	// -----------------------------------------------------------------------
}