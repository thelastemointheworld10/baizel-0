#include <engine/Engine.h>
#include <realization/graphics/LowLevelGraphicsSDL.h>

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
		mbRunning = true;
		while (mbRunning)
		{
			mpInput->Update();

			mpGraphics->GetRenderer()->SetDrawColor(0, 0, 0);
			mpGraphics->GetRenderer()->Clear();
			
			// ----------------------------------------------------------

			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_Escape))
				mbRunning = false;

			mpGraphics->GetRenderer()->SetDrawColor(255, 0, 0);
			mpGraphics->GetRenderer()->DrawFilledRect(400, 300, 100, 100);

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