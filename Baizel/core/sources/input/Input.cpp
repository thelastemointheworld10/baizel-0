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
		mpLowLevelInput->UpdateInput();

		tInputDevicesListIt it = mlstDevices.begin();
		for (; it != mlstDevices.end(); ++it)
		{
			(*it)->Update();
		}
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	void cInput::SetKeyboard(iKeyboard* apKeyboard)
	{
		mpKeyboard = apKeyboard;
		mlstDevices.push_back(mpKeyboard);
	}

	iKeyboard* cInput::GetKeyboard()
	{
		return mpKeyboard;
	}
	
	// -----------------------------------------------------------------------
}