#ifndef BAIZEL_MATH_H
#define BAIZEL_MATH_H

#include <random>
#include <ctime>

namespace baizel
{
    class cMath final
    {
    public:
        static int GetRandInt(int alMin, int alMax);
        static float GetRandFloat(float afMin, float afMax);

        template <typename T>
        static T Clamp(T aValue, const T& aMin, const T& aMax)
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