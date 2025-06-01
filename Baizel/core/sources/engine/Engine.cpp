#include <engine/Engine.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cEngine::cEngine(iEngineSetup* apEngineSetup)
	{
		mpEngineSetup = apEngineSetup;

		cLog::Log("- Creating engine stuff");

		cLog::Log("   Graphics");
		mpGraphics = mpEngineSetup->CreateGraphics();

		cLog::Log("   Input");
		mpInput = mpEngineSetup->CreateInput(this, mpGraphics->GetLowLevel());

		cLog::Log("   System");
		mpSystem = mpEngineSetup->CreateSystem();

		cLog::Log("   Time step");
		mpTimeStep = new cTimeStep(mpSystem);

		cLog::Log("----------------------------------------------------");
	}

	cEngine::~cEngine()
	{
		cLog::Log("- Deleting engine stuff");

		cLog::Log("   Graphics");
		delete mpGraphics;
		mpGraphics = nullptr;

		cLog::Log("   Input");
		delete mpInput;
		mpInput = nullptr;

		cLog::Log("   System");
		delete mpSystem;
		mpSystem = nullptr;

		cLog::Log("   Time step");
		delete mpTimeStep;
		mpTimeStep = nullptr;

		cLog::Log("   Game setup");
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

	bool cEngine::Init(std::string asWindowTitle, tVector2l avWindowSize, bool abFullscreen)
	{
		if (mpGraphics->GetLowLevel()->Init(asWindowTitle, avWindowSize, abFullscreen) == false)
		{
			cLog::Fatal("Failed to initialize graphics!");
			return false;
		}

		cLog::Log("----------------------------------------------------");
		cLog::Log("Engine initialized");
		cLog::Log("----------------------------------------------------");

		return true;
	}

	void cEngine::Run()
	{
		mbRunning = true;
		while (mbRunning)
		{
			mpInput->Update();
			mpTimeStep->AddFrame();

			mpGraphics->GetRenderer()->SetDrawColor(0, 0, 0);
			mpGraphics->GetRenderer()->Clear();

			mpGraphics->GetRenderer()->SwapBuffers();
		}
	}

	void cEngine::Exit()
	{
		cLog::Log("----------------------------------------------------");
		cLog::Log("Exiting engine");
		cLog::Log("----------------------------------------------------");

		mbRunning = false;
	}

	// -----------------------------------------------------------------------
}