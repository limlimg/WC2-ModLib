//Auto:
//press end turn with battle animation settings on, and ai will take your turn for you
//battle animation is removed
//Skip:
//press end turn button while ai is playing to not watch
//Extra feature:
//mark neutral countries as defeated to exclude them from turn cycle and win check
//add player neutral country into defeat list
//TODO: Fix AI bug caused by controlling player country

#include <stddef.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include "easytech.h"
#include "CGameManager.h"
#include "CScene.h"
#include "CActionAI.h"
#include "CStateManager/CGameState.h"
#include "CFightTextMgr.h"
#include "CGameSettings.h"
#include "CFight.h"
#include "GUI/GUIElement.h"

static bool AIAction;
static bool SkipMode;

__BEGIN_DECLS

//Initialize Auto and Skip flags
//Also: mark neutral countries as defeated to exclude them from turn cycle and win check
//Also: add player neutral country into defeat list
void _ZN12CGameManager10InitBattleEv(struct CGameManager *self) {
    if (self->IsNewGame) {
        _ZN12CGameManager10LoadBattleEPKc(self, self->BattleFileName);
        self->CurrentDialogueIndex = 0;
        self->CurrentTurnNumMinusOne = 0;
        self->RandomRewardMedal = 0;
        _ZN12CGameManager24MovePlayerCountryToFrontEv(self);
        struct CCountry *PlayerCountry = _ZN12CGameManager16GetPlayerCountryEv(self);
        if (PlayerCountry != NULL)
            _ZN12CGameManager20SetPlayercountrynameEiPKc(self, 0, PlayerCountry->Name);
        size_t i;
        for (i = 0; i < _ZNSt6vector4sizeE(P8CCountry)(&self->Country); i++) {
            struct CCountry *Country = _ZNSt6vectorixE(P8CCountry)(&self->Country, i);
            if (self->GameMode == 2
                && PlayerCountry != NULL
                && Country->Alliance == PlayerCountry->Alliance)
                Country->TaxRate = 1.0;
            if (Country->Alliance == NeutralID) {
                if (Country->AI)
                    Country->Defeated = true;
                else
                    _ZNSt6vector9push_backE(P8CCountry)(&self->DefeatCountry, Country);
            }
        }
        _ZN12CGameManager13InitCameraPosEv(self);
    } else
        _ZN12CGameManager12RealLoadGameEPKc(self, self->LoadFileName);
    self->Result = false;
    self->CampaignRewardMedal = 0;
    self->LocalHost = true;
    AIAction = false;
    SkipMode = false;
    _ZN6CScene20AllAreasEncirclementEv(&g_Scene);
    _ZN9CActionAI6InitAIEv(_ZN9CActionAI8InstanceEv());
}

void _ZN12CGameManager9TurnBeginEv(struct CGameManager *self) {
    struct CCountry *Country = _ZN12CGameManager13GetCurCountryEv(self);
    if (Country == NULL)
        return;
    _ZN8CCountry9TurnBeginEv(Country);
    AIAction = false;
    struct CGameState *game = (struct CGameState *) (_ZN13CStateManager11GetStatePtrE6EState(
            _ZN13CStateManager8InstanceEv(), Game));
    if (Country->AI) {
        _ZN10GUIElement4ShowEv((struct GUIElement *) game->AIProgressGUI);
    } else {
        _ZN10CGameState14HideAIProgressEv(game);
        if (self->GameMode != 5)
            _ZN10CGameState18PlayerCountryBeginEv(game);
        SkipMode = false;
        int AreaID = _ZN8CCountry19GetHighestValueAreaEv(Country);
        if (AreaID >= 0) {
            struct CountryAction action = {6, 0, 0, AreaID, 0};
            _ZN8CCountry6ActionERK13CountryAction(Country, &action);
        }
    }
}

