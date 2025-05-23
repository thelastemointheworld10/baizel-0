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

		mpGraphics->GetLowLevel()->GetRenderer()->SetClearColor(255, 255, 255);

		return true;
	}

	void cEngine::Run()
	{
		iTexture* pTex = mpGraphics->GetLowLevel()->CreateTexture();
		pTex->Load("textures/raw_test/00_raw.png");

		mbRunning = true;
		while (mbRunning)
		{
			mpInput->Update();

			mpGraphics->GetLowLevel()->GetRenderer()->Clear();
			mpGraphics->GetLowLevel()->GetRenderer()->Copy(pTex);
			mpGraphics->GetLowLevel()->GetRenderer()->SwapBuffers();
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