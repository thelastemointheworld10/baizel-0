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
}

cPlayer::~cPlayer()
{
	delete mpAudioSource;
	mpAudioSource = nullptr;

	delete mpStepBuffer;
	mpStepBuffer = nullptr;

	delete mpStepTimer;
	mpStepTimer = nullptr;

	delete mpWalkAnimation;
	mpWalkAnimation = nullptr;

	delete mpIdleAnimation;
	mpIdleAnimation = nullptr;
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
	mpAudioSource = mpAudioSystem->CreateSource();
	mpStepBuffer = mpAudioSystem->CreateBuffer();

	mvPosition = tVector2f(400, 300);
	mvSize = tVector2f(150, 150);
	mvCenter = mvSize / 2.0f;

	mpIdleAnimation = new cAnimation(mpGraphics->GetLowLevel());
	mpWalkAnimation = new cAnimation(mpGraphics->GetLowLevel());

	mpIdleAnimation->SetSpeed(3);
}

void cPlayer::OnStart()
{
	mpIdleAnimation->AddFrame("textures/player/player_idle_01.bmp");
	mpIdleAnimation->AddFrame("textures/player/player_idle_02.bmp");
	mpIdleAnimation->AddFrame("textures/player/player_idle_03.bmp");

	mpWalkAnimation->AddFrame("textures/player/player_walk_01.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_02.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_03.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_04.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_05.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_04.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_03.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_02.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_01.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_06.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_07.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_08.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_09.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_10.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_09.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_08.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_07.bmp");
	mpWalkAnimation->AddFrame("textures/player/player_walk_06.bmp");

	mpPlayerTexture = mpIdleAnimation->GetCurrentFrame();

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
		UpdateWalkAnimation(afTimeStep);
		PlayStepSound();

		mpAudioSystem->GetListener()->SetPosition(mvPosition);
		mpAudioSource->SetPosition(mvPosition);

		mvDirection = cMath::AngleToVector(mfAngle);
	}

	if (bDidMove == false && bDidRotate == false)
	{
		UpdateIdleAnimation(afTimeStep);
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

void cPlayer::UpdateIdleAnimation(float afTimeStep)
{
	mpIdleAnimation->Update(afTimeStep);
	mpPlayerTexture = mpIdleAnimation->GetCurrentFrame();
}

void cPlayer::UpdateWalkAnimation(float afTimeStep)
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

// -----------------------------------------------------------------------