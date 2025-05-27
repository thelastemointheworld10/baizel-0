#include <realization/input/LowLevelInputSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cLowLevelInputSDL::cLowLevelInputSDL(cEngine* apEngine)
	{
		mpEngine = apEngine;
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	std::vector<SDL_Event>& cLowLevelInputSDL::GetEvents()
	{
		return mvEvents;
	}

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////
	
	void cLowLevelInputSDL::PollEvents()
	{
		SDL_Event Event;

		while (SDL_PollEvent(&Event))
		{
			mvEvents.push_back(Event);

			if (Event.type == SDL_QUIT)
			{
				mpEngine->Exit();
			}
		}
	}

	void cLowLevelInputSDL::ClearEvents()
	{
		mvEvents.clear();
		mvEvents.reserve(gkMaximumEvents);
	}
	
	// -----------------------------------------------------------------------
}