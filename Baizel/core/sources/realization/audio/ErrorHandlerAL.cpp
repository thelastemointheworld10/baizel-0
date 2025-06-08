#include <realization/audio/ErrorHandlerAL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// GLOBAL FUNCTIONS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

    //////////////////////////////////////////
    // AL
    //////////////////////////////////////////

	bool CheckErrorsAL(const char* asFilename, std::uint_fast32_t alLine)
	{
        if (alcGetCurrentContext() == nullptr)
            return true;

        ALenum lError = alGetError();
        if (lError != AL_NO_ERROR)
        {
            cLog::Error("OpenAl Soft (%s : %d)", asFilename, alLine);
            switch (lError)
            {
            case AL_INVALID_NAME:
                cLog::Log("\tBad name (ID) was passed to an OpenAL function");
                break;
            case AL_INVALID_ENUM:
                cLog::Log("\tInvalid enum value was passed to an OpenAL function");
                break;
            case AL_INVALID_VALUE:
                cLog::Log("\tInvalid value was passed to an OpenAL function");
                break;
            case AL_INVALID_OPERATION:
                cLog::Log("\tRequested operation is not valid");
                break;
            case AL_OUT_OF_MEMORY:
                cLog::Log("\tRequested operation resulted in OpenAL running out of memory");
                break;
            default:
                cLog::Log("\tUnknown AL error: %d", lError);
            }
            
            return false;
        }

        return true;
	}

    //////////////////////////////////////////
    // ALC
    //////////////////////////////////////////

    bool CheckErrorsALC(const char* asFilename, std::uint_fast32_t alLine, ALCdevice* apDevice)
    {
        if (apDevice == nullptr)
            return true;

        ALCenum lError = alcGetError(apDevice);
        if (lError != ALC_NO_ERROR)
        {
            cLog::Error("OpenAl Soft (%s : %d)", asFilename, alLine);
            switch (lError)
            {
            case ALC_INVALID_VALUE:
                cLog::Log("\tInvalid value was passed to an OpenAL function");
                break;
            case ALC_INVALID_DEVICE:
                cLog::Log("\tBad device was passed to an OpenAL function");
                break;
            case ALC_INVALID_CONTEXT:
                cLog::Log("\tBad context was passed to an OpenAL function");
                break;
            case ALC_INVALID_ENUM:
                cLog::Log("\tUnknown enum value was passed to an OpenAL function");
                break;
            case ALC_OUT_OF_MEMORY:
                cLog::Log("\tUnknown enum value was passed to an OpenAL function");
                break;
            default:
                cLog::Log("\tUnknown ALC error: %d", lError);
            }

            return false;
        }

        return true;
    }
	
	// -----------------------------------------------------------------------
}