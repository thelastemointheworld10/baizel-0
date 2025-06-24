#include <engine/Engine.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cEngine::cEngine(iEngineSetup* apEngineSetup, iAudioSystem* apAudioSystem)
	{
		cLog::Log("- Creating engine stuff");

		cLog::Log("\tEngine setup");
		mpEngineSetup = apEngineSetup;

		cLog::Log("\tGraphics");
		mpGraphics = mpEngineSetup->CreateGraphics();

		cLog::Log("\tInput");
		mpInput = mpEngineSetup->CreateInput(this, mpGraphics->GetLowLevel());

		cLog::Log("\tSystem");
		mpApplicationTime = mpEngineSetup->CreateApplicationTime();

		cLog::Log("\tTime step");
		mpTimeStep = new cTimeStep(mpApplicationTime);

		cLog::Log("\tAudio system");
		mpAudioSystem = apAudioSystem;

		cLog::Log("\tUpdater");
		mpUpdater = new cUpdater();
	}

	cEngine::~cEngine()
	{
		cLog::Log("- Deleting engine stuff");

		cLog::Log("\tGraphics");
		delete mpGraphics;
		mpGraphics = nullptr;

		cLog::Log("\tInput");
		delete mpInput;
		mpInput = nullptr;

		cLog::Log("\tSystem");
		delete mpApplicationTime;
		mpApplicationTime = nullptr;

		cLog::Log("\tTime step");
		delete mpTimeStep;
		mpTimeStep = nullptr;

		cLog::Log("\tAudio system");
		delete mpAudioSystem;
		mpAudioSystem = nullptr;

		cLog::Log("\tUpdater");
		delete mpUpdater;
		mpUpdater = nullptr;

		cLog::Log("\tEngine setup");
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

	bool cEngine::Init(const std::string& asWindowTitle, tVector2l avWindowSize, tVector2f avVirtualSize, bool abFullscreen)
	{
		cLog::Log("* ----------------------------------------------------");
		cLog::Log("* Initializing engine");
		cLog::Log("* ----------------------------------------------------");

		if (mpGraphics->GetLowLevel()->Init(asWindowTitle, avWindowSize, avVirtualSize, abFullscreen) == false)
		{
			cLog::Fatal("Failed to initialize low level graphics!");
			return false;
		}
			
		mpAudioSystem->CreateDevice();
		mpAudioSystem->CreateContext();
		mpAudioSystem->CreateListener();

		mpAudioSystem->SetDistanceModel(eDistanceModel_InverseDistanceClamped);

		return true;
	}

	void cEngine::Run()
	{
		cLog::Log("* ----------------------------------------------------");
		cLog::Log("* Running engine");
		cLog::Log("* ----------------------------------------------------");

		mpUpdater->OnStart();

		mbRunning = true;
		while (mbRunning)
		{
			mpInput->Update();
			mpTimeStep->AddFrame();

			mpGraphics->GetRenderer()->ClearColor(mpGraphics->GetRenderer()->GetClearColor());
			mpGraphics->GetRenderer()->Clear();

			mpUpdater->OnUpdate(mpTimeStep->GetTimeStep());
			mpUpdater->OnDraw();

			mpGraphics->GetRenderer()->SwapBuffers();
		}

		mpUpdater->OnExit();
	}

	void cEngine::Exit()
	{
		mbRunning = false;

		cLog::Log("* ----------------------------------------------------");
		cLog::Log("* Exiting engine");
		cLog::Log("* ----------------------------------------------------");

		mpAudioSystem->Exit();
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	iAudioSystem* cEngine::GetAudioSystem()
	{
		return mpAudioSystem;
	}

	cGraphics* cEngine::GetGraphics()
	{
		return mpGraphics;
	}

	cInput* cEngine::GetInput()
	{
		return mpInput;
	}

	iApplicationTime* cEngine::GetApplicationTime()
	{
		return mpApplicationTime;
	}

	cUpdater* cEngine::GetUpdater()
	{
		return mpUpdater;
	}

	// -----------------------------------------------------------------------
}