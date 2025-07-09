#ifndef BAIZEL_OGGFILELIBVORBIS_H
#define BAIZEL_OGGFILELIBVORBIS_H

#include <vorbis/vorbisfile.h>

#include <audio/OggFile.h>

namespace baizel
{
    class cOggFileLibVorbis final : public iOggFile
    {
    public:
        bool LoadFile(const std::string& asPath) override;

    private:
        void ReadPCM(OggVorbis_File& aVorbis);
        void AssignInfo(OggVorbis_File& aVorbis, vorbis_info* apInfo);
    };
}

#endif // BAIZEL_OGGFILELIBVORBIS_H