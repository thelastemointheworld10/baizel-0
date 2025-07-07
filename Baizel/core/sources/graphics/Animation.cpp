#include <graphics/Animation.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cAnimation::cAnimation(iLowLevelGraphics* apLowLevelGraphics)
	{
		mpLowLevelGraphics = apLowLevelGraphics;

		mlCurrentFrame = 0;
		mvFrames.reserve(gkDefaultFrames);
		mfFrameRate = 1.0f / gkDefaultFrames;
		mfFrameTime = 0.0f;
	}

	cAnimation::~cAnimation()
	{
		if (mvFrames.size() == 0)
			return;

		for (iTexture* pFrame : mvFrames)
		{
			if (pFrame != nullptr && pFrame->GetPath().empty() == false)
			{
				delete pFrame;
			}
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

		if (iTexture* pExisting = FindSameFrame(asFramePath))
		{
			mvFrames.push_back(pExisting);
			return;
		}

		iTexture* pNewFrame = mpLowLevelGraphics->CreateTexture();
		if (pNewFrame == nullptr) // same frame does not exists
		{
			cLog::Error("Failed to create texture for frame: %s", asFramePath.c_str());
			return;
		}

		pNewFrame->LoadFile(asFramePath);
		mvFrames.push_back(pNewFrame);
	}

	void cAnimation::AddFrame(iTexture* apTexture)
	{
		if (mpLowLevelGraphics == nullptr)
		{
			cLog::Error("Failed to add frame! LowLevelGraphics is nullptr!");
			return;
		}

		//cLog::Log("adding animation frame: %s", apTexture->GetPath().c_str());
		if (apTexture == nullptr)
			cLog::Warning("New animation frame is nullptr");
		else
			mvFrames.push_back(apTexture);
	}

	void cAnimation::SetFrames(const tTextureVec& avFrames)
	{
		if (mvFrames.size() == 0)
			return;

		mvFrames.clear();

		for (iTexture* pFrame : avFrames)
		{
			if (pFrame != nullptr)
				mvFrames.push_back(pFrame);
		}

		Reset();
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

	void cAnimation::Reset()
	{
		mlCurrentFrame = 0;
		mfFrameTime = 0.0f;
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