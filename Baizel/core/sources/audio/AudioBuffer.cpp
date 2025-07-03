#include <audio/AudioBuffer.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	iAudioBuffer::iAudioBuffer(iAudioReader* apAudioReader)
	{
		mpAudioReader = apAudioReader;
		mpAudioFile = mpAudioReader->CreateOggFile();
	}

	iAudioBuffer::~iAudioBuffer()
	{
		delete mpAudioFile;
		mpAudioFile = nullptr;
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	bool iAudioBuffer::LoadAudio(const std::string& asPath)
	{
		if (mpAudioFile->LoadFile(asPath))
		{
			SetFormat(mpAudioFile->GetChannels());
			SetData(); // рустемчик <3
			return true;
		}

		return false;
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	uint32_t iAudioBuffer::GetID() const
	{
		return mlBufferID;
	}

	// -----------------------------------------------------------------------
}