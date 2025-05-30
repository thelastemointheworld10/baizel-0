#include <graphics/Animation.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cAnimation::cAnimation(int alFrames, iLowLevelGraphics* apLowLevelGraphics)
	{
		mpLowLevelGraphics = apLowLevelGraphics;

		mlCurrentFrame = 0;
		mvFrames.reserve(alFrames);
		mfFrameRate = 1.0f / alFrames;
	}

	cAnimation::~cAnimation()
	{
		for (iTexture* pFrame : mvFrames)
		{
			delete pFrame;
		}

		mvFrames.clear();
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	void cAnimation::SetSpeed(float afFrames)
	{
		mfFrameRate = 1.0f / afFrames;
	}

	void cAnimation::AddFrame(std::string asFramePath)
	{
		iTexture* pFrame = mpLowLevelGraphics->CreateTexture();
		pFrame->Load(asFramePath);

		mvFrames.push_back(pFrame);
	}

	iTexture* cAnimation::GetCurrentFrame() const
	{
		return mvFrames[mlCurrentFrame];
	}

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	void cAnimation::Update(float afTimeStep)
	{
		static float fFrameTime = 0.0f;
		fFrameTime += afTimeStep;

		if (fFrameTime >= mfFrameRate)
		{
			fFrameTime = 0.0f;
			if (mlCurrentFrame + 1 < mvFrames.size())
				mlCurrentFrame += 1;
			else
				mlCurrentFrame = 0;
		}
	}

	// -----------------------------------------------------------------------
}