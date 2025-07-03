#ifndef BAIZEL_AUDIOBUFFER_H
#define BAIZEL_AUDIOBUFFER_H

#include <string>
#include <vector>

#include <diagnostics/Log.h>
#include <audio/AudioReader.h>

namespace baizel
{
    class iAudioBuffer
    {
    public:
        iAudioBuffer(iAudioReader* apAudioReader);
        ~iAudioBuffer();

        bool LoadAudio(const std::string& asPath);

        uint32_t GetID() const;

    protected:
        virtual void SetData() = 0;
        virtual void SetFormat(int alChannels) = 0;

    protected:
        iAudioReader* mpAudioReader = nullptr;
        iOggFile* mpAudioFile = nullptr;

        uint32_t mlBufferID = 0;
        unsigned int mlFormat = 0;
    };
}

#endif // BAIZEL_AUDIOBUFFER_H