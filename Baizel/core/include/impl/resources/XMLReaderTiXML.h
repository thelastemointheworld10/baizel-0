#ifndef BAIZEL_XMLREADERTIXML_H
#define BAIZEL_XMLREADERTIXML_H

#include <resources/XMLReader.h>
#include <impl/resources/XMLDocumentTiXML.h>

namespace baizel
{
	class cXMLReaderTiXML final : public iXMLReader
	{
	public:
		iXMLDocument* CreateDocument() const override;
	};
}

#endif // BAIZEL_XMLREADERTIXML_H