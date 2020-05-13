//Auto:
//press end turn with battle animation settings on, and ai will take your turn for you
//battle animation is removed
//Skip:
//press end turn button while ai is playing to not watch
//changes in the ownerships of areas are still displayed
//Extra feature:
//mark neutral countries as defeated to exclude them from turn cycle and win check
//add player neutral country into defeat list
//TODO: Fix AI bug caused by controlling player country

#include <cmath>
#include <malloc.h>
#include "_CGameState.h"
#include "easytech.h"
#include "CStateManager/CGameState.h"
#include "CActionAI.h"
#include "CFightTextMgr.h"
#include "CGameSettings.h"

static bool AIAction;
static bool SkipMode;
static bool DisplayAreaChange;

//Initialize Auto and Skip flags
//Also: mark neutral countries as defeated to exclude them from turn cycle and win check
//Also: add player neutral country into defeat list
void CGameManager::InitBattle() {
    if (this->IsNewGame) {
        this->LoadBattle(this->BattleFileName);
        this->CurrentDialogueIndex = 0;
        this->CurrentTurnNumMinusOne = 0;
        this->RandomRewardMedal = 0;
        this->MovePlayerCountryToFront();
        CCountry *PlayerCountry = this->GetPlayerCountry();
        if (PlayerCountry != NULL)
            this->SetPlayercountryname(0, PlayerCountry->Name);
        size_t i;
        for (i = 0; i < this->Country.size(); i++) {
            CCountry *Country = this->Country[i];
            if (this->GameMode == CGameManager::Conquest && PlayerCountry != NULL &&
                Country->Alliance == PlayerCountry->Alliance)
                Country->TaxRate = 1.0;
            if (Country->Alliance == CCountry::NeutralID) {
                if (Country->AI)
                    Country->Defeated = true;
                else
                    this->DefeatCountry.push_back(Country);
            }
        }
        this->InitCameraPos();
    } else
        this->RealLoadGame(this->LoadFileName);
    this->Result = false;
    this->CampaignRewardMedal = 0;
    this->LocalHost = true;
    AIAction = false;
    SkipMode = false;
    g_Scene.AllAreasEncirclement();
    CActionAI::Instance()->InitAI();
}

void CGameManager::TurnBegin() {
    CCountry *Country = *this;
    if (Country == NULL)
        return;
    Country->TurnBegin();
    AIAction = false;
    CGameState *game = static_cast<CGameState *>(CStateManager::Instance()->GetStatePtr(Game));
    if (Country->AI) {
        game->AIProgressGUI->Show();
    } else {
        game->HideAIProgress();
        if (this->GameMode != CGameManager::Tutorial)
            game->PlayerCountryBegin();
        SkipMode = false;
        int AreaID = Country->GetHighestValueArea();
        if (AreaID >= 0) {
            CountryAction action = {CountryAction::CameraMoveAction, NoCard, 0, AreaID, 0};
            Country->Action(action);
        }
    }
}

//Auto is implemented here
void CGameManager::GameUpdate(float time) {
    if (!this->LocalHost)
        return;
    if (this->Result)
        return;
    CCountry *Country = *this;
    if (Country == NULL)
        return;
    Country->Update(time);
    if (!Country->IsActionFinish())
        return;
    CCountry *DefeatedCountry = this->GetNewDefeatedCountry();
    CGameState *GameState = static_cast<CGameState *>(CStateManager::Instance()->GetStatePtr(Game));
    if (DefeatedCountry != NULL) {
        GameState->ShowDefeated(DefeatedCountry);
        return;
    }
    if (Country->AI) {
        GameState->UpdateAIProgress();
        AIAction = true;
    }
    if (!AIAction)
        return;
    this->Next();
}

void CGameManager::Next() {
    CCountry *Country = *this;
    if (Country == NULL)
        return;
    if (!AIAction)
        return;
    //! set neutral to be defeated in InitBattle so that their turns are skipped
    if (Country->AreaIDList.empty() || Country->Defeated) {
        this->EndTurn();
        return;
    }
    CActionNode *ActionNode = CActionAI::Instance()->setCpuDriverbyId(this->CurrentCountryIndex,
                                                                      this->AlwaysZero);
    if (ActionNode == NULL) {
        this->EndTurn();
        return;
    }
    CountryAction Action = {CountryAction::NoAction,
                            ActionNode->CardID,
                            ActionNode->StartAreaID,
                            ActionNode->TargetAreaID,
                            ActionNode->ArmyIndex};
    switch (ActionNode->ActionType) {
        default:
            return;
        case CActionNode::UseCardNode:
            Action.ActionType = CountryAction::UseCardAction;
            Action.ArmyIndex = 0;
            break;
        case CActionNode::ArmyMoveNode:
            if (ActionNode->StartAreaID == ActionNode->TargetAreaID)
                Action.ActionType = CountryAction::ArmyInactiveAction;
            else
                Action.ActionType = CountryAction::ArmyMoveAction;
            break;
        case CActionNode::ArmyAttackNode:
            Action.ActionType = CountryAction::ArmyAttackAction;
            break;
        case CActionNode::ArmyMoveFrontNode:
            Action.ActionType = CountryAction::ArmyMoveFrontAction;
    }
    Country->Action(Action);
}

