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
        virtual void SetPosition(tVector2f avPosition) = 0;
        virtual void SetVelocity(const tVector3f& avVelocity) = 0;
        virtual void SetVelocity(tVector2f avVelocity) = 0;

        virtual void SetPitch(float afPitch) = 0;
        virtual void SetGain(float afGain) = 0;
        virtual void SetLoop(bool abLoop) = 0;

        virtual void SetRelative(bool abRelative) = 0;

        virtual void SetMinDistance(float afDistance) = 0;
        virtual void SetMaxDistance(float afDistance) = 0;
        virtual void SetRolloffFactor(float afRolloff) = 0;

        virtual void SetBuffer(iAudioBuffer* apAudioBuffer) = 0;

        const tVector3f& GetPosition() const;
        const tVector3f& GetVelocity() const;

        float GetPitch() const;
        float GetGain() const;
        bool GetLoop() const;

        bool GetRelative() const;

        float GetMinDistance() const;
        float GetMaxDistance() const;
        float GetRolloffFactor() const;

        iAudioBuffer* GetBuffer() const;

        virtual void Play() const = 0;
        virtual void Stop() const = 0;
        virtual void Pause() const = 0;

    protected:
        iAudioBuffer* mpAudioBuffer = nullptr;
        uint32_t mlSourceID = 0;

        tVector3f mvPosition = tVector3f();
        tVector3f mvVelocity = tVector3f();

        float mfPitch = 1.0f;
        float mfGain = 1.0f;
        bool mbLoop = false;

        bool mbRelative = false;

        float mfMinDistance = 200.0f;
        float mfMaxDistance = 600.0f;
        float mfRolloffFactor = 1.0f;
    };
}

#endif // BAIZEL_AUDIOSOURCE_H