#ifndef BAIZEL_GRAPHICS_H
#define BAIZEL_GRAPHICS_H

#include <graphics/LowLevelGraphics.h>

namespace baizel
{
	class cGraphics final
	{
	public:
		cGraphics(iLowLevelGraphics* apLowLevelGraphics, iRenderer* apRenderer);
		~cGraphics();

		iLowLevelGraphics* GetLowLevel();
		iRenderer* GetRenderer();

	private:
		iLowLevelGraphics* mpLowLevelGraphics;
		iRenderer* mpRenderer;
	};
}

#endif // BAIZEL_GRAPHICS_H