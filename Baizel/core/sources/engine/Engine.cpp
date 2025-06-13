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

		mpAudioSystem->SetDistanceModel(eDistanceModel_InverseDistanceClamped);

		cLog::Log("----------------------------------------------------");
		cLog::Log("Engine initialized");
		cLog::Log("----------------------------------------------------");

		return true;
	}

	void cEngine::Run()
	{
		mpAudioSystem->GetListener()->SetPosition(tVector2f(0, 0));

		iTexture* pBG = mpGraphics->GetLowLevel()->CreateTexture();
		pBG->LoadFile("textures/bg/winxp.jpg");

		cAnimation Animation(6, mpGraphics->GetLowLevel());
		Animation.SetSpeed(30.0f);
		Animation.AddFrame("textures/effects/effect_noise00.jpg");
		Animation.AddFrame("textures/effects/effect_noise01.jpg");
		Animation.AddFrame("textures/effects/effect_noise02.jpg");
		Animation.AddFrame("textures/effects/effect_noise03.jpg");
		Animation.AddFrame("textures/effects/effect_noise04.jpg");
		Animation.AddFrame("textures/effects/effect_noise05.jpg");

		iAudioBuffer* pBuffer = mpAudioSystem->CreateBuffer();
		iAudioSource* pSource = mpAudioSystem->CreateSource();

		pBuffer->LoadAudio("music/raw_test/1.ogg");
		pSource->SetBuffer(pBuffer);

		tVector2f vSoundPos(400, 300);

		pSource->SetGain(1.0f);
		pSource->SetLoop(true);
		pSource->SetRelative(false);
		pSource->SetPosition(vSoundPos);

		pSource->Play();

		tVector2f vPos = tVector2f(mpAudioSystem->GetListener()->GetPosition().ToVec2());
		tVector2f vSize = tVector2f(100, 100);
		float fSpeed = 200.0f;

		mbRunning = true;
		while (mbRunning)
		{
			mpInput->Update();
			mpTimeStep->AddFrame();

			mpGraphics->GetRenderer()->SetDrawColor(0, 0, 0);
			mpGraphics->GetRenderer()->Clear();

			mpGraphics->GetRenderer()->DrawTexture(pBG,
				tVector2f(),
				mpGraphics->GetLowLevel()->GetVirtualSize());
			
			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_W))
				vPos.y -= fSpeed * mpTimeStep->GetTimeStep();
			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_A))
				vPos.x -= fSpeed * mpTimeStep->GetTimeStep();
			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_S))
				vPos.y += fSpeed * mpTimeStep->GetTimeStep();
			if (mpInput->GetKeyboard()->GetKeyPressed(eKey_D))
				vPos.x += fSpeed * mpTimeStep->GetTimeStep();

			mpGraphics->GetRenderer()->DrawFilledRect(vPos, vSize, cColor(255, 0, 0));
			mpGraphics->GetRenderer()->DrawFilledRect(vSoundPos, vSize, cColor(0, 0, 255));

			mpAudioSystem->GetListener()->SetPosition(vPos);

			Animation.GetCurrentFrame()->SetAlpha(10);
			mpGraphics->GetRenderer()->DrawTexture(Animation.GetCurrentFrame(),
				tVector2f(),
				mpGraphics->GetLowLevel()->GetVirtualSize());
			Animation.Update(mpTimeStep->GetTimeStep());

			mpGraphics->GetRenderer()->SwapBuffers();
		}

		delete pBuffer;
		delete pSource;
		delete pBG;
	}

	void cEngine::Exit()
	{
		mbRunning = false;

		cLog::Log("----------------------------------------------------");
		cLog::Log("Exiting engine");
		cLog::Log("----------------------------------------------------");

		mpAudioSystem->Exit();
	}

	// -----------------------------------------------------------------------
}