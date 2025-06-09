#include <engine/Engine.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cEngine::cEngine(iEngineSetup* apEngineSetup, iAudioSystem* apAudioSystem)
	{
		mpEngineSetup = apEngineSetup;
		mpAudioSystem = apAudioSystem;

		cLog::Log("- Creating engine stuff");

		cLog::Log("\tGraphics");
		mpGraphics = mpEngineSetup->CreateGraphics();

		cLog::Log("\tInput");
		mpInput = mpEngineSetup->CreateInput(this, mpGraphics->GetLowLevel());

		cLog::Log("\tSystem");
		mpSystem = mpEngineSetup->CreateSystem();

		cLog::Log("\tTime step");
		mpTimeStep = new cTimeStep(mpSystem);

		cLog::Log("----------------------------------------------------");
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
		delete mpSystem;
		mpSystem = nullptr;

		cLog::Log("\tTime step");
		delete mpTimeStep;
		mpTimeStep = nullptr;

		cLog::Log("\tAudio system");
		delete mpAudioSystem;
		mpAudioSystem = nullptr;

		cLog::Log("\tGame setup");
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
			cLog::Fatal("Failed to initialize low level graphics!");
			return false;
		}

		cLog::Log("----------------------------------------------------");
			
		mpAudioSystem->CreateDevice();
		mpAudioSystem->CreateContext();
		mpAudioSystem->CreateListener();

		mpAudioSystem->GetListener()->SetMasterGain(1.0f);

		cLog::Log("----------------------------------------------------");
		cLog::Log("Engine initialized");
		cLog::Log("----------------------------------------------------");

		return true;
	}

	void cEngine::Run()
	{
		iAudioBuffer* pBuffer = mpAudioSystem->CreateBuffer();
		iAudioSource* pSource = mpAudioSystem->CreateSource();

		pBuffer->LoadAudio("music/raw_test/1.ogg");
		pSource->SetBufferID(pBuffer->GetID());

		pSource->SetGain(1.0f);
		pSource->SetLoop(false);

		mbRunning = true;
		while (mbRunning)
		{
			mpInput->Update();
			mpTimeStep->AddFrame();

			mpGraphics->GetRenderer()->SetDrawColor(0, 0, 0);
			mpGraphics->GetRenderer()->Clear();

			if (mpInput->GetKeyboard()->GetLastKey() == eKey_Space)
				pSource->Play();

			mpGraphics->GetRenderer()->SwapBuffers();
		}

		delete pBuffer;
		delete pSource;
	}

	void cEngine::Exit()
	{
		mbRunning = false;

		mpAudioSystem->Exit();

		cLog::Log("----------------------------------------------------");
		cLog::Log("Exiting engine");
		cLog::Log("----------------------------------------------------");
	}

	// -----------------------------------------------------------------------
}