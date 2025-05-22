#include <realization/LowLevelInputSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cLowLevelInputSDL::cLowLevelInputSDL(cEngine* apEngine, iLowLevelGraphics* apGraphics)
	{
		mpEngine = apEngine;
		mpGraphics = apGraphics;
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------
	
	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////
	
	void cLowLevelInputSDL::UpdateInput()
	{
		SDL_PumpEvents();

		SDL_Event SDLEvent[gkMaximumEvents];
		int lEventsCount = SDL_PeepEvents(
			SDLEvent, // Array where events will be recorded
			gkMaximumEvents, // Maximum number of events to extract
			SDL_GETEVENT, // What to do with events
			SDL_QUIT, // Minimum event type
			SDL_QUIT // Maximum event type
		);

		if (lEventsCount < 0)
			return;

		for (size_t i = 0; i < lEventsCount; ++i)
		{
			switch (SDLEvent[i].type)
			{
			case SDL_QUIT:
				mpEngine->Exit();
				break;
			}
		}
	}
	
	// -----------------------------------------------------------------------
}