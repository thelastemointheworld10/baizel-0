#include <Player.h>

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------

cPlayer::cPlayer(iAudioSystem* apAudioSystem, cGraphics* apGraphics, cInput* apInput, iApplicationTime* apApplicationTime)
{
	mpAudioSystem = apAudioSystem;
	mpGraphics = apGraphics;
	mpInput = apInput;
	mpStepTimer = new cTimer(apApplicationTime);
	mpWalkAnimation = new cAnimation(3, mpGraphics->GetLowLevel());
}

cPlayer::~cPlayer()
{
	delete mpAudioSource;
	mpAudioSource = nullptr;

	delete mpStepBuffer;
	mpAudioSource = nullptr;

	delete mpStepTimer;
	mpStepTimer = nullptr;
}

// -----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS
//////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------

//////////////////////////////////////////
// Runtime Control
//////////////////////////////////////////

void cPlayer::Init()
{
	mpPlayerTexture = mpGraphics->GetLowLevel()->CreateTexture();

	mpAudioSource = mpAudioSystem->CreateSource();
	mpStepBuffer = mpAudioSystem->CreateBuffer();

	mvPosition = tVector2f(400, 300);
	mvSize = tVector2f(150, 150);
	mvCenter = mvSize / 2.0f;
}

void cPlayer::OnStart()
{
	mpWalkAnimation->AddFrame("textures/player/player_walk_02.png");
	mpWalkAnimation->AddFrame("textures/player/player_walk_01.png");
	mpWalkAnimation->AddFrame("textures/player/player_walk_02.png");
	mpWalkAnimation->AddFrame("textures/player/player_walk_03.png");
	mpPlayerTexture = mpWalkAnimation->GetCurrentFrame();

	mpStepBuffer->LoadAudio("sounds/player/player_step_wood.ogg");
	mpAudioSource->SetBuffer(mpStepBuffer);

	mpStepTimer->Start();
}

void cPlayer::OnUpdate(float afTimeStep)
{
	bool bDidMove = false;
	bool bDidRotation = false;

	//////////////////////
	// Rotating
	if (mpInput->GetKeyboard()->GetKeyPressed(eKey_A))
	{
		bDidRotation = true;
		mfAngle -= mfRotateSpeed * afTimeStep;
	}
	if (mpInput->GetKeyboard()->GetKeyPressed(eKey_D))
	{
		bDidRotation = true;
		mfAngle += mfRotateSpeed * afTimeStep;
	}
	mvDirection = cMath::AngleToVector(mfAngle);

	//////////////////////
	// Moving
	if (mpInput->GetKeyboard()->GetKeyPressed(eKey_W))
	{
		bDidMove = true;
		mvPosition += mvDirection * mfMoveSpeed * afTimeStep;
	}
	if (mpInput->GetKeyboard()->GetKeyPressed(eKey_S))
	{
		bDidMove = true;
		mvPosition += mvDirection * -mfMoveSpeed * afTimeStep;
	}

	mbMoving = bDidMove || bDidRotation;

	if (mbMoving == true)
	{
		//////////////////////
		// Steps
		if (mpStepTimer->GetTimeInSec() >= mfStepSoundRate)
		{
			mpAudioSource->Play();
			mpStepTimer->Start();
		}

		//////////////////////
		// Animation
		mpWalkAnimation->Update(afTimeStep);
		mpPlayerTexture = mpWalkAnimation->GetCurrentFrame();
	}
}

void cPlayer::OnDraw()
{
	mpGraphics->GetRenderer()->DrawTexture(mpPlayerTexture, mvPosition, mvSize, mfAngle, mvCenter);
}

void cPlayer::OnExit()
{
	
}

// -----------------------------------------------------------------------