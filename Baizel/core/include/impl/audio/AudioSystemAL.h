#ifndef BAIZEL_AUDIOSYSTEMAL_H
#define BAIZEL_AUDIOSYSTEMAL_H

#include <audio/AudioSystem.h>

#include <impl/audio/AudioBufferAL.h>
#include <impl/audio/AudioSourceAL.h>
#include <impl/audio/AudioListenerAL.h>
#include <impl/audio/AudioDeviceAL.h>

namespace baizel
{
    class cAudioSystemAL final : public iAudioSystem
    {
    public:
        ~cAudioSystemAL();

        void CreateDevice() override;
        void CreateContext() override;
        void CreateListener() override;

        void SetDistanceModel(eDistanceModel aDistanceModel) const override;

        iAudioBuffer* CreateBuffer() const override;
        iAudioSource* CreateSource() const override;

        void Exit() override;

    private:
        ALCcontext* mpContext = nullptr;
    };
}

#endif // BAIZEL_AUDIOSYSTEMAL_H