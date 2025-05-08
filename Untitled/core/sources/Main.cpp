#include <Init.h>

using namespace baizel;

int main(int argc, char* args[])
{
    cInit* pInit = new cInit();

    if (pInit->Init() == false)
    {
        Fatal("Failed to initialize!");
        delete pInit;

        return EXIT_FAILURE;
    }
    else
    {
        pInit->Run();
        //pInit->Exit();
    }

    delete pInit;

    return EXIT_SUCCESS;
}