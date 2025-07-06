#include <Base.h>

using namespace baizel;

#undef main
int main()
{
    cLog::SetOutFile("log/baizel.log");

    cBase Base;

    if (Base.Init() == false)
    {
        cLog::Error("Failed to initialize!");
        return EXIT_FAILURE;
    }

    Base.Run();
    Base.Exit();

    cLog::CloseFile();

    return EXIT_SUCCESS;
}