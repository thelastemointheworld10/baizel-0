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
	bool bDidMove = Move(afTimeStep);
	bool bDidRotate = Rotate(afTimeStep);

	if (bDidMove || bDidRotate)
	{
		UpdateAnimation(afTimeStep);
		PlayStepSound();

		mvDirection = cMath::AngleToVector(mfAngle);
		mbWasMoving = true;

		return;
	}

	if (mbWasMoving == true)
	{
		ResetPlayer();
		mbWasMoving = false;
	}
}

void cPlayer::OnDraw()
{
	mpGraphics->GetRenderer()->DrawTexture(mpPlayerTexture, mvPosition, mvSize, mfAngle, mvCenter);
}

void cPlayer::OnExit()
{
	mpStepTimer->Stop();
}

// -----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS
//////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------

//////////////////////////////////////////
// Core Functionality
//////////////////////////////////////////

bool cPlayer::Move(float afTimeStep)
{
	bool bDidMove = false;

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

	return bDidMove;
}

bool cPlayer::Rotate(float afTimeStep)
{
	bool bDidRotation = false;

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

	return bDidRotation;
}

void cPlayer::UpdateAnimation(float afTimeStep)
{
	mpWalkAnimation->Update(afTimeStep);
	mpPlayerTexture = mpWalkAnimation->GetCurrentFrame();
}

void cPlayer::PlayStepSound()
{
	if (mpStepTimer->GetTimeInSec() >= mfStepSoundRate)
	{
		mpAudioSource->Play();
		mpStepTimer->Start();
	}
}

void cPlayer::ResetPlayer()
{
	mpWalkAnimation->ResetFrameTime();
	mpPlayerTexture = mpWalkAnimation->GetFrameByIndex(0);
}

// -----------------------------------------------------------------------