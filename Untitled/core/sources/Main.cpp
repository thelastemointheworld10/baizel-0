#include <Init.h>

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
    else
    {
        pBase->Run();
        // pBase->Exit();
    }

    delete pBase;

    return EXIT_SUCCESS;
}