#ifndef INIT_H
#define INIT_H

#include <string>
#include <Engine.h>
#include <implementation/SDLGameSetup.h>
#include <Log.h>

namespace baizel
{
    class cInit final
    {
    public:
        cInit();
        ~cInit();
    
        bool Init();
        void Run();
        void Exit();
    private:
        cEngine* mpEngine;

        iGameSetup* mpGameSetup;

        const char* msWindowTitle;
        cVector2l mvWindowSize;
        bool mbFullscreen;
    };
}

#endif // INIT_H