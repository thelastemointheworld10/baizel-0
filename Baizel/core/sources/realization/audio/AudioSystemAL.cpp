#include <realization/audio/AudioSystemAL.h>

namespace baizel
{
    //////////////////////////////////////////////////////////////////////////
    // CONSTRUCTORS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    cAudioSystemAL::~cAudioSystemAL()
    {
        mpContext = nullptr;
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
        mpAudioDevice = new cAudioDeviceAL();
        mpAudioDevice->SetDevice(mpAudioDevice->GetDefaultDevice());

        cLog::Log("Audio device created");
    }

    void cAudioSystemAL::CreateContext()
    {
        ALCdevice* pDevice = dynamic_cast<cAudioDeviceAL*>(mpAudioDevice)->GetALCDevice();

        mpContext = alcCall(alcCreateContext, pDevice, pDevice, nullptr);
        if (mpContext == nullptr)
        {
            cLog::Fatal("Failed to create audio context");
            return;
        }

        alcCall(alcMakeContextCurrent, pDevice, mpContext);

        cLog::Log("Audio context created");
    }

    void cAudioSystemAL::CreateListener()
    {
        mpAudioListener = new cAudioListenerAL();
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
    // Runtime Control
    //////////////////////////////////////////

    void cAudioSystemAL::Exit()
    {
        alcMakeContextCurrent(nullptr);
        alcDestroyContext(mpContext);
    }

    // -----------------------------------------------------------------------
}