#include <audio/AudioBuffer.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	bool iAudioBuffer::LoadAudio(const std::string& asPath)
	{
		Reset(); // old data

		int lError;
		mpVorbis = stb_vorbis_open_filename(asPath.c_str(), &lError, nullptr);
		if (mpVorbis == nullptr)
		{
			cLog::Error("Failed to load vorbis file '%s'! %d", asPath.c_str(), lError);
			return false;
		}

		// info about vorbis file
		stb_vorbis_info Info = stb_vorbis_get_info(mpVorbis);
		mlChannels = Info.channels;
		mlSampleRate = Info.sample_rate;

		// loading samples
		const int klTotalSamples = stb_vorbis_stream_length_in_samples(mpVorbis) * mlChannels;
		mvPCMData.resize(klTotalSamples);
		const int klSamplesRead = stb_vorbis_get_samples_short_interleaved(mpVorbis, mlChannels, mvPCMData.data(), klTotalSamples);
		if (klSamplesRead * mlChannels < klTotalSamples)
		{
			cLog::Error("Failed to read PCM data '%s'! Readed %d/%d", asPath.c_str(), klSamplesRead * mlChannels, klTotalSamples);
			stb_vorbis_close(mpVorbis);
			return false;
		}

		SetFormat(mlChannels);
		if (mlFormat == 0)
		{
			stb_vorbis_close(mpVorbis);
			return false;
		}

		SetData(); // alBufferData

		stb_vorbis_close(mpVorbis);
		cLog::Log("Audio data loaded: '%s'", asPath.c_str());

		return true;
	}

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	void iAudioBuffer::Reset()
	{
		if (mpVorbis != nullptr)
			stb_vorbis_close(mpVorbis);

		mlFormat = 0;
		mlChannels = 0;
		mlSampleRate = 0;
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	uint32_t iAudioBuffer::Get() const
	{
		return mlBufferID;
	}

	// -----------------------------------------------------------------------
}