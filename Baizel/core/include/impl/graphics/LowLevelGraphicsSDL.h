#ifndef BAIZEL_LOWLEVELGRAPHICSSDL_H
#define BAIZEL_LOWLEVELGRAPHICSSDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <engine/Log.h>

#include <graphics/LowLevelGraphics.h>
#include <impl/graphics/TextureSDL.h>
#include <impl/graphics/RendererSDL.h>

namespace baizel
{
    class cLowLevelGraphicsSDL : public iLowLevelGraphics
    {
    public:
        ~cLowLevelGraphicsSDL() override;

        bool Init(const std::string& asWindowTitle, tVector2l avWindowSize, tVector2f avVirtualSize, bool abFullscreen) override;

        SDL_Window* GetWindow() const;

        iTexture* CreateTexture() const override;

    private:
        SDL_Window* mpWindow = nullptr;
        std::string msWindowTitle = "baizel window";
        bool mbFullscreen = false;
    };
}

#endif // BAIZEL_LOWLEVELGRAPHICSSDL_H