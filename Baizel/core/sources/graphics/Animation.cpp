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
		mfFrameTime = 0.0f;
	}

	cAnimation::cAnimation(const cAnimation& aAnimation)
	{
		mpLowLevelGraphics = aAnimation.mpLowLevelGraphics;
		mvFrames.reserve(aAnimation.mvFrames.size());
		mlCurrentFrame = aAnimation.mlCurrentFrame;
		mfFrameRate = aAnimation.mfFrameRate;
		mfFrameTime = aAnimation.mfFrameTime;

		for (iTexture* pOldFrame : aAnimation.mvFrames)
		{
			if (pOldFrame != nullptr)
				AddFrame(pOldFrame->GetPath());
		}
	}

	cAnimation::~cAnimation()
	{
		for (iTexture* pFrame : mvFrames)
		{
			if (pFrame != nullptr)
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
		this->mfFrameRate = 1.0f / afFrames;
		cLog::Log("New FrameRate for %p: %f", this, mfFrameRate);
	}

	void cAnimation::AddFrame(const std::string& asFramePath)
	{
		cLog::Log("Adding animation frame: %s", asFramePath.c_str());

		if (mpLowLevelGraphics == nullptr)
		{
			cLog::Error("Failed to add frame! LowLevelGraphics is nullptr!");
			return;
		}

		iTexture* pFrame = mpLowLevelGraphics->CreateTexture();
		if (pFrame == nullptr)
		{
			cLog::Error("Failed to add frame! new frame is nullptr!");
			return;
		}

		pFrame->Load(asFramePath);

		mvFrames.push_back(pFrame);
	}

	iTexture* cAnimation::GetCurrentFrame() const
	{
		if (mvFrames.empty() || mlCurrentFrame >= mvFrames.size())
		{
			cLog::Warning("There isnt any frames, or current frame is goes beyond the boundaries of the vector");
			return nullptr;
		}

		return mvFrames[mlCurrentFrame];
	}

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	void cAnimation::Update(float afTimeStep)
	{
		mfFrameTime += afTimeStep;

		if (mfFrameTime >= mfFrameRate)
		{
			mfFrameTime = 0.0f;
			if (mlCurrentFrame + 1 < mvFrames.size())
				mlCurrentFrame += 1;
			else
				mlCurrentFrame = 0;
		}
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// OPERATORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Copy
	//////////////////////////////////////////

	cAnimation& cAnimation::operator=(const cAnimation& aAnimation)
	{
		if (this == &aAnimation)
			return *this;

		for (iTexture* pFrame : mvFrames)
		{
			delete pFrame;
		}
		mvFrames.clear();

		mpLowLevelGraphics = aAnimation.mpLowLevelGraphics;
		mvFrames.reserve(aAnimation.mvFrames.size());
		mlCurrentFrame = aAnimation.mlCurrentFrame;
		mfFrameRate = aAnimation.mfFrameRate;
		mfFrameTime = aAnimation.mfFrameTime;

		for (iTexture* pOldFrame : aAnimation.mvFrames)
		{
			if (pOldFrame != nullptr)
				AddFrame(pOldFrame->GetPath());
		}

		return *this;
	}

	// -----------------------------------------------------------------------
}