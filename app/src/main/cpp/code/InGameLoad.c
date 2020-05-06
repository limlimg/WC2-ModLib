//InGameLoad.cpp
//Change the retry button into load button
//auto-save a new game
//don't close GUI after saving

#include <malloc.h>
#include "easytech.h"
#include "CStateManager/CGameState.h"
#include "CGameManager.h"

static bool InGameLoad = false;

static void _ZN10CGameState11OpenSaveGUIEb(struct CGameState *self, bool load) {
    self->SaveGUI = malloc(sizeof(struct GUISave));
    _ZN7GUISaveC1Ev(self->SaveGUI);
    struct GUIRect rect = {0.0, 0.0, _ZN10ecGraphics8InstanceEv()->DisplaySize[0],
                           _ZN10ecGraphics8InstanceEv()->DisplaySize[1]};
    _ZN7GUISave4InitERK7GUIRectib(self->SaveGUI, &rect, g_GameManager.GameMode, load);
    _ZN10GUIElement8AddChildEPS_b((struct GUIElement *) _ZN10GUIManager8InstanceEv(),
                                  (struct GUIElement *) self->SaveGUI, true);
    _ZN10GUIElement11MoveToFrontEPS_((struct GUIElement *) _ZN10GUIManager8InstanceEv(),
                                     (struct GUIElement *) self->SaveGUI);
    _ZN10GUIElement4ShowEv((struct GUIElement *) self->SaveGUI);
}

//in game save-load menu related input
//don't close GUI after saving
//bool CGameState::OnEvent(Event const &event);
bool _ZN10CGameState13OpenLoadEventERK5Event(struct CGameState *self, const struct Event *event) {
    _ZN10GUIElement4HideEv((struct GUIElement *) self->PauseBoxGUI);
    _ZN10CGameState11OpenSaveGUIEb(self, true);
    InGameLoad = true;
    return false;
}

def_easytech(_ZN10CGameState7OnEventERK5Event)

bool _ZN10CGameState14CloseLoadEventERK5Event(struct CGameState *self, const struct Event *event) {
    if (InGameLoad) {
        _ZN10GUIManager7FadeOutEiP10GUIElement(_ZN10GUIManager8InstanceEv(), 14, NULL);
    } else {
        _ZN10GUIManager13SafeFreeChildEP10GUIElement(_ZN10GUIManager8InstanceEv(),
                                                     (struct GUIElement *) self->SaveGUI);
        _ZN10CGameState11OpenSaveGUIEb(self, false);
    }
    return false;
}

bool _ZN10CGameState15CancelLoadEventERK5Event(struct CGameState *self, const struct Event *event) {
    InGameLoad = false;
    return easytech(_ZN10CGameState7OnEventERK5Event)(self, event);
}

//Auto-save a new game
def_easytech(_ZN10CGameState7OnEnterEv)

void _ZN10CGameState7OnEnterEv(struct CGameState *self) {
    easytech(_ZN10CGameState7OnEnterEv)(self);
    if (g_GameManager.IsNewGame)
        _ZN12CGameManager8SaveGameEPKc(&g_GameManager,
                                       (g_GameManager.GameMode == 2) ? "conquest6.sav"
                                                                     : "game6.sav");
}

//blocks autosave in case of in game loading, so that you can load the auto-save file in game
def_easytech(_ZN10CGameState6OnExitEv)

void _ZN10CGameState6OnExitEv(struct CGameState *self) {
    if (InGameLoad)
        g_GameManager.Result = true;//This blocks auto save
    InGameLoad = false;
    easytech(_ZN10CGameState6OnExitEv)(self);
}

//End of File InGameLoad.cpp