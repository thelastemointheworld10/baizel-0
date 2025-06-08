#include <audio/AudioSource.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

    const tVector3f& iAudioSource::GetPosition() const
    {
        return mvPosition;
    }

    const tVector3f& iAudioSource::GetVelocity() const
    {
        return mvVelocity;
    }

    float iAudioSource::GetPitch() const
    {
        return mfPitch;
    }

    float iAudioSource::GetGain() const
    {
        return mfGain;
    }

    bool iAudioSource::GetLoop() const
    {
        return mbLoop;
    }

    uint32_t iAudioSource::GetBufferID() const
    {
        return mlAudioBufferID;
    }

	// -----------------------------------------------------------------------
}