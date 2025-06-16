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
        mvScreenSize = tVector2l(640, 480);
        mvVirtualSize = tVector2f(800, 600);
        mbFullscreen = false;

        mpEngine = new cEngine(new cEngineSetupSDL(), new cAudioSystemAL());

        mpPlayer = new cPlayer(mpEngine->GetAudioSystem(),
            mpEngine->GetGraphics(),
            mpEngine->GetInput(),
            mpEngine->GetApplicationTime());
    }

    cBase::~cBase()
    {
        cLog::Log("- Deleting base stuff");

        cLog::Log("\tPlayer");
        delete mpPlayer;
        mpPlayer = nullptr;

        cLog::Log("\tEngine");
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
        #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
        #endif

        if (mpEngine->Init(msWindowTitle, mvScreenSize, mvVirtualSize, mbFullscreen) == false)
        {
            cLog::Error("Failed to initialize engine!");
            return false;
        }

        mpPlayer->Init();
        mpEngine->GetUpdater()->AddUpdateable(mpPlayer);

        mpEngine->GetInput()->GetKeyboard()->SetKeyRepeat(false);
        mpEngine->SetClearColor(cColor(150, 150, 150));

        return true;
    }
    
    void cBase::Run()
    {
        mpEngine->Run();
    }
    
    void cBase::Exit()
    {
        // saving game progress && settings
    }
    
    // -----------------------------------------------------------------------
}