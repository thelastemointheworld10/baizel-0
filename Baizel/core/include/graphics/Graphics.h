#ifndef BAIZEL_GRAPHICS_H
#define BAIZEL_GRAPHICS_H

#include <graphics/LowLevelGraphics.h>

namespace baizel
{
	class cGraphics final
	{
	public:
		cGraphics(iLowLevelGraphics* apLowLevelGraphics);

		iLowLevelGraphics* GetLowLevel();

	private:
		iLowLevelGraphics* mpLowLevelGraphics;
	};
}

#endif // BAIZEL_GRAPHICS_H