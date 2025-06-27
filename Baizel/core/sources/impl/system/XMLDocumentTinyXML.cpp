#include <impl/system/XMLDocumentTinyXML.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Resource Management
	//////////////////////////////////////////

	void cXMLDocumentTinyXML::LoadFile(const std::string& asFileName)
	{
		cLog::Log("Loading XML Document: %s", asFileName.c_str());

		XMLError eResult = mDocument.LoadFile(asFileName.c_str());
		XMLCheckResult(eResult);
	}

	void cXMLDocumentTinyXML::SaveFile(const std::string& asFileName)
	{
		cLog::Log("Saving XML Document: %s", asFileName.c_str());

		XMLError eResult = mDocument.SaveFile(asFileName.c_str());
		XMLCheckResult(eResult);
	}

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	void cXMLDocumentTinyXML::InsertFirst(iXMLElement* apElement)
	{
		cXMLElementTinyXML* pElementTinyXML = dynamic_cast<cXMLElementTinyXML*>(apElement);
		mDocument.InsertFirstChild(pElementTinyXML->GetElement());
	}

	void cXMLDocumentTinyXML::InsertEnd(iXMLElement* apElement)
	{
		cXMLElementTinyXML* pElementTinyXML = dynamic_cast<cXMLElementTinyXML*>(apElement);
		mDocument.InsertEndChild(pElementTinyXML->GetElement());
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	XMLDocument& cXMLDocumentTinyXML::GetDocument()
	{
		return mDocument;
	}

	// -----------------------------------------------------------------------
}