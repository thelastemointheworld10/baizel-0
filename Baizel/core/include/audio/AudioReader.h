#ifndef BAIZEL_AUDIOREADER_H
#define BAIZEL_AUDIOREADER_H

#include <audio/OggFile.h>

namespace baizel
{
    class iAudioReader
    {
    public:
        virtual iOggFile* CreateOggFile() const = 0;
    };
}

#endif // BAIZEL_AUDIOREADER_H