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

		cLog::Log("   Game setup");
		delete mpEngineSetup;
		mpEngineSetup = nullptr;

		cLog::Log("   System");
		delete mpSystem;
		mpSystem = nullptr;

		cLog::Log("   Time step");
		delete mpTimeStep;
		mpTimeStep = nullptr;
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
		cAnimation Animation(13, mpGraphics->GetLowLevel());
		Animation.SetSpeed(24);
		Animation.AddFrame("textures/raw_test/01.png");
		Animation.AddFrame("textures/raw_test/02.png");
		Animation.AddFrame("textures/raw_test/03.png");
		Animation.AddFrame("textures/raw_test/04.png");
		Animation.AddFrame("textures/raw_test/05.png");
		Animation.AddFrame("textures/raw_test/06.png");
		Animation.AddFrame("textures/raw_test/07.png");
		Animation.AddFrame("textures/raw_test/08.png");
		Animation.AddFrame("textures/raw_test/09.png");
		Animation.AddFrame("textures/raw_test/10.png");
		Animation.AddFrame("textures/raw_test/11.png");
		Animation.AddFrame("textures/raw_test/12.png");
		Animation.AddFrame("textures/raw_test/13.png");

		mbRunning = true;
		while (mbRunning)
		{
			mpInput->Update();

			mpGraphics->GetRenderer()->SetDrawColor(0, 0, 0);
			mpGraphics->GetRenderer()->Clear();

			Animation.Update(mpTimeStep->GetTimeStep());
			mpGraphics->GetRenderer()->DrawTexture(Animation.GetCurrentFrame(), 0, 0,
				mpGraphics->GetLowLevel()->GetVirtualSize().x,
				mpGraphics->GetLowLevel()->GetVirtualSize().y);

			mpGraphics->GetRenderer()->SwapBuffers();
			mpTimeStep->AddFrame();
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