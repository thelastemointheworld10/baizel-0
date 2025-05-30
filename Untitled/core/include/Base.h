#ifndef BASE_H
#define BASE_H

#include <string>

#include <realization/engine/EngineSetupSDL.h>

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

        std::string msWindowTitle;
        tVector2l mvWindowSize;
        bool mbFullscreen;
    };
}

#endif // BASE_H