#ifndef BAIZEL_AUDIOLISTENER_H
#define BAIZEL_AUDIOLISTENER_H

#include <math/Math.h>
#include <math/MathTypes.h>

namespace baizel
{
    class iAudioListener
    {
    public:
        virtual void SetPosition(const tVector3f& avPosition) = 0;
        virtual void SetPosition(tVector2f avPosition) = 0;
        virtual void SetVelocity(const tVector3f& avVelocity) = 0;
        virtual void SetVelocity(tVector2f avVelocity) = 0;
        virtual void SetOrientation(const tVector3f& avUp, const tVector3f& avForward) = 0;
        virtual void SetMasterGain(float afGain) = 0;

        const tVector3f& GetPosition() const;
        const tVector3f& GetVelocity() const;
        const tVector3f& GetForward() const;
        const tVector3f& GetUp() const;
        float GetMasterGain() const;

    protected:
        tVector3f mvPosition = tVector3f();
        tVector3f mvVelocity = tVector3f();
        tVector3f mvForward = tVector3f();
        tVector3f mvUp = tVector3f();

        float mfMasterGain = 1.0f;
    };
}

#endif // BAIZEL_AUDIOLISTENER_H