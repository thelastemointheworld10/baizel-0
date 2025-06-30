#ifndef BAIZEL_XMLDOCUMENTTIXML_H
#define BAIZEL_XMLDOCUMENTTIXML_H

#include <tinyxml/tinyxml2.h>

#include <impl/diagnostics/ErrorHandlerTiXML.h>
#include <resources/XMLDocument.h>
#include <resources/XMLElement.h>

using namespace tinyxml2;

namespace baizel
{
    class cXMLDocumentTiXML final : public iXMLDocument
    {
    public:
        void SaveFile(const std::string& asPath) override;
        void LoadFile(const std::string& asPath) override;

    private:
        XMLElement* ConvertTinyXMLData(cXMLElement* apSource);

        void InsertAttributes(cXMLElement* apSource, XMLElement* apDest) const;
        void InsertChildren(cXMLNode* apSource, XMLElement* apDest);

    private:
        tinyxml2::XMLDocument mDocument;
    };
}

#endif // BAIZEL_XMLDOCUMENTTIXML_H