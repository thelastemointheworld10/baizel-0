#include <Game.h>

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------

cGame::cGame()
{
    msWindowTitle = "Untitled";
    mvScreenSize = tVector2l(1280, 720);
    mvVirtualSize = tVector2f(800, 600);
    mbFullscreen = false;

    cLog::SetOutFile("log/baizel.log");

    mpEngine = new cEngine(
        new cEngineSetupSDL(),
        new cAudioSystemAL(new cAudioReaderLibVorbis()),
        new cXMLReaderTiXML());

    mpPlayer = new cPlayer(mpEngine->GetAudioSystem(),
        mpEngine->GetGraphics(),
        mpEngine->GetInput(),
        mpEngine->GetApplicationTime(),
        mpEngine->GetXMLReader());
}

cGame::~cGame()
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

bool cGame::Init()
{
    if (mpEngine->Init(msWindowTitle, mvScreenSize, mvVirtualSize, mbFullscreen) == false)
    {
        cLog::Error("Failed to initialize engine!");
        return false;
    }

    mpEngine->GetInput()->GetKeyboard()->SetKeyRepeat(false);
    mpEngine->GetGraphics()->GetRenderer()->SetClearColor(cColor(100, 100, 100));
    mpEngine->GetAudioSystem()->GetListener()->SetMasterGain(1.0f);

    iAudioBuffer* pBuffer = mpEngine->GetAudioSystem()->CreateBuffer();
    pBuffer->LoadAudio("music/raw_test/01.ogg");
    iAudioSource* pSource = mpEngine->GetAudioSystem()->CreateSource();
    pSource->SetBuffer(pBuffer);
    pSource->SetLoop(true);
    pSource->Play();

    cLog::LogToFile("last log: %s", cLog::GetLastLog().c_str());

    return true;
}

void cGame::Run()
{
    mpEngine->Run();
}

void cGame::Exit()
{
    
}

// -----------------------------------------------------------------------