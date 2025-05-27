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

		iLowLevelGraphics* GetLowLevel() const;
		iRenderer* GetRenderer() const;

	private:
		iLowLevelGraphics* mpLowLevelGraphics;
		iRenderer* mpRenderer;
	};
}

#endif // BAIZEL_GRAPHICS_H