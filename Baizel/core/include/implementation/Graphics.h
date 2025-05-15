#ifndef BAIZEL_GRAPHICS_H
#define BAIZEL_GRAPHICS_H

#include <cstdint>
#include <SDL2/SDL.h>
#include <implementation/LowLevelGraphics.h>

namespace baizel
{
    class cGraphics
    {
    public:
        cGraphics(iLowLevelGraphics* apLowLevelGraphics);
        ~cGraphics();

        bool Init(const char* asWindowTitle, cVector2l avWindowSize, bool abFullscreen);

        void DrawRect(uint8_t alRed, uint8_t alGreen, uint8_t alBlue, uint8_t alAlpha = 255);
        void DrawTexturedRect(SDL_Texture* apTexture, uint8_t alAlpha = 255);
    protected:
        iLowLevelGraphics* mpLowLevelGraphics;
    };
}

#endif // BAIZEL_GRAPHICS_H