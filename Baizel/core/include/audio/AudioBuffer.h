#ifndef BAIZEL_AUDIOBUFFER_H
#define BAIZEL_AUDIOBUFFER_H

#include <string>
#include <vector>

#include <diagnostics/Log.h>

#include <audio/stb_vorbis.h>

namespace baizel
{
    class iAudioBuffer
    {
    public:
        bool LoadAudio(const std::string& asPath);

        uint32_t GetID() const;

    protected:
        virtual void SetData() = 0;
        virtual void SetFormat(int alChannels) = 0;

        void Reset();

    protected:
        uint32_t mlBufferID = 0;
        uint32_t mlFormat = 0;
        int mlChannels = 0;
        int mlSampleRate = 0;
        std::vector<int16_t> mvPCMData;

        stb_vorbis* mpVorbis = nullptr;
    };
}

#endif // BAIZEL_AUDIOBUFFER_H