#include <engine/FPSManager.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cFPSManager::cFPSManager(iSystem* apSystem)
	{
		mlFrames = 0;

		mlFPS = 60;
		mlFPSLimit = 0;

		mfTimeStep = 0.016f;

		mpSystem = apSystem;

		mfCurrentFrameTime = 0.0f;
		mfLastFrameTime = mpSystem->GetTimeInSec();

		mfFrameRate = 0.0f;
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	void cFPSManager::AddFrame()
	{
		mfCurrentFrameTime = mpSystem->GetTimeInSec();
		mfTimeStep = mfCurrentFrameTime - mfLastFrameTime;
		mfLastFrameTime = mfCurrentFrameTime;

		if (mlFPSLimit > 0)
			LimitFPS();
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	void cFPSManager::SetFPSLimit(int alFPSLimit)
	{
		mlFPSLimit = alFPSLimit;

		if (mlFPSLimit <= 0)
		{
			cLog::Warning("You have set the frame limit to 0. This means that there is no limit.");
			mfFrameRate = 0.0f;
		}
		else
		{
			mfFrameRate = 1.0f / mlFPSLimit;
			cLog::Log("Setting FPS limit: %d. New frame time: %.5f", mlFPSLimit, mfFrameRate);
		}
	}

	float cFPSManager::GetTimeStep() const
	{
		return mfTimeStep;
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////
	
	void cFPSManager::LimitFPS() const
	{
		float fFrameTime = mpSystem->GetTimeInSec() - mfLastFrameTime;
		if (fFrameTime < mfFrameRate)
		{
			mpSystem->SleepForMilliSec((mfFrameRate - fFrameTime) * 1000.0f);
		}
	}
	
	// -----------------------------------------------------------------------
}