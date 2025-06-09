#include <audio/AudioDevice.h>

namespace baizel
{
    //////////////////////////////////////////////////////////////////////////
    // PUBLIC METHODS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------

    //////////////////////////////////////////
    // Accessors
    //////////////////////////////////////////

    const tAudioDevicesVec& iAudioDevice::GetAvialableDevices() const
    {
        return mvAudioDevices;
    }

    const std::string& iAudioDevice::GetDefaultDevice() const
    {
        if (mvAudioDevices.size() > 0)
        {
            return mvAudioDevices[0];
        }
        else
        {
            cLog::Error("There is no audio devices yet!");
            return "";
        }
    }

    // -----------------------------------------------------------------------
}