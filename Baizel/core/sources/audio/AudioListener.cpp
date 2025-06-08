#include <audio/AudioListener.h>

namespace baizel
{
    //////////////////////////////////////////////////////////////////////////
    // PUBLIC METHODS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    //////////////////////////////////////////
    // Accessors
    //////////////////////////////////////////

    const tVector3f& iAudioListener::GetPosition() const
    {
        return mvPosition;
    }

    const tVector3f& iAudioListener::GetVelocity() const
    {
        return mvVelocity;
    }

    const tVector3f& iAudioListener::GetForward() const
    {
        return mvForward;
    }

    const tVector3f& iAudioListener::GetUp() const
    {
        return mvUp;
    }

    float iAudioListener::GetMasterGain() const
    {
        return mfMasterGain;
    }

    // -----------------------------------------------------------------------
}