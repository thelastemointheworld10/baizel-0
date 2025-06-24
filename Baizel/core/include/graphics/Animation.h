#ifndef BAIZEL_ANIMATION_H
#define BAIZEL_ANIMATION_H

#include <string>
#include <vector>

#include <math/Math.h>
#include <engine/Log.h>

#include <graphics/LowLevelGraphics.h>
#include <graphics/Texture.h>

namespace baizel
{
	using tFrameVector = std::vector<iTexture*>;
	const int gkDefaultFrames = 12;

	class cAnimation final
	{
	public:
		cAnimation(iLowLevelGraphics* apLowLevelGraphics);
		~cAnimation();

		void SetSpeed(float afFramesPerSec);
		void SetFrames(const tFrameVector& avFrames);

		void AddFrame(const std::string& asPath);
		void AddFrame(iTexture* apTexture);

		iTexture* GetCurrentFrame() const;
		iTexture* GetFrameByIndex(size_t alIndex) const;

		void ResetFrameTime();

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