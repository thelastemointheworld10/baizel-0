#include <engine/Engine.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////
	
	// -----------------------------------------------------------------------
	
	cEngine::cEngine(iEngineSetup* apGameSetup)
	{
		mpEngineSetup = apGameSetup;

		mpGraphics = apGameSetup->CreateGraphics();
		mpInput = apGameSetup->CreateInput(this, mpGraphics->GetLowLevel());
	}

	cEngine::~cEngine()
	{
		Log("- Deleting engine stuff");

		Log("  Graphics");
		delete mpGraphics;
		mpGraphics = nullptr;

		Log("  Input");
		delete mpInput;
		mpInput = nullptr;

		Log("  Game Setup");
		delete mpEngineSetup;
		mpEngineSetup = nullptr;
	}
	
	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	bool cEngine::Init(const char* asWindowTitle, tVector2l avWindowSize, bool abFullscreen)
	{
		if (mpGraphics->GetLowLevel()->Init(asWindowTitle, avWindowSize, abFullscreen) == false)
		{
			Fatal("Failed to initialize Graphics!");
			return false;
		}

		Log("----------------------------------------------------");
		Log("Engine initialized");
		Log("----------------------------------------------------");

		return true;
	}

	void cEngine::Run()
	{
		tVector2f vPos(0.0f);
		float fSpeed = 0.06f;

		mbRunning = true;
		while (mbRunning)
		{
			mpInput->Update();

			mpGraphics->GetRenderer()->SetDrawColor(132, 156, 173);
			mpGraphics->GetRenderer()->Clear();
			
			// ----------------------------------------------------------

			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_Escape))
				Exit();

			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_W))
				vPos.y -= fSpeed;
			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_S))
				vPos.y += fSpeed;
			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_A))
				vPos.x -= fSpeed;
			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_D))
				vPos.x += fSpeed;
			
			if (mpInput->GetMouse()->GetButtonPressed(eMouseButton_WheelDown))
				Log("Random int number: %d", cMath::GetRandInt(0, 10));
			if (mpInput->GetMouse()->GetButtonPressed(eMouseButton_WheelUp))
				Log("Random float number: %f", cMath::GetRandFloat(0.0f, 10.0f));

			mpGraphics->GetRenderer()->SetDrawColor(214, 122, 122);
			mpGraphics->GetRenderer()->DrawFilledRect(vPos.x, vPos.y, 100, 100);

			// ----------------------------------------------------------

			mpGraphics->GetRenderer()->SwapBuffers();
		}
	}

	void cEngine::Exit()
	{
		Log("----------------------------------------------------");
		Log("Exiting engine");
		Log("----------------------------------------------------");

		mbRunning = false;
	}

	// -----------------------------------------------------------------------
}