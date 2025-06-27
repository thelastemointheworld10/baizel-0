#ifndef BAIZEL_XMLREADER_H
#define BAIZEL_XMLREADER_H

#include <system/XMLDocument.h>
#include <system/XMLElement.h>

namespace baizel
{
    class iXMLReader
    {
    public:
        virtual iXMLDocument* CreateDocument() const = 0;
        virtual iXMLElement* CreateElement(iXMLDocument* apDocument) const = 0;
    };
}

#endif // BAIZEL_XMLREADER_H