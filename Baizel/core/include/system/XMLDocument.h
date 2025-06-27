#ifndef BAIZEL_XMLDOCUMENT_H
#define BAIZEL_XMLDOCUMENT_H

#include <string>

namespace baizel
{
    class iXMLElement;

    class iXMLDocument
    {
    public:
        virtual void LoadFile(const std::string& asFileName) = 0;
        virtual void SaveFile(const std::string& asFileName) = 0;

        virtual void InsertFirst(iXMLElement* apElement) = 0;
        virtual void InsertEnd(iXMLElement* apElement) = 0;
    };
}

#endif // BAIZEL_XMLDOCUMENT_H