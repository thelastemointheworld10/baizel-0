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
		mfFrameRate = 1.0f / afFrames;
	}

	void cAnimation::AddFrame(const std::string& asFramePath)
	{
		if (mpLowLevelGraphics == nullptr)
		{
			cLog::Error("Failed to add frame! LowLevelGraphics is nullptr!");
			return;
		}

		//cLog::Log("adding animation frame: %s", asFramePath.c_str());

		iTexture* pNewFrame = FindSameFrame(asFramePath);
		if (pNewFrame == nullptr) // same frame does not exists
		{
			pNewFrame = mpLowLevelGraphics->CreateTexture();
			pNewFrame->LoadFile(asFramePath);
		}

		mvFrames.push_back(pNewFrame);
	}

	iTexture* cAnimation::GetCurrentFrame() const
	{
		if (mvFrames.empty() || mlCurrentFrame >= mvFrames.size())
		{
			cLog::Error("There is no any animation frames, or current frame is goes beyond the boundaries of the vector");
			return nullptr;
		}

		return mvFrames[mlCurrentFrame];
	}

	iTexture* cAnimation::GetFrameByIndex(size_t alIndex) const
	{
		if (mvFrames.size() == 0 || alIndex >= mvFrames.size())
		{
			cLog::Error("There is no any animation frames, or current frame is goes beyond the boundaries of the vector");
			return nullptr;
		}

		return mvFrames[alIndex];
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
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	iTexture* cAnimation::FindSameFrame(const std::string& asPath) const
	{
		for (iTexture* pFrame : mvFrames)
		{
			if (pFrame->GetPath() == asPath)
			{
				return pFrame;
			}
		}

		return nullptr;
	}

	// -----------------------------------------------------------------------
}