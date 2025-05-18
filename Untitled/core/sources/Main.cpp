#include <Base.h>

using namespace baizel;

int main(int argc, char* args[])
{
    cBase* pBase = new cBase();

    if (pBase->Init() == false)
    {
        Fatal("Failed to initialize!");
        delete pBase;

        return EXIT_FAILURE;
    }

    pBase->Run();

    delete pBase;

    return EXIT_SUCCESS;
}