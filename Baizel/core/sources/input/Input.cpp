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
		tInputDevicesListIt it = mlstDevices.begin();
		for (; it != mlstDevices.end(); ++it)
		{
			delete (*it);
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

		tInputDevicesListIt it = mlstDevices.begin();
		for (; it != mlstDevices.end(); ++it)
		{
			(*it)->Update();
		}

		mpLowLevelInput->ClearEvents();
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

	iLowLevelInput* cInput::GetLowLevel()
	{
		return mpLowLevelInput;
	}
	
	// -----------------------------------------------------------------------
}