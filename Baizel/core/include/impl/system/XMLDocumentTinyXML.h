#ifndef BAIZEL_XMLDOCUMENTTINYXML_H
#define BAIZEL_XMLDOCUMENTTINYXML_H

#include <tinyxml/tinyxml2.h>

#include <system/XMLDocument.h>
#include <impl/system/XMLElementTinyXML.h>

#include <impl/system/ErrorHandlerTinyXML.h>

namespace baizel
{
    class cXMLDocumentTinyXML final : public iXMLDocument
    {
    public:
        void LoadFile(const std::string& asFileName) override;
        void SaveFile(const std::string& asFileName) override;

        void InsertFirst(iXMLElement* apElement) override;
        void InsertEnd(iXMLElement* apElement) override;

        tinyxml2::XMLDocument& GetDocument();

    private:
        tinyxml2::XMLDocument mDocument;
    };
}

#endif // BAIZEL_XMLDOCUMENTTINYXML_H