//Auto is implemented here
void _ZN12CGameManager10GameUpdateEf(struct CGameManager *self, float time) {
    if (!self->LocalHost)
        return;
    if (self->Result)
        return;
    struct CCountry *Country = _ZN12CGameManager13GetCurCountryEv(self);
    if (Country == NULL)
        return;
    _ZN8CCountry6UpdateEf(Country, time);
    if (!_ZN8CCountry14IsActionFinishEv(Country))
        return;
    struct CCountry *DefeatedCountry = _ZN12CGameManager21GetNewDefeatedCountryEv(self);
    struct CGameState *GameState = (struct CGameState *) (_ZN13CStateManager11GetStatePtrE6EState(
            _ZN13CStateManager8InstanceEv(),
            Game));
    if (DefeatedCountry != NULL) {
        _ZN10CGameState12ShowDefeatedEP8CCountry(GameState, DefeatedCountry);
        return;
    }
    if (Country->AI) {
        _ZN10CGameState16UpdateAIProgressEv(GameState);
        AIAction = true;
    }
    if (!AIAction)
        return;
    _ZN12CGameManager4NextEv(self);
}

void _ZN12CGameManager4NextEv(struct CGameManager *self) {
    struct CCountry *Country = _ZN12CGameManager13GetCurCountryEv(self);
    if (Country == NULL)
        return;
    if (!AIAction)
        return;
    //! set neutral to be defeated in InitBattle so that their turns are skipped
    if (_ZNSt4list5emptyE(i)(&Country->AreaIDList) || Country->Defeated) {
        _ZN12CGameManager7EndTurnEv(self);
        return;
    }
    struct CActionNode *ActionNode = _ZN9CActionAI16setCpuDriverbyIdEii(_ZN9CActionAI8InstanceEv(),
                                                                        self->CurrentCountryIndex,
                                                                        self->AlwaysZero);
    if (ActionNode == NULL) {
        _ZN12CGameManager7EndTurnEv(self);
        return;
    }
    struct CountryAction Action = {0,
                                   ActionNode->CardID,
                                   ActionNode->StartAreaID,
                                   ActionNode->TargetAreaID,
                                   ActionNode->ArmyIndex};
    switch (ActionNode->ActionType) {
        default:
            return;
        case 0x10010:
            Action.ActionType = 5;
            Action.ArmyIndex = 0;
            break;
        case 0x10020:
            if (ActionNode->StartAreaID == ActionNode->TargetAreaID)
                Action.ActionType = 2;
            else
                Action.ActionType = 1;
            break;
        case 0x10030:
            Action.ActionType = 3;
            break;
        case 0x10050:
            Action.ActionType = 4;
    }
    _ZN8CCountry6ActionERK13CountryAction(Country, &Action);
}

//Move camera while ai is controlling player country
bool _ZN8CCountry13IsLocalPlayerEv(struct CCountry *self) {
    return !AIAction;
}

