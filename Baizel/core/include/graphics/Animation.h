#ifndef BAIZEL_ANIMATION_H
#define BAIZEL_ANIMATION_H

#include <queue>

#include <math/Math.h>
#include <engine/Log.h>

#include <graphics/LowLevelGraphics.h>
#include <graphics/AnimationTypes.h>
#include <system/Timer.h>

namespace baizel
{
	class cAnimation final
	{
	public:
		cAnimation(int alFrames, iLowLevelGraphics* apLowLevelGraphics);
		~cAnimation();

		void SetSpeed(float afSpeed);
		void AddFrame(std::string asFramePath);
		iTexture* GetCurrentFrame() const;

		void Update(float afTimeStep);

	private:
		tFrameVector mvFrames;
		int mlCurrentFrame;

		float mfFrameRate;
		float mfFrameTime;

		iLowLevelGraphics* mpLowLevelGraphics;
	};
}

#endif // BAIZEL_ANIMATION_H