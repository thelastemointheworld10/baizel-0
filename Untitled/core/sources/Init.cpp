#include <Init.h>

namespace baizel
{
    //////////////////////////////////////////////////////////////////////////
    // CONSTRUCTORS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------
    
    cInit::cInit()
    {
        msWindowTitle = "Unknown";
        mvWindowSize = cVector2l(800, 600);
        mbFullscreen = false;

        mpGameSetup = new cSDLGameSetup();
        mpEngine = new cEngine(mpGameSetup);
    }

    cInit::~cInit()
    {
        delete mpEngine;
        mpEngine = nullptr;
    }
    
    // -----------------------------------------------------------------------
    
    //////////////////////////////////////////////////////////////////////////
    // PUBLIC METHODS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------
    
    bool cInit::Init()
    {
        if (mpEngine->Init(msWindowTitle, mvWindowSize, mbFullscreen) == false)
            return false;

        return true;
    }
    
    void cInit::Run()
    {
        mpEngine->Run();
    }
    
    void cInit::Exit()
    {
        mpEngine->Exit();
    }
    
    // -----------------------------------------------------------------------
}