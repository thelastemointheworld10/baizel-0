#ifndef BAIZEL_AUDIOBUFFERAL_H
#define BAIZEL_AUDIOBUFFERAL_H

#include <audio/AudioBuffer.h>
#include <impl/audio/ErrorHandlerAL.h>

namespace baizel
{
    class cAudioBufferAL final : public iAudioBuffer
    {
    public:
        cAudioBufferAL();
        ~cAudioBufferAL();

    protected:
        void SetData() override;
        void SetFormat(int alChannels) override;
    };
}

#endif // BAIZEL_AUDIOBUFFERAL_H