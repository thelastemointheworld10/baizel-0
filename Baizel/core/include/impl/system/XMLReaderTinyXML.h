#ifndef BAIZEL_XMLREADERTINYXML_H
#define BAIZEL_XMLREADERTINYXML_H

#include <system/XMLReader.h>

#include <impl/system/XMLDocumentTinyXML.h>
#include <impl/system/XMLElementTinyXML.h>

namespace baizel
{
    class cXMLReaderTinyXML final : public iXMLReader
    {
    public:
        iXMLDocument* CreateDocument() const override;
        iXMLElement* CreateElement(iXMLDocument* apDocument) const override;
    };
}

#endif // BAIZEL_XMLREADERTINYXML_H