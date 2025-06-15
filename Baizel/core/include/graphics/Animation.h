#ifndef BAIZEL_ANIMATION_H
#define BAIZEL_ANIMATION_H

#include <string>
#include <queue>

#include <math/Math.h>
#include <engine/Log.h>

#include <graphics/LowLevelGraphics.h>
#include <graphics/AnimationTypes.h>

namespace baizel
{
	class cAnimation final
	{
	public:
		cAnimation(int alFrames, iLowLevelGraphics* apLowLevelGraphics);
		~cAnimation();

		void SetSpeed(float afSpeed);
		void AddFrame(const std::string& asFramePath);
		iTexture* GetCurrentFrame() const;

		void Update(float afTimeStep);

	private:
		iTexture* FindSameFrame(const std::string& asPath) const;

	private:

		tFrameVector mvFrames;
		int mlCurrentFrame;

		float mfFrameRate;
		float mfFrameTime;

		iLowLevelGraphics* mpLowLevelGraphics;
	};
}

#endif // BAIZEL_ANIMATION_H