#include <impl/audio/AudioDeviceAL.h>

namespace baizel
{
    //////////////////////////////////////////////////////////////////////////
    // CONSTRUCTORS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    cAudioDeviceAL::cAudioDeviceAL()
    {
        mvAudioDevices.reserve(gkMaxAudioDevices);
        InitializeDevices();
    }

    cAudioDeviceAL::~cAudioDeviceAL()
    {
        if (mpAudioDevice == nullptr)
            return;

        alcCall(alcCloseDevice, mpAudioDevice, mpAudioDevice);
        mpAudioDevice = nullptr;
    }

    // -----------------------------------------------------------------------

    //////////////////////////////////////////////////////////////////////////
    // PUBLIC METHODS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    //////////////////////////////////////////
    // Runtime Control
    //////////////////////////////////////////

    void cAudioDeviceAL::InitializeDevices()
    {
        const ALCchar* sAllDevices = alcCall(alcGetString, mpAudioDevice, nullptr, ALC_ALL_DEVICES_SPECIFIER);
        const char* sDevice = sAllDevices;

        if (sDevice == nullptr)
        {
            cLog::Warning("There are no audio devices!");
            return;
        }

        do
        {
            //cLog::Log("Found audio device: %s", sDevice);
            mvAudioDevices.push_back(sDevice);
            sDevice += mvAudioDevices.back().length() + 1;
        } while (*sDevice != '\0' && mvAudioDevices.size() <= gkMaxAudioDevices);
    }

    //////////////////////////////////////////
    // Accessors
    //////////////////////////////////////////

    void cAudioDeviceAL::SetDevice(const std::string& asName)
    {
        if (mpAudioDevice != nullptr)
            alcCloseDevice(mpAudioDevice);

        cLog::Log("Opening audio device: %s", asName.c_str());
        mpAudioDevice = alcOpenDevice(asName.c_str());
        if (mpAudioDevice == nullptr)
        {
            cLog::Fatal("Failed to open audio device '%s'!", asName.c_str());
        }
    }

    ALCdevice* cAudioDeviceAL::GetALCDevice() const
    {
        return mpAudioDevice;
    }

    // -----------------------------------------------------------------------
}