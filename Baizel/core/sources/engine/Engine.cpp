#include <engine/Engine.h>

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
		cLog::Log("- Deleting engine stuff");

		cLog::Log("  Graphics");
		delete mpGraphics;
		mpGraphics = nullptr;

		cLog::Log("  Input");
		delete mpInput;
		mpInput = nullptr;

		cLog::Log("  Game Setup");
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
		if (avWindowSize == tVector2l(0, 0))
		{
			cLog::Warning("Window size is 0 x 0! Setting 640 x 480 by default");
			avWindowSize = tVector2l(640, 480);
		}

		if (mpGraphics->GetLowLevel()->Init(asWindowTitle, avWindowSize, abFullscreen) == false)
		{
			cLog::Fatal("Failed to initialize Graphics!");
			return false;
		}

		cLog::Log("----------------------------------------------------");
		cLog::Log("Engine initialized");
		cLog::Log("----------------------------------------------------");

		return true;
	}

	void cEngine::Run()
	{
		/////////////////////////////////
		// Player position and
		// speed
		tVector2f vPos(0.0f);
		float fSpeed = 0.06f;

		/////////////////////////////////
		// Loading player texture
		iTexture* pPlayerTexture = mpGraphics->GetLowLevel()->CreateTexture();
		pPlayerTexture->Load("textures/raw_test/00.png");

		mbRunning = true;
		while (mbRunning)
		{
			mpInput->Update();

			mpGraphics->GetRenderer()->SetDrawColor(132, 156, 173);
			mpGraphics->GetRenderer()->Clear();
			
			// ----------------------------------------------------------

			/////////////////////////////////
			// Player movement
			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_W))
				vPos.y -= fSpeed;
			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_S))
				vPos.y += fSpeed;
			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_A))
				vPos.x -= fSpeed;
			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_D))
				vPos.x += fSpeed;

			/////////////////////////////////
			// The player turns into a
			// random color when pressing space
			if (mpInput->GetKeyboard()->GetLastKey() == eKey_Space)
			{
				uint8_t lRed = cMath::GetRandInt(50, 255);
				uint8_t lGreen = cMath::GetRandInt(50, 255);
				uint8_t lBlue = cMath::GetRandInt(50, 255);

				cLog::Log("New player color: %d %d %d", lRed, lGreen, lBlue);

				pPlayerTexture->SetColor(lRed, lGreen, lBlue);
			}

			/////////////////////////////////
			// The player turns into a
			// random alpha when pressing left alt
			if (mpInput->GetKeyboard()->GetLastKey() == eKey_LeftAlt)
			{
				uint8_t lAlpha = cMath::GetRandInt(0, 255);

				cLog::Log("New player alpha: %d", lAlpha);

				pPlayerTexture->SetAlpha(lAlpha);
			}

			
			mpGraphics->GetRenderer()->DrawTexture(pPlayerTexture, vPos.x, vPos.y, 100, 100);

			// ----------------------------------------------------------

			mpGraphics->GetRenderer()->SwapBuffers();
		}

		delete pPlayerTexture;
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