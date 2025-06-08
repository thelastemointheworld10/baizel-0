#include <realization/audio/AudioBufferAL.h>

namespace baizel
{
    //////////////////////////////////////////////////////////////////////////
    // CONSTRUCTORS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    cAudioBufferAL::cAudioBufferAL()
    {
        alCall(alGenBuffers, 1, &mlBufferID);
    }

    cAudioBufferAL::~cAudioBufferAL()
    {
        alCall(alDeleteBuffers, 1, &mlBufferID);
    }

    // -----------------------------------------------------------------------

    //////////////////////////////////////////////////////////////////////////
    // PROTECTED METHODS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    //////////////////////////////////////////
    // Accessors
    //////////////////////////////////////////

    void cAudioBufferAL::SetData()
    {
        alCall(alBufferData, mlBufferID, mlFormat, mvPCMData.data(), 
             mvPCMData.size() * sizeof(uint16_t), mlSampleRate);
    }

    void cAudioBufferAL::SetFormat(int alChannels)
    {
        switch (alChannels)
        {
        case 1:
            mlFormat = AL_FORMAT_MONO16;
            break;
        case 2:
            mlFormat = AL_FORMAT_STEREO16;
            break;
        default:
            cLog::Error("Unsupported Audio Format");
            mlFormat = 0;
            break;
        }
    }

    // -----------------------------------------------------------------------
}