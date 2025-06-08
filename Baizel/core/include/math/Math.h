#ifndef BAIZEL_MATH_H
#define BAIZEL_MATH_H

#include <random>
#include <ctime>
#include <math/MathTypes.h>

namespace baizel
{
    class cMath final
    {
    public:
        static int RandInt(int alMin, int alMax);
        static float RandFloat(float afMin, float afMax);

        static tVector2f AngleToVector(float afAngle);

        template <typename T>
        inline static T Clamp(T aValue, T aMin, T aMax)
        {
            if (aValue < aMin) aValue = aMin;
            else if (aValue > aMax) aValue = aMax;

            return aValue;
        }

    private:
        static std::mt19937 mRandomGenerator;
    };
}

#endif // BAIZEL_MATH_H