#include <engine/TimeStep.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cTimeStep::cTimeStep(iApplicationTime* apApplicationTime)
	{
		mfTimeStep = 0.016f;

		mpApplicationTime = apApplicationTime;

		mfCurrentFrameTime = 0.0f;
		mfLastFrameTime = mpApplicationTime->GetTimeInSec();
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
		mfCurrentFrameTime = mpApplicationTime->GetTimeInSec();
		mfTimeStep = mfCurrentFrameTime - mfLastFrameTime; // <-- глеб лох
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