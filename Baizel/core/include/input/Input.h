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

        iKeyboard* GetKeyboard();
        iMouse* GetMouse();
        void SetDevice(eInputDeviceType alInputDeviceType, iInputDevice* apInputDevice);

        void Update();

    private:
        template <typename T>
        T* GetDevice(eInputDeviceType alInputDeviceType)
        {
            int lDeviceType = static_cast<int>(alInputDeviceType);

            if (alInputDeviceType < 0 || alInputDeviceType >= eInputDeviceType_Count)
            {
                cLog::Error("Failed to get input device! Invalid device type: %d", lDeviceType);
                return nullptr;
            }

            iInputDevice* pParentDevice = mpInputDevices[alInputDeviceType];
            if (pParentDevice == nullptr)
            {
                cLog::Error("Failed to get input device! Device with type %d not initialized", lDeviceType);
                return nullptr;
            }

            T* pResult = dynamic_cast<T*>(pParentDevice);
            if (pResult == nullptr)
            {
                cLog::Error("Failed to get input device! Type mismatch for device %d. Expected %s, got %s",
                    lDeviceType,
                    typeid(T).name(),
                    typeid(*pParentDevice).name());

                return nullptr;
            }

            return pResult;
        }

    private:
        iLowLevelInput* mpLowLevelInput = nullptr;
        tInputDevicesArray mpInputDevices = {};
    };
}

#endif // BAIZEL_INPUT_H