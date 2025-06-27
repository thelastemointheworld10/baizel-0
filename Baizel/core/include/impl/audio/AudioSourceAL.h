#ifndef BAIZEL_AUDIOSOURCEAL_H
#define BAIZEL_AUDIOSOURCEAL_H

#include <impl/audio/ErrorHandlerAL.h>

#include <audio/AudioSource.h>

namespace baizel
{
    class cAudioSourceAL final : public iAudioSource
    {
    public:
        cAudioSourceAL();

        void SetPosition(const tVector3f& avPosition) override;
        void SetPosition(tVector2f avPosition) override;
        void SetVelocity(const tVector3f& avVelocity) override;
        void SetVelocity(tVector2f avVelocity) override;

        void SetPitch(float afPitch) override;
        void SetGain(float afGain) override;
        void SetLoop(bool abLoop) override;

        void SetRelative(bool abRelative) override;

        void SetMinDistance(float afDistance) override;
        void SetMaxDistance(float afDistance) override;
        void SetRolloffFactor(float afRolloff) override;

        void SetBuffer(iAudioBuffer* apAudioBuffer) override;

        void Play() const override;
        void Stop() const override;
        void Pause() const override;
    };
}

#endif // BAIZEL_AUDIOSOURCEAL_H