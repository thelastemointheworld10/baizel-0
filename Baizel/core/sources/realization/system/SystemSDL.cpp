#include <realization/system/SystemSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	int cSystemSDL::GetTimeInMilliSec() const
	{
		return static_cast<int>(SDL_GetTicks64());
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
		SDL_Delay(static_cast<Uint32>(alTime));
	}

	void cSystemSDL::SleepForSec(int alTime) const
	{
		SDL_Delay(static_cast<Uint32>(alTime * 1000));
	}

	// -----------------------------------------------------------------------
}