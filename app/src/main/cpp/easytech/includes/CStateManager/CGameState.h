#ifndef EASYTECH_CGAMESTATE_H
#define EASYTECH_CGAMESTATE_H

#include "CStateManager.h"
#include "../GUI/GameGUI.h"

__BEGIN_DECLS

struct CGameState {
    CBaseState_field;
    IEventReceiver_field;
    float FirstTouchStartPos[2];
    bool FirstTouch;
    bool SecondTouch;
    float TouchPos[2][2];
    int FirstTouchIndex;
    int SecondTouchIndex;
    struct CTouchInertia CTouchInertia;
    struct GUIButton *GameButtonRound;
    struct GUIButton *GameButtonCard;
    struct GUIButton *GameButtonPause;
    struct GUIButton *GameButtonCardRemove;
    bool BuyingCard;
    struct GUIGold *GoldGUI;
    struct GUITax *TaxGUI;
    struct GUISmallCard *SmallCardGUI;
    struct GUIAttackBox *AttackBoxGUI;
    struct GUIPauseBox *PauseBoxGUI;
    struct GUIBuyCard *BuyCardGUI;
    struct GUIOptions *OptionsGUI;
    struct GUISave *SaveGUI;
    struct GUIBattle *BattleGUI;
    struct GUIResult *ResultGUI;
    struct GUIDefeated *DefeatedGUI;
    struct GUIAIProgress *AIProgressGUI;
    struct GUISelArmy *SelArmyGUI;
    struct GUIBegin *BeginGUI;
    struct GUIBattleIntro *BattleIntroGUI;
    struct GUIVictory *VictoryGUI;
    struct GUITutorails *TutorailsGUI;
    struct GUIIap *IapGUI;
    struct GUIDialogue *DialogueGUI;
    struct GUIBank *BankGUI;
    struct GUIActionInfo *ActionInfoGUI;
    struct GUIWarning *WarningGUI;
    struct GUIEnd *EndGUI;
    int MotionGameButtonRound;
    int MotionGameButtonCard;
    int MotionGameButtonPause;
    int MotionGUIGold;
    bool GameNotInterrupted;
    bool ShouldCameraAutoFixPos;
    bool IdleTimerEnabled;
    float IdleTimer;
};

void _ZN10CGameStateC1Ev(struct CGameState *self);

void _ZN10CGameStateC2Ev(struct CGameState *self);

void _ZN10CGameStateD0Ev(struct CGameState *self);

void _ZN10CGameStateD1Ev(struct CGameState *self);

void _ZN10CGameStateD2Ev(struct CGameState *self);

void _ZN10CGameState7OnEnterEv(struct CGameState *self);

void _ZN10CGameState6OnExitEv(struct CGameState *self);

void _ZN10CGameState6UpdateEf(struct CGameState *self, float time);

void _ZN10CGameState6RenderEv(struct CGameState *self);

bool _ZN10CGameState7OnEventERK5Event(struct CGameState *self, struct Event const *event);

void _ZN10CGameState10TouchBeginEffi(struct CGameState *self, float x, float y, int index);

void _ZN10CGameState9TouchMoveEffi(struct CGameState *self, float x, float y, int index);

void _ZN10CGameState8TouchEndEffi(struct CGameState *self, float x, float y, int index);

void _ZN10CGameState11BackPressedEv(struct CGameState *self);

void _ZN10CGameState11ScrollWheelEfff(struct CGameState *self, float, float, float);

void _ZN10CGameState15EnterBackgroundEv(struct CGameState *self);

void _ZN10CGameState15EnableIdleTimerEf(struct CGameState *self, float time);

void _ZN10CGameState14HideAIProgressEv(struct CGameState *self);

void _ZN10CGameState8InitGameEv(struct CGameState *self);

void _ZN10CGameState18PlayerCountryBeginEv(struct CGameState *self);

void _ZN10CGameState11ReleaseGameEv(struct CGameState *self);

void _ZN10CGameState15ResetTouchStateEv(struct CGameState *self);

void _ZN10CGameState10SelectAreaEi(struct CGameState *self, int AreaID);

void _ZN10CGameState12ShowDefeatedEP8CCountry(struct CGameState *self, struct CCountry *);

void _ZN10CGameState12ShowDialogueEPKcS1_b(struct CGameState *self, const char *DialogueString,
                                           const char *Commander, bool left);

void _ZN10CGameState11ShowWarningEi(struct CGameState *self, int type);

void
_ZN10CGameState12StartBattaleEiiib(struct CGameState *self, int StartAreaID, int TargetAreaID, int,
                                   bool Animation);

void _ZN10CGameState12UnselectAreaEv(struct CGameState *self);

void _ZN10CGameState16UpdateAIProgressEv(struct CGameState *self);

void _ZN10CGameState16UpdateActionInfoEv(struct CGameState *self);

__END_DECLS

#endif //EASYTECH_CGAMESTATE_H
