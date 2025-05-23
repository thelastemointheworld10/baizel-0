#ifndef BASE_H
#define BASE_H

#include <string>

#include <engine/Engine.h>
#include <engine/Log.h>

#include <realization/EngineSetupSDL.h>

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
        cEngine* mpEngine = nullptr;

        const char* msWindowTitle;
        tVector2l mvWindowSize;
        bool mbFullscreen;
    };
}

#endif // BASE_H