//Skip is implemented here
void _ZN10CGameState6UpdateEf(struct CGameState *self, float time) {
    if (self->IdleTimerEnabled) {
        self->IdleTimer -= time;
        if (self->IdleTimer <= 0.0) {
            self->IdleTimer = 0.0;
            self->IdleTimerEnabled = false;
        }
    }
    if (self->BuyingCard &&
        _ZN8CCountry14IsActionFinishEv(_ZN12CGameManager16GetPlayerCountryEv(&g_GameManager))) {
        if (_ZN10GUIBuyCard13CanBuySelCardEv(self->BuyCardGUI))
            _ZN10GUIBuyCard15ResetCardTargetEv(self->BuyCardGUI);
        else {
            _ZN10GUIBuyCard13ReleaseTargetEv(self->BuyCardGUI);
            _ZN10GUIElement4HideEv((struct GUIElement *) self->GameButtonCardRemove);
            _ZN10GUIElement4ShowEv((struct GUIElement *) self->GameButtonCard);
            _ZN10GUIElement4HideEv((struct GUIElement *) self->SmallCardGUI);
        }
        self->BuyingCard = false;
    }
    do {
        if ((self->PauseBoxGUI->Flags & GUI_Shown)
            || (self->OptionsGUI && (self->OptionsGUI->Flags & GUI_Shown))
            || (self->SaveGUI && (self->SaveGUI->Flags & GUI_Shown))
            || (self->WarningGUI && (self->WarningGUI->Flags & GUI_Shown))
            || (self->DialogueGUI && (self->DialogueGUI->Flags & GUI_Shown)))
            break;
        if (_ZN12CGameManager12IsManipulateEv(&g_GameManager)) {
            float speed[2];
            _ZN13CTouchInertia6UpdateEf(&self->CTouchInertia, time);
            if (_ZN13CTouchInertia8GetSpeedERfS0_(&self->CTouchInertia, &speed[0], &speed[1])) {
                if (_ZN6CScene4MoveEii(&g_Scene, (int) (-speed[0] * time),
                                       (int) (-speed[1] * time)))
                    _ZN13CTouchInertia4StopEv(&self->CTouchInertia);
            } else if (self->ShouldCameraAutoFixPos) {
                _ZN7CCamera13SetAutoFixPosEb(&g_Scene.CCamera, true);
                self->ShouldCameraAutoFixPos = false;
            }
        } else {
            if (SkipMode)
                time = 1.0;
            else if (g_GameSettings.Speed > 2)
                time *= (g_GameSettings.Speed == 3) ? 1.5 : 2.0;
        }
        _ZN15ecEffectManager6UpdateEf(_ZN15ecEffectManager8InstanceEv(), time);
        _ZN6CScene6UpdateEf(&g_Scene, time);
        _ZN13CFightTextMgr6UpdateEf(&g_FightTextMgr, time);
        if ((self->DefeatedGUI && (self->DefeatedGUI->Flags & GUI_Shown))
            || !self->GameNotInterrupted
            || g_GameManager.Result)
            break;
        if (!_ZN6CScene9IsBombingEv(&g_Scene))
            _ZN12CGameManager10GameUpdateEf(&g_GameManager, time);
    } while (SkipMode);
}

//Press end turn button
//Also: in game save-load menu related input
def_easytech(_ZN10CGameState7OnEventERK5Event)

bool __attribute__((weak))
_ZN10CGameState13OpenLoadEventERK5Event(struct CGameState *self, const struct Event *event) {
    return easytech(_ZN10CGameState7OnEventERK5Event)(self, event);
}

bool __attribute__((weak))
_ZN10CGameState14CloseLoadEventERK5Event(struct CGameState *self, const struct Event *event) {
    return easytech(_ZN10CGameState7OnEventERK5Event)(self, event);
}

bool __attribute__((weak))
_ZN10CGameState15CancelLoadEventERK5Event(struct CGameState *self, const struct Event *event) {
    return easytech(_ZN10CGameState7OnEventERK5Event)(self, event);
}

