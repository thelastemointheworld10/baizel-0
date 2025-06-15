#include <realization/time/ApplicationTimeSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	int cApplicationTimeSDL::GetTimeInMilliSec() const
	{
		return static_cast<int>(SDL_GetTicks64());
	}

	float cApplicationTimeSDL::GetTimeInSec() const
	{
		return SDL_GetTicks64() / 1000.0f;
	}

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	void cApplicationTimeSDL::SleepForMilliSec(int alTime) const
	{
		SDL_Delay(static_cast<Uint32>(alTime));
	}

	void cApplicationTimeSDL::SleepForSec(int alTime) const
	{
		SDL_Delay(static_cast<Uint32>(alTime * 1000));
	}

	// -----------------------------------------------------------------------
}