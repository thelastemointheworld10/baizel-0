#ifndef BAIZEL_LOWLEVELGRAPHICSSDL_H
#define BAIZEL_LOWLEVELGRAPHICSSDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <engine/Log.h>

#include <graphics/LowLevelGraphics.h>
#include <realization/graphics/TextureSDL.h>
#include <realization/graphics/RendererSDL.h>
#include <realization/graphics/FontSDL.h>

#undef CreateFont

namespace baizel
{
    class cLowLevelGraphicsSDL : public iLowLevelGraphics
    {
    public:
        ~cLowLevelGraphicsSDL() override;

        bool Init(std::string asWindowTitle, tVector2l avWindowSize, bool abFullscreen) override;

        SDL_Window* GetWindow() const;

        iTexture* CreateTexture() const override;
        iFont* CreateFont() override;

        void SetCursorVisible(bool abVisible) const override;

    private:
        SDL_Window* mpWindow = nullptr;
        std::string msWindowTitle;
        bool mbFullscreen;
    };
}

#endif // BAIZEL_LOWLEVELGRAPHICSSDL_H