#ifndef BASE_H
#define BASE_H

#include <string>
#ifdef _WIN32
#include <Windows.h>
#endif

#include <realization/engine/EngineSetupSDL.h>
#include <realization/audio/AudioSystemAL.h>

#include <Player.h>

namespace baizel
{
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
}

#endif // BASE_H