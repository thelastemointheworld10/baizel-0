#include <math/Math.h>

namespace baizel
{
	std::mt19937 cMath::mRandomGenerator { std::random_device{}() };

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	int cMath::GetRandInt(int alMin, int alMax)
	{
		std::uniform_int_distribution<int> lRandNumber(alMin, alMax);
		return lRandNumber(mRandomGenerator);
	}

	float cMath::GetRandFloat(float afMin, float afMax)
	{
		std::uniform_real_distribution<float> fRandNumber(afMin, afMax);
		return fRandNumber(mRandomGenerator);
	}

	// -----------------------------------------------------------------------
}