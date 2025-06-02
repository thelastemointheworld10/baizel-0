#include <Base.h>

using namespace baizel;

#undef main
int main()
{
    cBase Base;

    if (Base.Init() == false)
    {
        cLog::Fatal("Failed to initialize!");
        return EXIT_FAILURE;
    }

    Base.Run();
    Base.Exit();

    return EXIT_SUCCESS;
}