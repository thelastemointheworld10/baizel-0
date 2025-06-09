#ifndef BAIZEL_AUDIOSYSTEMAL_H
#define BAIZEL_AUDIOSYSTEMAL_H

#include <audio/AudioSystem.h>

#include <realization/audio/AudioBufferAL.h>
#include <realization/audio/AudioSourceAL.h>
#include <realization/audio/AudioListenerAL.h>
#include <realization/audio/AudioDeviceAL.h>

namespace baizel
{
    class cAudioSystemAL final : public iAudioSystem
    {
    public:
        ~cAudioSystemAL();

        void CreateDevice() override;
        void CreateContext() override;
        void CreateListener() override;

        iAudioBuffer* CreateBuffer() const override;
        iAudioSource* CreateSource() const override;

        void Exit() override;

    private:
        ALCcontext* mpContext = nullptr;
    };
}

#endif // BAIZEL_AUDIOSYSTEMAL_H