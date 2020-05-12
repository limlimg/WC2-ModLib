//Change the retry button into load button
//auto-save a new game
//don't close GUI after saving

#include "easytech.h"
#include "CGameManager.h"
#include "InGameLoad.h"

static bool InGameLoad = false;

void CGameState::OpenSaveGUI(bool load) {
    this->SaveGUI = new GUISave;
    _ZN7GUISaveC1Ev(this->SaveGUI);
    GUIRect rect = {0.0, 0.0, _ZN10ecGraphics8InstanceEv()->DisplaySize[0],
                    _ZN10ecGraphics8InstanceEv()->DisplaySize[1]};
    this->SaveGUI->Init(rect, g_GameManager.GameMode, load);
    GUIManager::Instance()->AddChild(this->SaveGUI, true);
    GUIManager::Instance()->MoveToFront(this->SaveGUI);
    this->SaveGUI->Show();
}

//in game save-load menu related input
//don't close GUI after saving
//bool CGameState::OnEvent(Event const &event);
bool CGameState::OpenLoadEvent(const Event &event) {
    this->PauseBoxGUI->Hide();
    this->OpenSaveGUI(true);
    InGameLoad = true;
    return false;
}

bool CGameState::CloseLoadEvent(const Event &event) {
    if (InGameLoad) {
        GUIManager::Instance()->FadeOut(14, NULL);
    } else {
        GUIManager::Instance()->SafeFreeChild(this->SaveGUI);
        this->OpenSaveGUI(false);
    }
    return false;
}

def_easytech(_ZN10CGameState7OnEventERK5Event)

bool CGameState::CancelLoadEvent(const Event &event) {
    InGameLoad = false;
    return easytech(_ZN10CGameState7OnEventERK5Event)(this, &event);
}

//Auto-save a new game
def_easytech(_ZN10CGameState7OnEnterEv)

void CGameState::OnEnter() {
    easytech(_ZN10CGameState7OnEnterEv)(this);
    if (g_GameManager.IsNewGame)
        g_GameManager.SaveGame(
                (g_GameManager.GameMode == CGameManager::Conquest) ? "conquest6.sav" : "game6.sav");
}

//blocks autosave in case of in game loading, so that you can load the auto-save file in game
def_easytech(_ZN10CGameState6OnExitEv)

void CGameState::OnExit() {
    if (InGameLoad)
        g_GameManager.Result = true;//This blocks auto save
    InGameLoad = false;
    easytech(_ZN10CGameState6OnExitEv)(this);
}
