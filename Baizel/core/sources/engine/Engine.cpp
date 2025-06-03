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
			cLog::Fatal("Failed to initialize low level graphics!");
			return false;
		}

		cLog::Log("----------------------------------------------------");
		cLog::Log("Engine initialized");
		cLog::Log("----------------------------------------------------");

		return true;
	}

	void cEngine::Run()
	{
		float fSize = 64.0f;

		iFont* pFont = mpGraphics->GetLowLevel()->CreateFont();
		pFont->Load("fonts/test.ttf");

		tVector2f vPos(400, 0);
		tVector2f vPos1(400, 150);
		tVector2f vPos2(400, 300);

		pFont->SetSize(fSize);

		mbRunning = true;
		while (mbRunning)
		{
			mpInput->Update();
			mpTimeStep->AddFrame();

			mpGraphics->GetRenderer()->SetDrawColor(0, 0, 0);
			mpGraphics->GetRenderer()->Clear();

			float fSpeed = 100.0f * mpTimeStep->GetTimeStep();

			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_W))
				vPos.y -= fSpeed;
			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_A))
				vPos.x -= fSpeed;
			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_S))
				vPos.y += fSpeed;
			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_D))
				vPos.x += fSpeed;

			if (mpInput->GetMouse()->GetButtonPressed(eMouseButton_WheelDown))
				fSize -= 12.0f;
			if (mpInput->GetMouse()->GetButtonPressed(eMouseButton_WheelUp))
				fSize += 12.0f;

			pFont->SetText("center-alingn");
			pFont->Draw(vPos, cColor(100, 255, 50), eTextAlign_Center);

			pFont->SetText("left-alingn");
			pFont->Draw(vPos1, cColor(100, 255, 50), eTextAlign_Left);

			pFont->SetText("right-alingn");
			pFont->Draw(vPos2 , cColor(100, 255, 50), eTextAlign_Right);


			mpGraphics->GetRenderer()->SwapBuffers();
		}

		delete pFont;
	}

	void cEngine::Exit()
	{
		mbRunning = false;

		cLog::Log("----------------------------------------------------");
		cLog::Log("Exiting engine");
		cLog::Log("----------------------------------------------------");
	}

	// -----------------------------------------------------------------------
}