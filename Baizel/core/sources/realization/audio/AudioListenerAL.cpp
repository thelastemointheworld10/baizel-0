#include <realization/audio/AudioListenerAL.h>

namespace baizel
{
    //////////////////////////////////////////////////////////////////////////
    // PUBLIC METHODS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    //////////////////////////////////////////
    // Resource Management
    //////////////////////////////////////////

    void cAudioListenerAL::SetPosition(const tVector3f& avPosition)
    {
        mvPosition = avPosition;
        alCall(alListener3f, AL_POSITION, mvPosition.x, mvPosition.y, mvPosition.z);
    }

    void cAudioListenerAL::SetPosition(const tVector2f& avPosition)
    {
        mvPosition = tVector3f(avPosition.x, avPosition.y, 0.0f);
        alCall(alListener3f, AL_POSITION, mvPosition.x, mvPosition.y, mvPosition.z);
    }

    void cAudioListenerAL::SetVelocity(const tVector3f& avVelocity)
    {
        mvVelocity = avVelocity;
        alCall(alListener3f, AL_VELOCITY, mvVelocity.x, mvVelocity.y, mvVelocity.z);
    }

    void cAudioListenerAL::SetVelocity(const tVector2f& avVelocity)
    {
        mvVelocity = tVector3f(avVelocity.x, avVelocity.y, 0.0f);
        alCall(alListener3f, AL_VELOCITY, mvVelocity.x, mvVelocity.y, mvVelocity.z);
    }

    void cAudioListenerAL::SetOrientation(const tVector3f& avUp, const tVector3f& avForward)
    {
        mvUp = avUp;
        mvForward = avForward;

        // up && forward vectors
        ALfloat fOrientation[6] = { mvUp.x, mvUp.y, mvUp.z, mvForward.x, mvForward.y, mvForward.z};
        alCall(alListenerfv, AL_ORIENTATION, fOrientation);
    }

    void cAudioListenerAL::SetMasterGain(float afGain)
    {
        mfMasterGain = afGain;
        mfMasterGain = cMath::Clamp(mfMasterGain, 0.0f, 1.0f);
        alCall(alListenerf, AL_GAIN, mfMasterGain);
    }

    // -----------------------------------------------------------------------
}