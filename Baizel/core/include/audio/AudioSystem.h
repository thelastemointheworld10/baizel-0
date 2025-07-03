#ifndef BAIZEL_AUDIOSYSTEM_H
#define BAIZEL_AUDIOSYSTEM_H

#include <vector>
#include <string>

#include <math/MathTypes.h>
#include <diagnostics/Log.h>

#include <audio/AudioBuffer.h>
#include <audio/AudioSource.h>
#include <audio/AudioListener.h>
#include <audio/AudioDevice.h>

#include <audio/AudioReader.h>

namespace baizel
{
    enum eDistanceModel
    {
        eDistanceModel_None,
        eDistanceModel_InverseDistance,
        eDistanceModel_InverseDistanceClamped,
        eDistanceModel_LinearDistance,
        eDistanceModel_LinearDistanceClamped,
        eDistanceModel_ExponentDistance,
        eDistanceModel_ExponentDistanceClamped
    };

    class iAudioSystem
    {
    public:
        iAudioSystem(iAudioReader* apAudioReader);
        virtual ~iAudioSystem();

        virtual void CreateDevice() = 0;
        virtual void CreateContext() = 0;
        virtual void CreateListener() = 0;

        virtual void SetDistanceModel(eDistanceModel aDistanceModel) const = 0;

        virtual iAudioBuffer* CreateBuffer() const = 0;
        virtual iAudioSource* CreateSource() const = 0;

        iAudioListener* GetListener() const;

        virtual void Exit() = 0;

    protected:
        iAudioListener* mpAudioListener = nullptr;
        iAudioDevice* mpAudioDevice = nullptr;
        iAudioReader* mpAudioReader = nullptr;
    };
}

#endif // BAIZEL_AUDIOSYSTEM_H