//Move camera while ai is controlling player country
bool CCountry::IsLocalPlayer() {
    return !AIAction;
}

//Skip is implemented here
//Render game scene when the ownership of any area changes
void CGameState::Update(float time) {
    if (this->IdleTimerEnabled) {
        this->IdleTimer -= time;
        if (this->IdleTimer <= 0.0) {
            this->IdleTimer = 0.0;
            this->IdleTimerEnabled = false;
        }
    }
    if (this->BuyingCard && g_GameManager.GetPlayerCountry()->IsActionFinish()) {
        if (this->BuyCardGUI->CanBuySelCard())
            this->BuyCardGUI->ResetCardTarget();
        else {
            this->BuyCardGUI->ReleaseTarget();
            this->GameButtonCardRemove->Hide();
            this->GameButtonCard->Show();
            this->SmallCardGUI->Hide();
        }
        this->BuyingCard = false;
    }
    do {
        if ((this->PauseBoxGUI->Flags & GUIElement::Shown)
            || (this->OptionsGUI && (this->OptionsGUI->Flags & GUIElement::Shown))
            || (this->SaveGUI && (this->SaveGUI->Flags & GUIElement::Shown))
            || (this->WarningGUI && (this->WarningGUI->Flags & GUIElement::Shown))
            || (this->DialogueGUI && (this->DialogueGUI->Flags & GUIElement::Shown)))
            break;
        if (g_GameManager.IsManipulate()) {
            float speed[2];
            this->CTouchInertia.Update(time);
            if (this->CTouchInertia.GetSpeed(speed[0], speed[1])) {
                if (g_Scene.Move((int) (-speed[0] * time), (int) (-speed[1] * time)))
                    this->CTouchInertia.Stop();
            } else if (this->ShouldCameraAutoFixPos) {
                g_Scene.CCamera.SetAutoFixPos(true);
                this->ShouldCameraAutoFixPos = false;
            }
        } else {
            if (SkipMode)
                time = 1.0;
            else if (g_GameSettings.Speed > 2)
                time *= (g_GameSettings.Speed == 3) ? 1.5 : 2.0;
        }
        ecEffectManager::Instance()->Update(time);
        g_Scene.Update(time);
        g_FightTextMgr.Update(time);
        if ((this->DefeatedGUI && (this->DefeatedGUI->Flags & GUIElement::Shown)) ||
            !this->GameNotInterrupted || g_GameManager.Result)
            break;
        if (!g_Scene.IsBombing())
            g_GameManager.GameUpdate(time);
    } while (SkipMode && !DisplayAreaChange);
    DisplayAreaChange = false;
}

//Capture area ownership change
void CCountry::RemoveArea(int AreaID) {
    DisplayAreaChange = true;
    this->AreaIDList.remove(AreaID);
    if (g_Scene[AreaID]->AreaType == CArea::capital)
        this->CapitalIDList.remove(AreaID);
}

void CCountry::AddArea(int AreaID) {
    DisplayAreaChange = true;
    if (!this->FindArea(AreaID)) {
        this->AreaIDList.push_back(AreaID);
        if (g_Scene[AreaID]->AreaType == CArea::capital)
            this->CapitalIDList.push_back(AreaID);
    }
}

//Press end turn button
//Also: in game save-load menu related input
def_easytech(_ZN10CGameState7OnEventERK5Event)

