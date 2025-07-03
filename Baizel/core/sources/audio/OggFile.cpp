#include <audio/OggFile.h>

namespace baizel
{
    //////////////////////////////////////////////////////////////////////////
    // CONSTRUCTORS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    iOggFile::iOggFile()
    {
        mvPCMData.reserve(gkPCMLength);
    }

    // -----------------------------------------------------------------------

    //////////////////////////////////////////////////////////////////////////
    // PUBLIC METHODS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------
    
    //////////////////////////////////////////
    // Accessors
    //////////////////////////////////////////

    int iOggFile::GetVersion() const
    {
        return mlVersion;
    }

    int iOggFile::GetChannels() const
    {
        return mlChannels;
    }

    long iOggFile::GetRate() const
    {
        return mlRate;
    }

    long iOggFile::GetBitrateUpper() const
    {
        return mlBitrateUpper;
    }

    long iOggFile::GetBitrateNominal() const
    {
        return mlBitrateNominal;
    }
        
    long iOggFile::GetBitrateLower() const
    {
        return mlBitrateLower;
    }

    long iOggFile::GetBitrateWindow() const
    {
        return mlBitrateWindow;
    }

    const tPCMVec& iOggFile::GetPCM() const
    {
        return mvPCMData;
    }

    // -----------------------------------------------------------------------
}