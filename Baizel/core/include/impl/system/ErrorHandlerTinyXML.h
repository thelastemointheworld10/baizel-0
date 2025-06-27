#ifndef BAIZEL_ERRORHANDLERTINYXML_H
#define BAIZEL_ERRORHANDLERTINYXML_H

#include <tinyxml/tinyxml2.h>

#include <engine/Log.h>

using namespace tinyxml2;

namespace baizel
{
	#define XMLCheckResult(alResult) XMLCheckResultImpl(__FILE__, __LINE__, alResult);

	//////////////////////////////////////////////////////////////////////////
	// GLOBAL FUNCTIONS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	inline bool XMLCheckResultImpl(const char* asFile, std::uint_fast32_t alLine, XMLError alResult)
    {
        if (alResult != XML_SUCCESS)
        {
            cLog::Error("TinyXML (%s : %d)", asFile, alLine);
            cLog::Log("\t%s", tinyxml2::XMLDocument::ErrorIDToName(alResult));

            return false;
        }

        return true;
    }
	
	// -----------------------------------------------------------------------
}

#endif // BAIZEL_ERRORHANDLERTINYXML_H