#include <realization/audio/AudioSourceAL.h>

namespace baizel
{
    //////////////////////////////////////////////////////////////////////////
    // CONSTRUCTORS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    cAudioSourceAL::cAudioSourceAL()
    {
        alCall(alGenSources, 1, &mlSourceID);
    }

    // -----------------------------------------------------------------------

    //////////////////////////////////////////////////////////////////////////
    // PUBLIC METHODS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    //////////////////////////////////////////
    // Runtime Control
    //////////////////////////////////////////

    void cAudioSourceAL::Play() const
    {
        UpdateValues();

        alCall(alSourcePlay, mlSourceID);
    }

    // -----------------------------------------------------------------------

    //////////////////////////////////////////////////////////////////////////
    // PROTECTED METHODS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    //////////////////////////////////////////
    // Runtime Control
    //////////////////////////////////////////

    void cAudioSourceAL::UpdateValues() const
    {
        alCall(alSourcef, mlSourceID, AL_PITCH, mfPitch);
        alCall(alSourcef, mlSourceID, AL_GAIN, mfGain);
        alCall(alSource3f, mlSourceID, AL_POSITION, mvPosition.x, mvPosition.y, mvPosition.z);
        alCall(alSource3f, mlSourceID, AL_VELOCITY, mvVelocity.x, mvVelocity.y, mvVelocity.z);
        alCall(alSourcei, mlSourceID, AL_LOOPING, mbLoop ? AL_TRUE : AL_FALSE);
        alCall(alSourcei, mlSourceID, AL_BUFFER, mlAudioBuffer);
    }

    // -----------------------------------------------------------------------
}