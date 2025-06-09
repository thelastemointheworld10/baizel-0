#ifndef BAIZEL_AUDIOSYSTEM_H
#define BAIZEL_AUDIOSYSTEM_H

#include <vector>
#include <string>

#include <math/MathTypes.h>
#include <engine/Log.h>

#include <audio/AudioBuffer.h>
#include <audio/AudioSource.h>
#include <audio/AudioListener.h>
#include <audio/AudioDevice.h>

namespace baizel
{
    class iAudioSystem
    {
    public:
        ~iAudioSystem();

        virtual void CreateDevice() = 0;
        virtual void CreateContext() = 0;
        virtual void CreateListener() = 0;

        virtual iAudioBuffer* CreateBuffer() const = 0;
        virtual iAudioSource* CreateSource() const = 0;

        iAudioListener* GetListener() const;

        virtual void Exit() = 0;

    protected:
        iAudioListener* mpAudioListener = nullptr;
        iAudioDevice* mpAudioDevice = nullptr;
    };
}

#endif // BAIZEL_AUDIOSYSTEM_H