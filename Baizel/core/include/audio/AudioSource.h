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
        void SetPosition(const tVector3f& avPosition);
        void SetVelocity(const tVector3f& avVelocity);
        void SetPitch(float afPitch);
        void SetGain(float afGain);
        void SetLoop(bool abLoop);
        void SetBuffer(uint32_t alAudioBuffer);

        const tVector3f& GetPosition() const;
        const tVector3f& GetVelocity() const;
        float GetPitch() const;
        float GetGain() const;
        bool GetLoop() const;
        uint32_t GetBuffer() const;

        virtual void Play() const = 0;

    protected:
        virtual void UpdateValues() const = 0;

    protected:
        uint32_t mlSourceID = 0;

        tVector3f mvPosition = tVector3f();
        tVector3f mvVelocity = tVector3f();

        float mfPitch = 1.0f;
        float mfGain = 1.0f;
        bool mbLoop = false;

        uint32_t mlAudioBuffer = 0;
    };
}

#endif // BAIZEL_AUDIOSOURCE_H