bool _ZN10CGameState7OnEventERK5Event(struct CGameState *self, struct Event const *event) {
    switch (event->type) {
        case GUI : {
            switch (event->info.GUI.type) {
                case Button : {
                    if ((struct GUIButton *) event->info.GUI.ptr == self->GameButtonRound) {
                        if (_ZN12CGameManager12IsManipulateEv(&g_GameManager)) {
                            if (self->BuyCardGUI->CardCanTarget) {
                                _ZN10GUIBuyCard13ReleaseTargetEv(self->BuyCardGUI);
                                _ZN10GUIElement4HideEv(
                                        (struct GUIElement *) self->GameButtonCardRemove);
                                _ZN10GUIElement4ShowEv((struct GUIElement *) self->GameButtonCard);
                                _ZN10GUIElement4HideEv((struct GUIElement *) self->SmallCardGUI);
                                self->BuyingCard = false;
                            }
                            _ZN10GUIElement4HideEv((struct GUIElement *) self->GameButtonCard);
                            _ZN10CGameState15ResetTouchStateEv(self);
                            _ZN10CGameState12UnselectAreaEv(self);
                            _ZN7CCamera13SetAutoFixPosEb(&g_Scene.CCamera, true);
                            self->ShouldCameraAutoFixPos = false;
                            g_Scene.NewRoundFlashing = false;
                            if (g_GameSettings.BattleAnimation) {
                                AIAction = true;
                            } else {
                                _ZN12CGameManager7EndTurnEv(&g_GameManager);
                                _ZN9CActionAI6InitAIEv(_ZN9CActionAI8InstanceEv());
                                _ZN10CGameState16UpdateAIProgressEv(self);
                            }
                        } else {
                            if (AIAction)
                                SkipMode = true;
                        }
                        return false;
                    }
                    struct GUIPauseBox *PauseBox = self->PauseBoxGUI;
                    if ((struct GUIButton *) event->info.GUI.ptr == PauseBox->ButtonRestart) {
                        return _ZN10CGameState13OpenLoadEventERK5Event(self, event);
                    }
                    if (self->SaveGUI != NULL &&
                        (struct GUIButton *) event->info.GUI.ptr == self->SaveGUI->ButtonOK)
                        return _ZN10CGameState14CloseLoadEventERK5Event(self, event);
                    if (self->SaveGUI != NULL &&
                        (struct GUIButton *) event->info.GUI.ptr == self->SaveGUI->ButtonBack)
                        return _ZN10CGameState15CancelLoadEventERK5Event(self, event);
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
    return easytech(_ZN10CGameState7OnEventERK5Event)(self, event);
}

//Don't move camera under skip mode
void _ZN7CCamera5UpateEf(struct CCamera *self, float time) {
    if (!self->IsMoving) return;
    if (SkipMode) {
        self->Speed[0] = 0.0;
        self->Speed[1] = 0.0;
        self->IsMoving = false;
        self->AutoFixPos = false;
        return;
    }
    int i;
    for (i = 0; i < 2; i++) {
        if (self->Speed[i] == 0.0) continue;
        if (fabs(self->TargetPos[i] - self->CenterPos[i]) < fabs(self->Speed[i] * 30.0 * time)) {
            self->CenterPos[i] = self->TargetPos[i];
            self->Speed[i] = 0.0;
        } else {
            self->CenterPos[i] += self->Speed[i] * 30.0 * time;
        }
    }
    if (self->Speed[0] == 0.0 && self->Speed[1] == 0.0) {
        self->IsMoving = false;
        self->AutoFixPos = false;
    }
}

//Disables battle animation
void
_ZN10CGameState12StartBattaleEiiib(struct CGameState *self, int StartAreaID, int TargetAreaID,
                                   int a3,
                                   bool Animation) {
    struct CFight fight;
    _ZN6CFightC1Ev(&fight);
    _ZN6CFight11FirstAttackEii(&fight, StartAreaID, TargetAreaID);
    _ZN6CFight11ApplyResultEv(&fight);
    if (fight.StartArmySecondAttack || fight.TargetArmySecondAttack) {
        _ZN6CFight12SecondAttackEv(&fight);
        _ZN6CFight11ApplyResultEv(&fight);
    }
    _ZN6CFightD1Ev(&fight);
}

void _ZN9GUIBattleC1Ev(struct GUIBattle *self) { _ZN10GUIElementC1Ev((struct GUIElement *) self); }
void _ZN9GUIBattleC2Ev(struct GUIBattle *self) __attribute__ ((alias("_ZN9GUIBattleC1Ev")));

void _ZN9GUIBattleD1Ev(struct GUIBattle *self) { _ZN10GUIElementD1Ev((struct GUIElement *) self); }
void _ZN9GUIBattleD2Ev(struct GUIBattle *self) __attribute__ ((alias("_ZN9GUIBattleD1Ev")));
void _ZN9GUIBattleD0Ev(struct GUIBattle *self) {
    _ZN9GUIBattleD1Ev(self);
    free(self);
}

void _ZN9GUIBattle4InitERK7GUIRect() {}

//Stop the game from saving commander data on game closing, which is suspected to cause data loss
//Now it will save whenever a change in medal number is detected

#include <ecLibrary.h>

def_easytech(_ZN10CCommander4SaveEv)

void _ZN10CCommander4SaveEv(struct CCommander *self) {}

def_easytech(_Z12ecGameUpdatef)

void _Z12ecGameUpdatef(float time) {
    static int medal = 50;
    if (medal != g_Commander.Medal) {
        easytech(_ZN10CCommander4SaveEv)(&g_Commander);
        medal = g_Commander.Medal;
    }
    easytech(_Z12ecGameUpdatef)(time);
}

__END_DECLS
