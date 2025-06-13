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

        SetPosition(mvPosition);
        SetVelocity(mvVelocity);

        SetPitch(mfPitch);
        SetGain(mfGain);
        SetLoop(mbLoop);

        SetRelative(mbRelative);

        SetMinDistance(mfMinDistance);
        SetMaxDistance(mfMaxDistance);
        SetRolloffFactor(mfRolloffFactor);
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

    void cAudioSourceAL::SetPosition(const tVector2f& avPosition)
    {
        mvPosition = tVector3f(avPosition.x, avPosition.y, 0.0f);
        alCall(alSource3f, mlSourceID, AL_POSITION, mvPosition.x, mvPosition.y, mvPosition.z);
    }

    void cAudioSourceAL::SetVelocity(const tVector3f& avVelocity)
    {
        mvVelocity = avVelocity;
        alCall(alSource3f, mlSourceID, AL_VELOCITY, mvVelocity.x, mvVelocity.y, mvVelocity.z);
    }

    void cAudioSourceAL::SetVelocity(const tVector2f& avVelocity)
    {
        mvVelocity = tVector3f(avVelocity.x, avVelocity.y, 0.0f);
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

    void cAudioSourceAL::SetRelative(bool abRelative)
    {
        mbRelative = abRelative;
        alCall(alSourcei, mlSourceID, AL_SOURCE_RELATIVE, mbRelative ? AL_TRUE : AL_FALSE);
    }

    void cAudioSourceAL::SetMinDistance(float afDistance)
    {
        mfMinDistance = afDistance;
        alCall(alSourcef, mlSourceID, AL_REFERENCE_DISTANCE, mfMinDistance);
    }

    void cAudioSourceAL::SetMaxDistance(float afDistance)
    {
        mfMaxDistance = afDistance;
        alCall(alSourcef, mlSourceID, AL_MAX_DISTANCE, mfMaxDistance);
    }

    void cAudioSourceAL::SetRolloffFactor(float afRolloff)
    {
        mfRolloffFactor = afRolloff;
        alCall(alSourcef, mlSourceID, AL_ROLLOFF_FACTOR, mfRolloffFactor);
    }

    void cAudioSourceAL::SetBuffer(iAudioBuffer* apAudioBuffer)
    {
        mpAudioBuffer = apAudioBuffer;
        alCall(alSourcei, mlSourceID, AL_BUFFER, mpAudioBuffer->GetID());
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