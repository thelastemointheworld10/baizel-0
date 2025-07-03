#include <impl/audio/OggFileLibVorbis.h>

namespace baizel
{
    //////////////////////////////////////////////////////////////////////////
    // CONSTRUCTORS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    cOggFileLibVorbis::~cOggFileLibVorbis()
    {
        //delete mpInfo;
        //mpInfo = nullptr;
    }

    // -----------------------------------------------------------------------

    //////////////////////////////////////////////////////////////////////////
    // PUBLIC METHODS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    //////////////////////////////////////////
    // Resource Management
    //////////////////////////////////////////

    bool cOggFileLibVorbis::LoadFile(const std::string& asPath)
    {
        OggVorbis_File Vorbis;
        vorbis_info* pInfo = nullptr;

        if (ov_fopen(asPath.c_str(), &Vorbis) < 0)
        {
            cLog::Error("Failed to load ogg file '%s'", asPath.c_str());
            return false;
        }

        cLog::Log("Ogg file '%s' has been loaded", asPath.c_str());

        AssignInfo(Vorbis, pInfo);
        ReadPCM(Vorbis);

        ov_clear(&Vorbis);

        return true;
    }

    // -----------------------------------------------------------------------

    //////////////////////////////////////////////////////////////////////////
    // PROTECTED METHODS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------
    
    //////////////////////////////////////////
    // Core Functionality
    //////////////////////////////////////////

    void cOggFileLibVorbis::ReadPCM(OggVorbis_File& aVorbis)
    {
        mvPCMData.clear();
        std::vector<short> vTempBuffer(gkPCMLength);

        while (true)
        {
            int lSection = 0;
            long lBytes = ov_read(&aVorbis, (char*)vTempBuffer.data(), gkPCMLength * sizeof(short), 0, 2, 1, &lSection);

            if (lBytes <= 0) break;
            
            size_t lSamplesRead = lBytes / sizeof(short);
            mvPCMData.insert(mvPCMData.end(),
                vTempBuffer.begin(),
                vTempBuffer.begin() + lSamplesRead);
        }
    }

    void cOggFileLibVorbis::AssignInfo(OggVorbis_File& aVorbis, vorbis_info* apInfo)
    {
        apInfo = ov_info(&aVorbis, -1);

        mlVersion = apInfo->version;
        mlChannels = apInfo->channels;
        mlRate = apInfo->rate;

        mlBitrateUpper = apInfo->bitrate_upper;
        mlBitrateNominal = apInfo->bitrate_nominal;
        mlBitrateLower = apInfo->bitrate_lower;
        mlBitrateWindow = apInfo->bitrate_window;

        cLog::Log("Ogg info: version: %d channels: %d, bitrate_upper: %d, bitrate_nominal: %d, bitrate_lower: %d, bitrate_window: %d, rate: %d",
            mlVersion, mlChannels, mlBitrateUpper, mlBitrateNominal, mlBitrateLower, mlBitrateWindow, mlRate);
    }
    
    // -----------------------------------------------------------------------
}