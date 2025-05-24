#ifndef BAIZEL_INPUT_H
#define BAIZEL_INPUT_H

#include <SDL2/SDL.h>

#include <engine/Log.h>

#include <input/LowLevelInput.h>
#include <input/Keyboard.h>
#include <input/Mouse.h>

namespace baizel
{
    class cInput final
    {
    public:
        cInput(iLowLevelInput* apLowLevelInput);
        ~cInput();

        iLowLevelInput* GetLowLevel();

        template <typename T>
        T* GetDevice(eInputDeviceType alInputDeviceType)
        {
            int lDeviceType = static_cast<int>(alInputDeviceType);

            if (alInputDeviceType < 0 || alInputDeviceType >= eInputDeviceType_Count)
            {
                Error("Failed to get input device! Incorrect device type value");
                return nullptr;
            }

            iInputDevice* pParentDevice = mpInputDevices[alInputDeviceType];
            if (pParentDevice == nullptr)
            {
                Error("Failed to get input device! Device with type %d not initialized", lDeviceType);
                return nullptr;
            }

            T* pResult = dynamic_cast<T*>(pParentDevice);
            if (pResult == nullptr)
            {
                Error("Failed to get input device! Type mismatch for device %d. Expected %s, got %s",
                    lDeviceType,
                    typeid(T).name(),
                    typeid(*pParentDevice).name());

                return nullptr;
            }

            return pResult;
        }
        void SetDevice(eInputDeviceType alInputDeviceType, iInputDevice* apInputDevice);

        void Update();

    private:
        iLowLevelInput* mpLowLevelInput;

        tInputDevicesArray mpInputDevices;
    };
}

#endif // BAIZEL_INPUT_H