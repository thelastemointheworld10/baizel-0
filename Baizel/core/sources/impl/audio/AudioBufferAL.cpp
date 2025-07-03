#include <impl/audio/AudioBufferAL.h>

namespace baizel
{
    //////////////////////////////////////////////////////////////////////////
    // CONSTRUCTORS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    cAudioBufferAL::cAudioBufferAL(iAudioReader* apAudioReader) : iAudioBuffer(apAudioReader)
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
        alCall(alBufferData, mlBufferID, mlFormat, mpAudioFile->GetPCM().data(),
            mpAudioFile->GetPCM().size() * sizeof(short), mpAudioFile->GetRate());
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