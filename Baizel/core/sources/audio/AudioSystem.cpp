#include <audio/AudioSystem.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	iAudioSystem::iAudioSystem(iAudioReader* apAudioReader)
	{
		mpAudioReader = apAudioReader;
	}

	iAudioSystem::~iAudioSystem()
	{
		delete mpAudioListener;
		mpAudioListener = nullptr;

		delete mpAudioDevice;
		mpAudioDevice = nullptr;

		delete mpAudioReader;
		mpAudioReader = nullptr;
	}
	
	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	iAudioListener* iAudioSystem::GetListener() const
	{
		return mpAudioListener;
	}

	// -----------------------------------------------------------------------
}