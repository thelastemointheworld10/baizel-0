#include <math/Math.h>

namespace baizel
{
	std::mt19937 cMath::mRandomGenerator{ std::random_device{}() };

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	int cMath::RandInt(int alMin, int alMax)
	{
		std::uniform_int_distribution<int> lRandNumber(alMin, alMax);
		return lRandNumber(mRandomGenerator);
	}

	float cMath::RandFloat(float afMin, float afMax)
	{
		std::uniform_real_distribution<float> fRandNumber(afMin, afMax);
		return fRandNumber(mRandomGenerator);
	}

	tVector2f cMath::AngleToVector(float afAngle)
	{
		float fRadians = afAngle * (3.14159265f / 180.0f);
		return tVector2f(std::cos(fRadians), std::sin(fRadians));
	}

	// -----------------------------------------------------------------------
}