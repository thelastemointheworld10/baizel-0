#include <input/Input.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////
	
	// -----------------------------------------------------------------------
	
	cInput::cInput(iLowLevelInput* apLowLevelInput)
	{
		mpLowLevelInput = apLowLevelInput;
	}

	cInput::~cInput()
	{
		for (iInputDevice* pInputDevice : mpInputDevices)
		{
			delete pInputDevice;
		}

		delete mpLowLevelInput;
		mpLowLevelInput = nullptr;
	}
	
	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------
	
	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	void cInput::Update()
	{
		mpLowLevelInput->PollEvents();

		for (iInputDevice* pInputDevice : mpInputDevices)
		{
			if (pInputDevice == nullptr)
				continue;

			pInputDevice->Update();
		}

		mpLowLevelInput->ClearEvents();
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	iLowLevelInput* cInput::GetLowLevel() const
	{
		return mpLowLevelInput;
	}

	iKeyboard* cInput::GetKeyboard()
	{
		return GetDevice<iKeyboard>(eInputDeviceType_Keyboard);
	}

	iMouse* cInput::GetMouse()
	{
		return GetDevice<iMouse>(eInputDeviceType_Mouse);
	}

	void cInput::SetDevice(eInputDeviceType alInputDeviceType, iInputDevice* apInputDevice)
	{
		int lDeviceType = static_cast<int>(alInputDeviceType);

		cLog::Log("Setting input device of type %d as %s", lDeviceType, typeid(apInputDevice).name());

		if (alInputDeviceType < 0 || alInputDeviceType >= eInputDeviceType_Count)
		{
			cLog::Error("Failed to set input device! Invalid device type: %d", lDeviceType);
			return;
		}

		if (apInputDevice == nullptr)
		{
			cLog::Error("Trying to set nullptr device for type %d", lDeviceType);
			return;
		}

		if (mpInputDevices[alInputDeviceType] != nullptr)
			delete mpInputDevices[alInputDeviceType];

		mpInputDevices[alInputDeviceType] = apInputDevice;
	}
	
	// -----------------------------------------------------------------------
}