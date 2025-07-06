#include <engine/Engine.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cEngine::cEngine(iEngineSetup* apEngineSetup, iAudioSystem* apAudioSystem, iXMLReader* apXMLReader)
	{
		cLog::Log("- Creating engine stuff");

		cLog::Log("\tEngine setup");
		mpEngineSetup = apEngineSetup;

		cLog::Log("\tAudio system");
		mpAudioSystem = apAudioSystem;

		cLog::Log("\tXML reader");
		mpXMLReader = apXMLReader;

		cLog::Log("\tGraphics");
		mpGraphics = mpEngineSetup->CreateGraphics();

		cLog::Log("\tInput");
		mpInput = mpEngineSetup->CreateInput(this, mpGraphics->GetLowLevel());

		cLog::Log("\tApplication time");
		mpApplicationTime = mpEngineSetup->CreateApplicationTime();

		cLog::Log("\tUpdater");
		mpUpdater = new cUpdater();

		cLog::Log("\tTime step");
		mpTimeStep = new cTimeStep(mpApplicationTime);
	}

	cEngine::~cEngine()
	{
		cLog::Log("- Deleting engine stuff");

		cLog::Log("\tAudio system");
		delete mpAudioSystem;
		mpAudioSystem = nullptr;

		cLog::Log("\tXML reader");
		delete mpXMLReader;
		mpXMLReader = nullptr;

		cLog::Log("\tGraphics");
		delete mpGraphics;
		mpGraphics = nullptr;

		cLog::Log("\tInput");
		delete mpInput;
		mpInput = nullptr;

		cLog::Log("\tApplication time");
		delete mpApplicationTime;
		mpApplicationTime = nullptr;

		cLog::Log("\tUpdater");
		delete mpUpdater;
		mpUpdater = nullptr;

		cLog::Log("\tTime step");
		delete mpTimeStep;
		mpTimeStep = nullptr;

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
			cLog::Error("Failed to initialize low level graphics!");
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

	iAudioSystem* cEngine::GetAudioSystem() const
	{
		return mpAudioSystem;
	}

	iXMLReader* cEngine::GetXMLReader() const
	{
		return mpXMLReader;
	}

	cGraphics* cEngine::GetGraphics() const
	{
		return mpGraphics;
	}

	cInput* cEngine::GetInput() const
	{
		return mpInput;
	}

	iApplicationTime* cEngine::GetApplicationTime() const
	{
		return mpApplicationTime;
	}

	cUpdater* cEngine::GetUpdater() const
	{
		return mpUpdater;
	}

	// -----------------------------------------------------------------------
}