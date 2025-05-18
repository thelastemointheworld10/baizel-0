#ifndef BASE_H
#define BASE_H

#include <string>

#include <Engine.h>
#include <Log.h>

#include <implementation/GameSetupSDL.h>

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
        cEngine* mpEngine;

        const char* msWindowTitle;
        cVector2l mvWindowSize;
        bool mbFullscreen;
    };
}

#endif // BASE_H