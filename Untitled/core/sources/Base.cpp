#include <Base.h>

namespace baizel
{
    //////////////////////////////////////////////////////////////////////////
    // CONSTRUCTORS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------
    
    cBase::cBase()
    {
        msWindowTitle = "Untitled";
        mvWindowSize = tVector2l(640, 640);
        mbFullscreen = false;

        mpEngine = new cEngine(new cEngineSetupSDL());
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
        {
            cLog::Error("Failed to initialize engine!");
            return false;
        }

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