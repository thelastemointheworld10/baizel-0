#include <Base.h>

#include <impl/resources/XMLDocumentTiXML.h>

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------

cBase::cBase()
{
    msWindowTitle = "Untitled";
    mvScreenSize = tVector2l(1600, 900);
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
    if (mpEngine->Init(msWindowTitle, mvScreenSize, mvVirtualSize, mbFullscreen) == false)
    {
        cLog::Error("Failed to initialize engine!");
        return false;
    }

    mpEngine->GetInput()->GetKeyboard()->SetKeyRepeat(false);
    mpEngine->GetGraphics()->GetRenderer()->SetClearColor(cColor(100, 100, 100));

    mpPlayer->Init();
    mpEngine->GetUpdater()->AddUpdateable(mpPlayer);

    return true;
}

void cBase::Run()
{
    mpEngine->Run();
}

void cBase::Exit()
{
    cXMLDocumentTiXML* pXMLDoc = new cXMLDocumentTiXML();
    cXMLElement* pRoot = new cXMLElement("root", nullptr);
    cXMLElement* pElem = new cXMLElement("time", nullptr);
    cXMLElement* pElem1 = new cXMLElement("time1", nullptr);
    cXMLElement* pElem2 = new cXMLElement("time2", nullptr);

    pXMLDoc->AddChild(pRoot);

    pElem->SetValueBool(true);
    pElem1->SetValueString("hi");
    pElem2->SetValueInt(444);
    pElem->SetAttributeFloat("val", mpEngine->GetApplicationTime()->GetTimeInSec());
    pElem1->SetAttributeFloat("val1", 12423.0f);
    pElem2->SetAttributeInt("val2", 13);

    pRoot->AddChild(pElem);
    pRoot->AddChild(pElem1);
    pRoot->AddChild(pElem2);

    pXMLDoc->SaveFile("saves/second_test.sav");

    delete pElem;
    delete pElem1;
    delete pElem2;
    delete pRoot;
    delete pXMLDoc;
}

// -----------------------------------------------------------------------