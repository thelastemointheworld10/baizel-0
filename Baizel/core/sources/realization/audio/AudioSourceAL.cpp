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
    // Accessors
    //////////////////////////////////////////

    void cAudioSourceAL::SetPosition(const tVector3f& avPosition)
    {
        mvPosition = avPosition;
        alCall(alSource3f, mlSourceID, AL_POSITION, mvPosition.x, mvPosition.y, mvPosition.z);
    }

    void cAudioSourceAL::SetVelocity(const tVector3f& avVelocity)
    {
        mvVelocity = avVelocity;
        alCall(alSource3f, mlSourceID, AL_VELOCITY, mvVelocity.x, mvVelocity.y, mvVelocity.z);
    }

    void cAudioSourceAL::SetPitch(float afPitch)
    {
        mfPitch = afPitch;
        mfPitch = cMath::Clamp(mfPitch, 0.0f, 1.0f);
        alCall(alSourcef, mlSourceID, AL_PITCH, mfPitch);
    }

    void cAudioSourceAL::SetGain(float afGain)
    {
        mfGain = afGain;
        mfGain = cMath::Clamp(mfGain, 0.0f, 1.0f);
        alCall(alSourcef, mlSourceID, AL_GAIN, mfGain);
    }

    void cAudioSourceAL::SetLoop(bool abLoop)
    {
        mbLoop = abLoop;
        alCall(alSourcei, mlSourceID, AL_LOOPING, mbLoop ? AL_TRUE : AL_FALSE);
    }

    void cAudioSourceAL::SetBufferID(uint32_t alAudioBuffer)
    {
        mlAudioBufferID = alAudioBuffer;
        alCall(alSourcei, mlSourceID, AL_BUFFER, mlAudioBufferID);
    }

    //////////////////////////////////////////
    // Runtime Control
    //////////////////////////////////////////

    void cAudioSourceAL::Play() const
    {
        alCall(alSourcePlay, mlSourceID);
    }

    void cAudioSourceAL::Stop() const
    {
        alCall(alSourceStop, mlSourceID);
    }

    void cAudioSourceAL::Pause() const
    {
        alCall(alSourcePause, mlSourceID);
    }

    // -----------------------------------------------------------------------
}