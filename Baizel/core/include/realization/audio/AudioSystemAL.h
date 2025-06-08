#ifndef BAIZEL_AUDIOSYSTEMAL_H
#define BAIZEL_AUDIOSYSTEMAL_H

#include <audio/AudioSystem.h>
#include <realization/audio/ErrorHandlerAL.h>

#include <realization/audio/AudioBufferAL.h>
#include <realization/audio/AudioSourceAL.h>

namespace baizel
{
    class cAudioSystemAL : public iAudioSystem
    {
    public:
        ~cAudioSystemAL();

        void CreateDevice() override;
        void CreateContext() override;

        iAudioBuffer* CreateBuffer() const override;
        iAudioSource* CreateSource() const override;

        void SetListenerPosition(const tVector3f& avPosition) override;
        void SetListenerVelocity(const tVector3f& avVelocity) override;

        void SetAudioDevices() override;

        void Exit() override;

    private:
        ALCdevice* mpDevice = nullptr;
        ALCcontext* mpContext = nullptr;
    };
}

#endif // BAIZEL_AUDIOSYSTEMAL_H