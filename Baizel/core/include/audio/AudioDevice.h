#ifndef BAIZEL_AUDIODEVICE_H
#define BAIZEL_AUDIODEVICE_H

#include <vector>
#include <string>

#include <engine/Log.h>

namespace baizel
{
    using tAudioDevicesVec = std::vector<std::string>;
    const int gkMaxAudioDevices = 3;

    class iAudioDevice
    {
    public:
        virtual void SetDevice(const std::string& asName) = 0;

        const tAudioDevicesVec& GetAvialableDevices() const;
        const std::string& GetDefaultDevice() const;

    protected:
        virtual void InitializeDevices() = 0;

    protected:
        tAudioDevicesVec mvAudioDevices = {};
    };
}

#endif // BAIZEL_AUDIODEVICE_H