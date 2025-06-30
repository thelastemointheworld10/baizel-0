#ifndef BAIZEL_XMLDOCUMENT_H
#define BAIZEL_XMLDOCUMENT_H

#include <diagnostics/Log.h>
#include <resources/XMLNode.h>

namespace baizel
{
    class iXMLDocument : public cXMLNode
    {
    public:
        iXMLDocument();

        virtual void SaveFile(const std::string& asPath) = 0;
        virtual void LoadFile(const std::string& asPath) = 0;

    protected:
        std::string msPath = "";
    };
}

#endif // BAIZEL_XMLDOCUMENT_H