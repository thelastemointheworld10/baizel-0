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

    void iAudioSource::SetPosition(const tVector3f& avPosition)
    {
        mvPosition = avPosition;
    }

    void iAudioSource::SetVelocity(const tVector3f& avVelocity)
    {
        mvVelocity = avVelocity;
    }

    void iAudioSource::SetPitch(float afPitch)
    {
        mfPitch = afPitch;
        mfPitch = cMath::Clamp<float>(mfPitch, 0.0f, 1.0f);
    }

    void iAudioSource::SetGain(float afGain)
    {
        mfGain = afGain;
        mfGain = cMath::Clamp<float>(mfGain, 0.0f, 1.0f);
    }

    void iAudioSource::SetLoop(bool abLoop)
    {
        mbLoop = abLoop;
    }

    void iAudioSource::SetBuffer(uint32_t alAudioBuffer)
    {
        mlAudioBuffer = alAudioBuffer;
    }

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

    uint32_t iAudioSource::GetBuffer() const
    {
        return mlAudioBuffer;
    }

	// -----------------------------------------------------------------------
}