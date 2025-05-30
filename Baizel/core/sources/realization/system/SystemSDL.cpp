#include <realization/system/SystemSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cSystemSDL::cSystemSDL()
	{
		mlStartTime = SDL_GetPerformanceCounter();
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	int cSystemSDL::GetTimeInMilliSec() const
	{
		return SDL_GetTicks64() - mlStartTime;
	}

	float cSystemSDL::GetTimeInSec() const
	{
		return SDL_GetTicks64() / 1000.0f;
	}

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	void cSystemSDL::SleepForMilliSec(int alTime) const
	{
		SDL_Delay(alTime);
	}

	void cSystemSDL::SleepForSec(int alTime) const
	{
		SDL_Delay(alTime * 1000);
	}

	// -----------------------------------------------------------------------
}