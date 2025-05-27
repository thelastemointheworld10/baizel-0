#ifndef BAIZEL_MATH_H
#define BAIZEL_MATH_H

#include <random>
#include <ctime>

namespace baizel
{
    class cMath final
    {
    public:
        cMath();

        static int GetRandInt(int alMin, int alMax);
        static float GetRandFloat(float afMin, float afMax);

    private:
        static std::mt19937 mRandomGenerator;
    };
}

#endif // BAIZEL_MATH_H