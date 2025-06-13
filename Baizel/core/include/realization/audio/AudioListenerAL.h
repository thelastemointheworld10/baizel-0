#ifndef BAIZEL_AUDIOLISTENERAL_H
#define BAIZEL_AUDIOLISTENERAL_H

#include <realization/audio/ErrorHandlerAL.h>

#include <audio/AudioListener.h>

namespace baizel
{
    class cAudioListenerAL final : public iAudioListener
    {
    public:
        void SetPosition(const tVector3f& avPosition) override;
        void SetPosition(const tVector2f& avPosition) override;
        void SetVelocity(const tVector3f& avVelocity) override;
        void SetVelocity(const tVector2f& avVelocity) override;
        void SetOrientation(const tVector3f& avUp, const tVector3f& avForward) override;
        void SetMasterGain(float afGain) override;
    };
}

#endif // BAIZEL_AUDIOLISTENERAL_H