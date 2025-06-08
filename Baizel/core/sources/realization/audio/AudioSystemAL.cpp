#include <realization/audio/AudioSystemAL.h>

namespace baizel
{
    //////////////////////////////////////////////////////////////////////////
    // CONSTRUCTORS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    cAudioSystemAL::~cAudioSystemAL()
    {
        delete mpDevice;
        mpDevice = nullptr;

        delete mpDevice;
        mpDevice = nullptr;
    }

    // -----------------------------------------------------------------------

    //////////////////////////////////////////////////////////////////////////
    // PUBLIC METHODS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    //////////////////////////////////////////
    // Resource Management
    //////////////////////////////////////////

    void cAudioSystemAL::CreateDevice()
    {
        SetAudioDevices();
        const char* sDefaultDevice = mvAudioDevices[0].c_str();
        cLog::Log("Default device: %s", sDefaultDevice);

        mpDevice = alcOpenDevice(sDefaultDevice);
        if (mpDevice == nullptr)
        {
            cLog::Fatal("Failed to open default audio device");
            return;
        }

        cLog::Log("Audio device created");
    }

    void cAudioSystemAL::CreateContext()
    {
        mpContext = alcCall(alcCreateContext, mpDevice, mpDevice, nullptr);
        if (mpContext == nullptr)
        {
            cLog::Fatal("Failed to create audio context");
            return;
        }

        alcCall(alcMakeContextCurrent, mpDevice, mpContext);

        cLog::Log("Audio context created");
    }

    iAudioBuffer* cAudioSystemAL::CreateBuffer() const
    {
        return new cAudioBufferAL();
    }

    iAudioSource* cAudioSystemAL::CreateSource() const
    {
        return new cAudioSourceAL();
    }

    //////////////////////////////////////////
    // Accessors
    //////////////////////////////////////////

    void cAudioSystemAL::SetListenerPosition(const tVector3f& avPosition)
    {
        alCall(alListener3f, AL_POSITION, avPosition.x, avPosition.y, avPosition.z);
    }

    void cAudioSystemAL::SetListenerVelocity(const tVector3f& avVelocity)
    {
        alCall(alListener3f, AL_VELOCITY, avVelocity.x, avVelocity.y, avVelocity.z);
    }

    void cAudioSystemAL::SetAudioDevices()
    {
        const ALCchar* sAllDevices = alcCall(alcGetString, mpDevice, nullptr, ALC_ALL_DEVICES_SPECIFIER);
        const char* sDevice = sAllDevices;

        do
        {
            cLog::Log("Adding audio device: %s", sDevice);

            mvAudioDevices.push_back(sDevice);
            sDevice += mvAudioDevices.back().length() + 1;
        } while (*sDevice != '\0' && mvAudioDevices.size() <= gkMaxAudioDevices);
    }

    //////////////////////////////////////////
    // Runtime Control
    //////////////////////////////////////////

    void cAudioSystemAL::Exit()
    {
        alcCall(alcMakeContextCurrent, mpDevice, nullptr);
        alcCall(alcDestroyContext, mpDevice, mpContext);
        alcCall(alcCloseDevice, mpDevice, mpDevice);
    }

    // -----------------------------------------------------------------------
}