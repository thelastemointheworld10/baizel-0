#ifndef BAIZEL_AUDIOREADERLIBVORBIS_H
#define BAIZEL_AUDIOREADERLIBVORBIS_H

#include <audio/AudioReader.h>
#include <impl/audio/OggFileLibVorbis.h>

namespace baizel
{
    class cAudioReaderLibVorbis final : public iAudioReader
    {
    public:
        iOggFile* CreateOggFile() const;
    };
}

#endif // BAIZEL_AUDIOREADERLIBVORBIS_H