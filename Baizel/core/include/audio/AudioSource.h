#ifndef BAIZEL_AUDIOSOURCE_H
#define BAIZEL_AUDIOSOURCE_H

#include <math/Math.h>
#include <math/MathTypes.h>

#include <audio/AudioBuffer.h>

namespace baizel
{
    class iAudioSource
    {
    public:
        virtual void SetPosition(const tVector3f& avPosition) = 0;
        virtual void SetVelocity(const tVector3f& avVelocity) = 0;
        virtual void SetPitch(float afPitch) = 0;
        virtual void SetGain(float afGain) = 0;
        virtual void SetLoop(bool abLoop) = 0;
        virtual void SetBufferID(uint32_t alAudioBufferID) = 0;

        const tVector3f& GetPosition() const;
        const tVector3f& GetVelocity() const;
        float GetPitch() const;
        float GetGain() const;
        bool GetLoop() const;
        uint32_t GetBufferID() const;

        virtual void Play() const = 0;
        virtual void Stop() const = 0;
        virtual void Pause() const = 0;

    protected:
        uint32_t mlSourceID = 0;

        tVector3f mvPosition = tVector3f();
        tVector3f mvVelocity = tVector3f();

        float mfPitch = 1.0f;
        float mfGain = 1.0f;
        bool mbLoop = false;

        uint32_t mlAudioBufferID = 0;
    };
}

#endif // BAIZEL_AUDIOSOURCE_H