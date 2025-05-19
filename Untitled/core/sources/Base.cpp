#include <Base.h>

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

        mpEngine = new cEngine(new cSDLGameSetup());
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

    //////////////////////////////////////////
    // Runtime Control
    //////////////////////////////////////////
    
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
        // some logic like reset scripts global vars
    }
    
    // -----------------------------------------------------------------------
}