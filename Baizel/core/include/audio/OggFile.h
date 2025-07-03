#ifndef BAIZEL_OGGFILE_H
#define BAIZEL_OGGFILE_H

#include <string>
#include <vector>

#include <diagnostics/Log.h>

namespace baizel
{
    const int gkPCMLength = 4096;
    using tPCMVec = std::vector<short>;

    class iOggFile
    {
    public:
        iOggFile();
        virtual ~iOggFile() = default;

        virtual bool LoadFile(const std::string& asPath) = 0;

        int GetVersion() const;
        int GetChannels() const;
        long GetRate() const;

        long GetBitrateUpper() const;
        long GetBitrateNominal() const;
        long GetBitrateLower() const;
        long GetBitrateWindow() const;

        const tPCMVec& GetPCM() const;

    protected:
        int mlVersion = 0;
        int mlChannels = 0;
        long mlRate = 0;

        long mlBitrateUpper = 0;
        long mlBitrateNominal = 0;
        long mlBitrateLower = 0;
        long mlBitrateWindow = 0;

        tPCMVec mvPCMData = tPCMVec();
    };
}

#endif // BAIZEL_OGGFILE_H