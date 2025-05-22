#ifndef BAIZEL_LOWLEVELGRAPHICSSDL_H
#define BAIZEL_LOWLEVELGRAPHICSSDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <engine/Log.h>

#include <graphics/LowLevelGraphics.h>
#include <realization/TextureSDL.h>
#include <realization/RendererSDL.h>

namespace baizel
{
    class cLowLevelGraphicsSDL : public iLowLevelGraphics
    {
    public:
        cLowLevelGraphicsSDL();
        ~cLowLevelGraphicsSDL() override;

        bool Init(const char* asWindowTitle, cVector2l avWindowSize, bool abFullscreen) override;

        SDL_Window* GetWindow() const;
        iRenderer* GetRenderer() const override;
        iTexture* CreateTexture() const override;

        void SetCursorVisible(bool abVisible) const override;

    private:
        SDL_Window* mpWindow = nullptr;
        std::string msWindowTitle;
        cVector2l mvWindowSize;
        bool mbFullscreen;
    };
}

#endif // BAIZEL_LOWLEVELGRAPHICSSDL_H