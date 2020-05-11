#ifndef EASYTECH_CGAMESTATE_H
#define EASYTECH_CGAMESTATE_H

#include "CStateManager.h"
#include "../GUI/GameGUI.h"
#include "../CGameManager.h"
#include "../cxxvector.h"

__sub2_struct(CGameState, CBaseState, IEventReceiver)
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
#ifdef __cplusplus

    void OnEnter();

    void OnExit();

    void Update(float time);

    void Render();

    bool OnEvent(const Event &event);

    void TouchBegin(float x, float y, int index);

    void TouchMove(float x, float y, int index);

    void TouchEnd(float x, float y, int index);

    void BackPressed();

    void ScrollWheel(float, float, float);

    void EnterBackground();

    void EnableIdleTimer(float time);

    void HideAIProgress();

    void InitGame();

    void PlayerCountryBegin();

    void ReleaseGame();

    void ResetTouchState();

    void SelectArea(int AreaID);

    void ShowDefeated(CCountry *);

    void ShowDialogue(const char *DialogueString, const char *Commander, bool left);

    void ShowWarning(int type);

    void StartBattale(int StartAreaID, int TargetAreaID, int, bool Animation);

    void UnselectArea();

    void UpdateAIProgress();

    void UpdateActionInfo();

#endif
__end_struct

__BEGIN_DECLS
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

struct CFight {
    vector(int) StartArmyDices;
    vector(int) TargetArmyDices;
    struct CCountry *AirStrikeCountry;
    int StartArmyNumDicesLost;
    int TargetArmyNumDicesLost;
    int StartArmyDefence;
    int StartArmyExtraAttack;
    int TargetArmyDefence;
    int TargetArmyExtraAttack;
    int x34;
    int x38;
    int StartAreaID;
    int TargetAreaID;
    int StartArmyNumDices;
    int TargetArmyNumDices;
    int StartArmyNumDices1;
    int TargetArmyNumDices1;
    int StartArmyReceiveDamage;
    int TargetArmyReceiveDamage;
    int StartArmyReceiveDamageFirst;
    int TargetArmyReceiveDamageFirst;
    int x64;
    int x68;
    int StartArmyMaxAttack;
    int StartArmyMinAttack;
    int TargetArmyMaxAttack;
    int TargetArmyMinAttack;
    int AirStrikeAttack;
    int AirStrikeType;
    bool CanCounter;
    int SecondAttackIndex;
    bool StartArmySecondAttack;
    bool TargetArmySecondAttack;
    int SecondAttackSideIndex;
    bool x94;
#ifdef __cplusplus

    void AirStrikesAttack(CCountry *, int TargetAreaID, int type);

    void AirStrikesAttack(int StartAreaID, int TargetAreaID);

    void ApplyResult();

    void FirstAttack(int StartAreaID, int TargetAreaID);

    int GetAttackerResult(int index);

    int GetDefenderResult(int index);

    void NormalAttack(int StartAreaID, int TargetAreaID);

    void SecondAttack();

#endif
};

__BEGIN_DECLS
void _ZN6CFightC1Ev(struct CFight *self);

void _ZN6CFightC2Ev(struct CFight *self);

void _ZN6CFightD1Ev(struct CFight *self);

void _ZN6CFightD2Ev(struct CFight *self);

void
_ZN6CFight16AirStrikesAttackEP8CCountryii(struct CFight *self, struct CCountry *, int TargetAreaID,
                                          int type);

void _ZN6CFight16AirStrikesAttackEii(struct CFight *self, int StartAreaID, int TargetAreaID);

void _ZN6CFight11ApplyResultEv(struct CFight *self);

void _ZN6CFight11FirstAttackEii(struct CFight *self, int StartAreaID, int TargetAreaID);

int _ZN6CFight17GetAttackerResultEi(struct CFight *self, int index);

int _ZN6CFight17GetDefenderResultEi(struct CFight *self, int index);

void _ZN6CFight12NormalAttackEii(struct CFight *self, int StartAreaID, int TargetAreaID);

void _ZN6CFight12SecondAttackEv(struct CFight *self);

__END_DECLS

#endif //EASYTECH_CGAMESTATE_H
