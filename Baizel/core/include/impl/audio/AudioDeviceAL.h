#ifndef BAIZEL_AUDIODEVICEAL_H
#define BAIZEL_AUDIODEVICEAL_H

#include <impl/audio/ErrorHandlerAL.h>

#include <audio/AudioDevice.h>

namespace baizel
{
    class cAudioDeviceAL final : public iAudioDevice
    {
    public:
        cAudioDeviceAL();
        ~cAudioDeviceAL();

        void SetDevice(const std::string& asName) override;
        ALCdevice* GetALCDevice() const;

    protected:
        void InitializeDevices() override;

    private:
        ALCdevice* mpAudioDevice = nullptr;
    };
}

#endif // BAIZEL_AUDIODEVICEAL_H