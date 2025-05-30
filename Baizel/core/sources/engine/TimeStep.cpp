#include <engine/TimeStep.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cTimeStep::cTimeStep(iSystem* apSystem)
	{
		mfTimeStep = 0.016f;

		mpSystem = apSystem;

		mfCurrentFrameTime = 0.0f;
		mfLastFrameTime = mpSystem->GetTimeInSec();
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	void cTimeStep::AddFrame()
	{
		mfCurrentFrameTime = mpSystem->GetTimeInSec();
		mfTimeStep = mfCurrentFrameTime - mfLastFrameTime;
		mfLastFrameTime = mfCurrentFrameTime;
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	float cTimeStep::GetTimeStep() const
	{
		return mfTimeStep;
	}

	// -----------------------------------------------------------------------
}