bool CGameState::OnEvent(const Event &event) {
    switch (event.type) {
        case Event::GUI : {
            switch (event.info.GUI.type) {
                case Event::info::GUI::Button : {
                    if (event.info.GUI.ptr == this->GameButtonRound) {
                        if (g_GameManager.IsManipulate()) {
                            if (this->BuyCardGUI->CardCanTarget) {
                                this->BuyCardGUI->ReleaseTarget();
                                this->GameButtonCardRemove->Hide();
                                this->GameButtonCard->Show();
                                this->SmallCardGUI->Hide();
                                this->BuyingCard = false;
                            }
                            this->GameButtonCard->Hide();
                            this->ResetTouchState();
                            this->UnselectArea();
                            g_Scene.CCamera.SetAutoFixPos(true);
                            this->ShouldCameraAutoFixPos = false;
                            g_Scene.NewRoundFlashing = false;
                            if (g_GameSettings.BattleAnimation) {
                                AIAction = true;
                                CActionAI::Instance()->InitAI();
                            } else {
                                g_GameManager.EndTurn();
                                CActionAI::Instance()->InitAI();
                                this->UpdateAIProgress();
                            }
                        } else {
                            if (AIAction)
                                SkipMode = true;
                        }
                        return false;
                    }
                    GUIPauseBox *PauseBox = this->PauseBoxGUI;
                    if (event.info.GUI.ptr == PauseBox->ButtonRestart) {
                        return this->OpenLoadEvent(event);
                    }
                    if (this->SaveGUI != NULL && event.info.GUI.ptr == this->SaveGUI->ButtonOK)
                        return this->CloseLoadEvent(event);
                    if (this->SaveGUI != NULL && event.info.GUI.ptr == this->SaveGUI->ButtonBack)
                        return this->CancelLoadEvent(event);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
    return easytech(_ZN10CGameState7OnEventERK5Event)(this, &event);
}

//Don't move camera under skip mode
void CCamera::Upate(float time) {
    if (!this->IsMoving) return;
    if (SkipMode) {
        this->Speed[0] = 0.0;
        this->Speed[1] = 0.0;
        this->IsMoving = false;
        this->AutoFixPos = false;
        return;
    }
    int i;
    for (i = 0; i < 2; i++) {
        if (this->Speed[i] == 0.0) continue;
        if (fabs(this->TargetPos[i] - this->CenterPos[i]) < fabs(this->Speed[i] * 30.0 * time)) {
            this->CenterPos[i] = this->TargetPos[i];
            this->Speed[i] = 0.0;
        } else {
            this->CenterPos[i] += this->Speed[i] * 30.0 * time;
        }
    }
    if (this->Speed[0] == 0.0 && this->Speed[1] == 0.0) {
        this->IsMoving = false;
        this->AutoFixPos = false;
    }
}

//Disables battle animation
void CGameState::StartBattale(int StartAreaID, int TargetAreaID, int a3, bool Animation) {
    CFight fight;
    _ZN6CFightC1Ev(&fight);
    fight.FirstAttack(StartAreaID, TargetAreaID);
    fight.ApplyResult();
    if (fight.StartArmySecondAttack || fight.TargetArmySecondAttack) {
        fight.SecondAttack();
        fight.ApplyResult();
    }
    _ZN6CFightD1Ev(&fight);
}

__BEGIN_DECLS
void _ZN9GUIBattleC1Ev(GUIBattle *self) { _ZN10GUIElementC1Ev((struct GUIElement *) self); }
void _ZN9GUIBattleC2Ev(GUIBattle *self) __attribute__ ((alias("_ZN9GUIBattleC1Ev")));
void _ZN9GUIBattleD1Ev(GUIBattle *self) { _ZN10GUIElementD1Ev((struct GUIElement *) self); }
void _ZN9GUIBattleD2Ev(GUIBattle *self) __attribute__ ((alias("_ZN9GUIBattleD1Ev")));
void _ZN9GUIBattleD0Ev(GUIBattle *self) {
    _ZN9GUIBattleD1Ev(self);
    free(self);
}
void _ZN9GUIBattle4InitERK7GUIRect() {}
__END_DECLS

/*WIP: Fix Auto AI
int calcAreaArmyHp(CArea *Area, bool TopOnly) {
    if (Area == NULL)
        return -1;
    if (Area->ArmyCount <= 0)
        return 0;
    CArmy *army;
    if (TopOnly) {
        army = Area->GetArmy(0);
        return (army != NULL) ? army->Hp : -1;
    }
    int i, s = 0;
    for (i = 0; i < Area->ArmyCount; i++) {
        army = Area->GetArmy(i);
        if (army == NULL)
            return -1;
        s += army->Hp;
    }
    return s;
}*/

//Stop the game from saving commander data on game closing, which is suspected to cause data loss
//Now it will save whenever a change in medal number is detected

#include <ecLibrary.h>

void CCommander::Save() {}

def_easytech(_ZN10CCommander4SaveEv)
def_easytech(_Z12ecGameUpdatef)

void ecGameUpdate(float time) {
    static int medal = 50;
    if (medal != g_Commander.Medal) {
        easytech(_ZN10CCommander4SaveEv)(&g_Commander);
        medal = g_Commander.Medal;
    }
    easytech(_Z12ecGameUpdatef)(time);
}
