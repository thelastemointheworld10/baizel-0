#ifndef BAIZEL_XMLDOCUMENTTIXML_H
#define BAIZEL_XMLDOCUMENTTIXML_H

#include <tinyxml/tinyxml2.h>

#include <resources/XMLDocument.h>
#include <resources/XMLElement.h>

using namespace tinyxml2;

namespace baizel
{
    class cXMLDocumentTiXML final : public iXMLDocument
    {
    public:
        bool SaveFile(const std::string& asPath) override;
        bool LoadFile(const std::string& asPath) override;

    private:
        XMLElement* CreateTiXMLElement(cXMLElement* apSource);
        cXMLElement* CreateXMLElement(cXMLElement* apParent, const XMLElement* apSource);

        void InsertTinyXMLChildren();
        void InsertXMLChildren();

        void InsertAttributesTiXML(cXMLElement* apSource, XMLElement* apDest) const;
        void InsertChildrenTiXML(cXMLNode* apSource, XMLNode* apDest);
        void InsertAttributesXML(const XMLElement* apSource, cXMLElement* apDest);
        void InsertChildrenXML(const XMLElement* apSource, cXMLElement* apDest);

    private:
        tinyxml2::XMLDocument mDocument;
    };
}

#endif // BAIZEL_XMLDOCUMENTTIXML_H