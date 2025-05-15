#include <Init.h>

namespace baizel
{
    //////////////////////////////////////////////////////////////////////////
    // CONSTRUCTORS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------
    
    cBase::cBase()
    {
        msWindowTitle = "Unknown";
        mvWindowSize = cVector2l(800, 600);
        mbFullscreen = false;

        mpGameSetup = new cSDLGameSetup();
        mpEngine = new cEngine(mpGameSetup);
    }

    cBase::~cBase()
    {
        delete mpEngine;
        mpEngine = nullptr;
    }
    
    // -----------------------------------------------------------------------
    
    //////////////////////////////////////////////////////////////////////////
    // PUBLIC METHODS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------
    
    bool cBase::Init()
    {
        if (mpEngine->Init(msWindowTitle, mvWindowSize, mbFullscreen) == false)
            return false;

        return true;
    }
    
    void cBase::Run()
    {
        mpEngine->Run();
    }
    
    void cBase::Exit()
    {
        mpEngine->Exit();
    }
    
    // -----------------------------------------------------------------------
}