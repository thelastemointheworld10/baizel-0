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
		cAnimation* pAnimation = new cAnimation(13, mpGraphics->GetLowLevel());
		pAnimation->SetSpeed(64.0f);
		pAnimation->AddFrame("textures/raw_test/01.png");
		pAnimation->AddFrame("textures/raw_test/02.png");
		pAnimation->AddFrame("textures/raw_test/03.png");
		pAnimation->AddFrame("textures/raw_test/04.png");
		pAnimation->AddFrame("textures/raw_test/05.png");
		pAnimation->AddFrame("textures/raw_test/06.png");
		pAnimation->AddFrame("textures/raw_test/07.png");
		pAnimation->AddFrame("textures/raw_test/08.png");
		pAnimation->AddFrame("textures/raw_test/09.png");
		pAnimation->AddFrame("textures/raw_test/10.png");
		pAnimation->AddFrame("textures/raw_test/11.png");
		pAnimation->AddFrame("textures/raw_test/12.png");
		pAnimation->AddFrame("textures/raw_test/13.png");

		cAnimation* pAnim2 = new cAnimation(13, mpGraphics->GetLowLevel());
		*pAnim2 = *pAnimation;
		pAnim2->SetSpeed(12.0f);

		mbRunning = true;
		while (mbRunning)
		{
			mpInput->Update();

			mpGraphics->GetRenderer()->SetDrawColor(0, 0, 0);
			mpGraphics->GetRenderer()->Clear();

			pAnimation->Update(mpTimeStep->GetTimeStep());
			pAnim2->Update(mpTimeStep->GetTimeStep());

			mpGraphics->GetRenderer()->DrawTexture(pAnimation->GetCurrentFrame(), 0, 0,
				118 * 4,
				59 * 4);
			mpGraphics->GetRenderer()->DrawTexture(pAnim2->GetCurrentFrame(), 0, 59*4,
				118 * 4,
				59 * 4);

			mpGraphics->GetRenderer()->SwapBuffers();
			mpTimeStep->AddFrame();
		}

		delete pAnimation;
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