#ifndef PLAYER_H
#define PLAYER_H

#include <engine/Engine.h>

using namespace baizel;

class cPlayer final : public iUpdateable
{
public:
	cPlayer(iAudioSystem* apAudioSystem, cGraphics* apGraphics, cInput* apInput, iApplicationTime* apApplicationTime);
	~cPlayer() override;

	void Init();

	void OnStart() override;
	void OnUpdate(float afTimeStep) override;
	void OnDraw() override;
	void OnExit() override;

private:
	bool Move(float afTimeStep);
	bool Rotate(float afTimeStep);
	void UpdateIdleAnimation(float afTimeStep);
	void UpdateWalkAnimation(float afTimeStep);
	void PlayStepSound();

private:
	tVector2f mvSize = tVector2f(100);
	tVector2f mvCenter = tVector2f(50);
	tVector2f mvPosition = tVector2f();
	tVector2f mvDirection = tVector2f();

	float mfMoveSpeed = 150.0f;
	float mfRotateSpeed = 100.0f;
	float mfAngle = 0.0f;

	float mfStepSoundRate = 0.9f;

	cAnimation* mpIdleAnimation = nullptr;
	cAnimation* mpWalkAnimation = nullptr;

	iTexture* mpPlayerTexture = nullptr;

	iAudioSource* mpAudioSource = nullptr;
	iAudioBuffer* mpStepBuffer = nullptr;
	cTimer* mpStepTimer;

	iAudioSystem* mpAudioSystem = nullptr;
	cGraphics* mpGraphics = nullptr;
	cInput* mpInput = nullptr;
};

#endif // PLAYER_H