#ifndef BAIZEL_AUDIOSOURCEAL_H
#define BAIZEL_AUDIOSOURCEAL_H

#include <realization/audio/ErrorHandlerAL.h>

#include <audio/AudioSource.h>

namespace baizel
{
    class cAudioSourceAL final : public iAudioSource
    {
    public:
        cAudioSourceAL();

        void SetPosition(const tVector3f& avPosition) override;
        void SetVelocity(const tVector3f& avVelocity) override;
        void SetPitch(float afPitch) override;
        void SetGain(float afGain) override;
        void SetLoop(bool abLoop) override;
        void SetBufferID(uint32_t alAudioBuffer) override;

        void Play() const override;
    };
}

#endif // BAIZEL_AUDIOSOURCEAL_H