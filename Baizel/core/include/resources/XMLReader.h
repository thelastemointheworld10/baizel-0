#ifndef BAIZEL_XMLREADER_H
#define BAIZEL_XMLREADER_H

#include <resources/XMLDocument.h>

namespace baizel
{
	class iXMLReader
	{
	public:
		virtual iXMLDocument* CreateDocument() const = 0;
	};
}

#endif // BAIZEL_XMLREADER_H