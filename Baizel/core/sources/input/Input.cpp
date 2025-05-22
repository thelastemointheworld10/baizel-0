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

	iLowLevelInput* cInput::GetLowLevel()
	{
		return mpLowLevelInput;
	}

	iKeyboard* cInput::GetKeyboard()
	{
		return mpKeyboard;
	}

	void cInput::SetKeyboard(iKeyboard* apKeyboard)
	{
		mpKeyboard = apKeyboard;
		mlstDevices.push_back(mpKeyboard);
	}

	iMouse* cInput::GetMouse()
	{
		return mpMouse;
	}

	void cInput::SetMouse(iMouse* apMouse)
	{
		mpMouse = apMouse;
		mlstDevices.push_back(mpMouse);
	}
	
	// -----------------------------------------------------------------------
}