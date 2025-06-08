#ifndef BAIZEL_AUDIOSOURCEAL_H
#define BAIZEL_AUDIOSOURCEAL_H

#include <realization/audio/ErrorHandlerAL.h>

#include <audio/AudioSource.h>

namespace baizel
{
    class cAudioSourceAL final : public iAudioSource
    {
    public:
        cAudioSourceAL();

        void Play() const override;

    protected:
        void UpdateValues() const override;
    };
}

#endif // BAIZEL_AUDIOSOURCEAL_H