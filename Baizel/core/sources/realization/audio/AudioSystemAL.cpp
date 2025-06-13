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

    void cAudioSystemAL::SetDistanceModel(eDistanceModel aDistanceModel) const
    {
        ALenum lDistanceModel;
        switch (aDistanceModel)
        {
        case eDistanceModel_None:
            lDistanceModel = AL_NONE;
            break;
        case eDistanceModel_InverseDistance:
            lDistanceModel = AL_INVERSE_DISTANCE;
            break;
        case eDistanceModel_InverseDistanceClamped:
            lDistanceModel = AL_INVERSE_DISTANCE_CLAMPED;
            break;
        case eDistanceModel_LinearDistance:
            lDistanceModel = AL_LINEAR_DISTANCE;
            break;
        case eDistanceModel_LinearDistanceClamped:
            lDistanceModel = AL_LINEAR_DISTANCE_CLAMPED;
            break;
        case eDistanceModel_ExponentDistance:
            lDistanceModel = AL_EXPONENT_DISTANCE;
            break;
        case eDistanceModel_ExponentDistanceClamped:
            lDistanceModel = AL_EXPONENT_DISTANCE_CLAMPED;
            break;
        default:
            lDistanceModel = AL_NONE;
            break;
        }

        alCall(alDistanceModel, lDistanceModel);
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