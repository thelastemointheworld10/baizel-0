#include <engine/Engine.h>
#include <realization/LowLevelGraphicsSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////
	
	// -----------------------------------------------------------------------
	
	cEngine::cEngine(iEngineSetup* apGameSetup)
	{
		mpGameSetup = apGameSetup;

		mpGraphics = apGameSetup->CreateGraphics();
		mpInput = apGameSetup->CreateInput(this, mpGraphics);
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
		delete mpGameSetup;
		mpGameSetup = nullptr;
	}
	
	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	bool cEngine::Init(const char* asWindowTitle, cVector2l avWindowSize, bool abFullscreen)
	{
		if (mpGraphics->Init(asWindowTitle, avWindowSize, abFullscreen) == false)
		{
			Fatal("Failed to initialize Graphics!");
			return false;
		}

		Log("----------------------------------------------------");
		Log("Engine initialized");
		Log("----------------------------------------------------");

		mpGraphics->GetRenderer()->SetClearColor(255, 255, 255);

		return true;
	}

	void cEngine::Run()
	{
		iTexture* pTex = mpGraphics->CreateTexture();
		pTex->Load("textures/raw_test/00_raw.png");

		mbRunning = true;
		while (mbRunning)
		{
			mpInput->Update();

			if (mpInput->GetKeyboard()->GetKeyPressed(eKey::eKey_0))
			{
				Log("0 is pressed");
			}

			mpGraphics->GetRenderer()->Clear();
			mpGraphics->GetRenderer()->Copy(pTex);
			mpGraphics->GetRenderer()->SwapBuffers();
		}

		delete pTex;
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