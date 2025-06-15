#include <time/Timer.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cTimer::cTimer(iApplicationTime* apApplicationTime)
	{
		mpApplicationTime = apApplicationTime;
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	void cTimer::Start()
	{
		mlStartTicks = mpApplicationTime->GetTimeInMilliSec();
		mlPausedTicks = 0;

		mbStarted = true;
		mbPaused = false;
	}

	void cTimer::Stop()
	{
		mbStarted = false;
		mbPaused = false;

		mlStartTicks = 0;
		mlPausedTicks = 0;
	}

	void cTimer::Pause()
	{
		if (mbStarted == false)
		{
			cLog::Warning("You can not pause the timer while it is not started");
			return;
		}

		if (mbPaused == true)
		{
			cLog::Warning("Timer is already paused");
			return;
		}

		mbPaused = true;
		mlPausedTicks = mpApplicationTime->GetTimeInMilliSec() - mlStartTicks;
		mlStartTicks = 0;
	}

	void cTimer::Unpause()
	{
		if (mbStarted == false)
		{
			cLog::Warning("You can not unpause the timer while it is not started");
			return;
		}

		if (mbPaused == false)
		{
			cLog::Warning("Timer is already unpaused");
			return;
		}

		mbPaused = false;
		mlStartTicks = mpApplicationTime->GetTimeInMilliSec() - mlPausedTicks;
		mlPausedTicks = 0;
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	float cTimer::GetTimeInMilliSec() const
	{
		if (mbStarted == false)
		{
			cLog::Warning("Timer is not started");
			return 0.0f;
		}

		if (mbPaused == true)
			return mlPausedTicks;
		else
			return mpApplicationTime->GetTimeInMilliSec() - mlStartTicks;
	}

	float cTimer::GetTimeInSec() const
	{
		return GetTimeInMilliSec() / 1000.0f;
	}

	bool cTimer::IsStarted() const
	{
		return mbStarted;
	}

	bool cTimer::IsPaused() const
	{
		return mbPaused;
	}

	// -----------------------------------------------------------------------
}