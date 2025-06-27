#include <impl/system/XMLReaderTinyXML.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Resource Management
	//////////////////////////////////////////

	iXMLDocument* cXMLReaderTinyXML::CreateDocument() const
	{
		return new cXMLDocumentTinyXML();
	}

	iXMLElement* cXMLReaderTinyXML::CreateElement(iXMLDocument* apDocument) const
	{
		return new cXMLElementTinyXML(apDocument);
	}

	// -----------------------------------------------------------------------
}