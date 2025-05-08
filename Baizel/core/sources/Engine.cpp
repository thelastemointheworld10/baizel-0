#include <Engine.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////
	
	// -----------------------------------------------------------------------
	
	cEngine::cEngine(iGameSetup* apGameSetup)
	{
		mpGameSetup = apGameSetup;
		mpGraphics = apGameSetup->CreateGraphics();
		mpInput = apGameSetup->CreateInput(this);
	}

	cEngine::~cEngine()
	{
		Log("destructor of cEngine called");

		delete mpGraphics;
		mpGraphics = nullptr;

		delete mpInput;
		mpInput = nullptr;

		delete mpGameSetup;
		mpGameSetup = nullptr;
	}
	
	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

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

		return true;
	}

	void cEngine::Run()
	{
		mbRunning = true;
		while (mbRunning)
		{
			mpInput->Update();
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