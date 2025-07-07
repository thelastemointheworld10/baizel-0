#ifndef BASE_H
#define BASE_H

#include <string>
#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

#include <impl/engine/EngineSetupSDL.h>
#include <impl/audio/AudioSystemAL.h>
#include <impl/audio/AudioReaderLibVorbis.h>
#include <impl/resources/XMLReaderTiXML.h>

#include <Player.h>

using namespace baizel;

class cBase final
{
public:
    cBase();
    ~cBase();

    bool Init();
    void Run();
    void Exit();

private:
    std::string msWindowTitle = "";
    tVector2l mvScreenSize = tVector2l(800, 600);
    tVector2f mvVirtualSize = tVector2f(800, 600);
    bool mbFullscreen = false;

    cEngine* mpEngine = nullptr;

    cPlayer* mpPlayer = nullptr;
};

#endif // BASE_H