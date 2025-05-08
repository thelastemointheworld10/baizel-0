#ifndef BAIZEL_LOWLEVELGRAPHICSSDL_H
#define BAIZEL_LOWLEVELGRAPHICSSDL_H

#include <implementation/LowLevelGraphics.h>
#include <SDL2/SDL.h>

namespace baizel
{
    class cLowLevelGraphicsSDL : public iLowLevelGraphics
    {
    public:
        ~cLowLevelGraphicsSDL() override;

        bool Init(const char* asWindowTitle, cVector2l avWindowSize, bool abFullscreen) override;

        void SetCursorVisible(bool abVisible) override;
    private:
        SDL_Window* mpWindow;
        std::string msWindowTitle;
        cVector2l mvWindowSize;
        bool mbFullscreen;
    };
}

#endif // BAIZEL_LOWLEVELGRAPHICSSDL_H