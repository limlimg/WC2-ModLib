#ifndef EASYTECH_GAMEGUI_H
#define EASYTECH_GAMEGUI_H

#include "GUIElement.h"
#include "../CScene.h"

struct GUIGold;

__sub_struct(GUITax, GUIElement)
    struct ecImage *Image_income_board;
    struct ecImage *Image_income_board2;
    struct ecImage *ImageCommander;
    struct ecText MoneyText;
    int Money;
    struct ecText IndustryText;
    int Industry;
    struct ecImage *Image_stamp[4];
    int InstalltionType;
    struct CCountry *Country;
#ifdef __cplusplus

    void OnRender();

    void Init(const GUIRect &);

    void SetArea(int AreaID);

    void SetIndustry(int industry);

    void SetMoney(int money);

#ifdef extends_GUITax
    extends_GUITax
#endif
#endif
__end_struct

__BEGIN_DECLS
void _ZN6GUITaxC1Ev(struct GUITax *self);

void _ZN6GUITaxD1Ev(struct GUITax *self);

void _ZN6GUITax8OnRenderEv(struct GUITax *self);

void _ZN6GUITax4InitERK7GUIRect(struct GUITax *self, const struct GUIRect *);

void _ZN6GUITax7SetAreaEi(struct GUITax *self, int AreaID);

void _ZN6GUITax11SetIndustryEi(struct GUITax *self, int industry);

void _ZN6GUITax8SetMoneyEi(struct GUITax *self, int money);

__END_DECLS

__sub_struct(GUISmallCard, GUIElement)
    struct ecImage *CardImage;
#ifdef __cplusplus

    void OnRender();

    void Init(const GUIRect &);

    void SetCard(CardDef *);

#ifdef extends_GUISmallCard
    extends_GUISmallCard
#endif
#endif
__end_struct

__BEGIN_DECLS
void _ZN12GUISmallCardC1Ev(struct GUISmallCard *self);

void _ZN12GUISmallCardD1Ev(struct GUISmallCard *self);

void _ZN12GUISmallCard8OnRenderEv(struct GUISmallCard *self);

void _ZN12GUISmallCard4InitERK7GUIRect(struct GUISmallCard *self, const struct GUIRect *);

void _ZN12GUISmallCard7SetCardEP7CardDef(struct GUISmallCard *self, struct CardDef *);

__END_DECLS

__sub_struct(GUIAttackBox, GUIElement)
    struct GUIButton *x34PGUIElementButtonOK;
    struct GUIButton *x38PGUIElementButtonCancel;
    struct ecImage *Image_attack_board;
    struct ecImage *ImageStartCountry;
    struct ecImage *ImageTargetCountry;
    int StartAreaID;
    int TargetAreaID;
#ifdef __cplusplus

    bool OnEvent(const Event &);

    void OnRender();

    void Init(const GUIRect &);

    void SetAttack(int StartAreaID, int TargetAreaID);

#ifdef extends_GUIAttackBox
    extends_GUIAttackBox
#endif
#endif
__end_struct

__BEGIN_DECLS
void _ZN12GUIAttackBoxC1Ev(struct GUIAttackBox *self);

void _ZN12GUIAttackBoxD1Ev(struct GUIAttackBox *self);

bool _ZN12GUIAttackBox7OnEventERK5Event(struct GUIAttackBox *self, const struct Event *);

void _ZN12GUIAttackBox8OnRenderEv(struct GUIAttackBox *self);

void _ZN12GUIAttackBox4InitERK7GUIRect(struct GUIAttackBox *self, const struct GUIRect *);

void _ZN12GUIAttackBox9SetAttackEii(struct GUIAttackBox *self, int StartAreaID, int TargetAreaID);

__END_DECLS

__sub_struct(GUIPauseBox, GUIElement)
    struct GUIButton *ButtonResume;
    struct GUIButton *ButtonSave;
    struct GUIButton *ButtonOption;
    struct GUIButton *ButtonRestart;
    struct GUIButton *ButtonQuit;
    struct ecTexture *ecTexture;
    struct ecImage *ImageMenuBox;
#ifdef __cplusplus

    bool OnEvent(const Event &);

    void OnRender();

    void Init(const GUIRect &);

#ifdef extends_GUIPauseBox
    extends_GUIPauseBox
#endif
#endif
__end_struct

__BEGIN_DECLS
void _ZN11GUIPauseBoxC1Ev(struct GUIPauseBox *self);

void _ZN11GUIPauseBoxD1Ev(struct GUIPauseBox *self);

bool _ZN11GUIPauseBox7OnEventERK5Event(struct GUIPauseBox *self, const struct Event *);

void _ZN11GUIPauseBox8OnRenderEv(struct GUIPauseBox *self);

void _ZN11GUIPauseBox4InitERK7GUIRect(struct GUIPauseBox *self, const struct GUIRect *);

__END_DECLS

struct GUICardTab;
struct GUITech;
struct GUIMedal;
struct GUICardList;

__sub_struct(GUIBuyCard, GUIElement)
    struct GUIButton *ButtonBack;
    struct GUIButton *ButtonOK;
    struct GUICardTab *CardTab;
    struct GUIGold *GoldGUI;
    struct GUITech *TechGUI;
    struct GUIMedal *MedalGUI;
    struct ecTexture *BuyCardBgTexture;
    struct ecImage *BuyCardBgImage;
    struct ecTexture *BroadTexture;
    struct ecImage *BroadImage;
    struct ecTexture *UnknownTexture;
    struct ecImage *UnknownImage;
    struct ecUniFont Font;
    struct ecText NameText;
    struct ecText IntroText;
    struct GUICardList *CardListGUI[5];
    int Unknown1;
    int SelCardID;
    int Unknown2;
    bool CardCanTarget;
    bool CardTargetArmy;
#ifdef __cplusplus

    bool OnEvent(const Event &);

    void OnRender();

    void Init(const GUIRect &);

    bool CanBuySelCard();

    struct CardDef *GetSelCard();

    void ReleaseTarget();

    void ResetCardState();

    void ResetCardTarget();

    void SelCard(int CardTab, int index);

    void SetSelCardIntro();

#ifdef extends_GUIBuyCard
    extends_GUIBuyCard
#endif
#endif
__end_struct

__BEGIN_DECLS
void _ZN10GUIBuyCardC1Ev(struct GUIBuyCard *self);

void _ZN10GUIBuyCardD1Ev(struct GUIBuyCard *self);

bool _ZN10GUIBuyCard7OnEventERK5Event(struct GUIBuyCard *self, const struct Event *);

void _ZN10GUIBuyCard8OnRenderEv(struct GUIBuyCard *self);

void _ZN10GUIBuyCard4InitERK7GUIRect(struct GUIBuyCard *self, const struct GUIRect *);

bool _ZN10GUIBuyCard13CanBuySelCardEv(struct GUIBuyCard *self);

struct CardDef *_ZN10GUIBuyCard10GetSelCardEv(struct GUIBuyCard *self);

void _ZN10GUIBuyCard13ReleaseTargetEv(struct GUIBuyCard *self);

void _ZN10GUIBuyCard14ResetCardStateEv(struct GUIBuyCard *self);

void _ZN10GUIBuyCard15ResetCardTargetEv(struct GUIBuyCard *self);

void _ZN10GUIBuyCard7SelCardEii(struct GUIBuyCard *self, int CardTab, int index);

void _ZN10GUIBuyCard15SetSelCardIntroEv(struct GUIBuyCard *self);

__END_DECLS

__sub_struct(GUIOptions, GUIElement)
    struct GUIButton *ButtonBack;
    struct GUIButton *ButtonOK;
    struct GUIScrollBar *ScrollBar1;
    struct GUIScrollBar *ScrollBar2;
    struct GUIButton *BattleAnimationUncheck;
    struct GUIButtonEx *BattleAnimationCheck;
    struct GUILevelSel *SelSpeed;
    struct ecTexture *x50PecTexture_commonbg;
    struct ecImage *x54PecImage_commonbg;
    struct ecTexture *x58PecTexture_board_options;
    struct ecImage *x5CPecImage_board_options;
    float x60fWidth;
#ifdef __cplusplus

    bool OnEvent(const Event &);

    void OnRender();

    void Init(const GUIRect &);

#ifdef extends_GUIOptions
    extends_GUIOptions
#endif
#endif
__end_struct

__BEGIN_DECLS
void _ZN10GUIOptionsC1Ev(struct GUIOptions *self);

void _ZN10GUIOptionsD1Ev(struct GUIOptions *self);

bool _ZN10GUIOptions7OnEventERK5Event(struct GUIOptions *self, const struct Event *);

void _ZN10GUIOptions8OnRenderEv(struct GUIOptions *self);

void _ZN10GUIOptions4InitERK7GUIRect(struct GUIOptions *self, const struct GUIRect *);

__END_DECLS

struct GUISaveItem;

__sub_struct(GUISave, GUIElement)
    struct GUIButton *ButtonBack;
    struct GUIButton *ButtonOK;
    struct GUISaveItem *SaveItem[7];
    struct ecTexture *Texture_commonbg;
    struct ecImage *Image_commonbg;
    int GameMode;
    bool Load;
    int SelectedItem;
#ifdef __cplusplus

    bool OnEvent(const struct Event &);

    void OnRender();

    void Init(const struct GUIRect &, int GameMode, bool Load);

    void SelItem(int index);

#ifdef extends_GUISave
    extends_GUISave
#endif
#endif
__end_struct

__BEGIN_DECLS
void _ZN7GUISaveC1Ev(struct GUISave *self);

void _ZN7GUISaveD1Ev(struct GUISave *self);

bool _ZN7GUISave7OnEventERK5Event(struct GUISave *self, const struct Event *);

void _ZN7GUISave8OnRenderEv(struct GUISave *self);

void _ZN7GUISave4InitERK7GUIRectib(struct GUISave *self, const struct GUIRect *, int GameMode,
                                   bool Load);

void _ZN7GUISave7SelItemEi(struct GUISave *self, int index);

__END_DECLS

struct GUIBattle;
struct GUIResult;

__sub_struct(GUIDefeated, GUIElement)
    struct GUIButtonEx *ButtonOK;
    struct ecTexture *x38;
    struct ecImage *Image_country_defeat;
    struct ecTextureRes TextureRes_flag;
    struct ecImage *ImageFlag;
    struct ecImage *ImageGeneral;
    struct CCountry *DefeatedCountry;
    struct ecText Text_defeated;
    float AutoCloseTimer;
    float x9C;
    float xA0;
    int xA4;
#ifdef __cplusplus

    bool OnEvent(const Event &);

    void OnRender();

    void OnUpdate(float time);

    void Init(const GUIRect &);

    void HideDefeated();

    void ShowDefeated(CCountry *country);

#ifdef extends_GUIDefeated
    extends_GUIDefeated
#endif
#endif
__end_struct

__BEGIN_DECLS
void _ZN11GUIDefeatedC1Ev(struct GUIDefeated *self);

void _ZN11GUIDefeatedD1Ev(struct GUIDefeated *self);

bool _ZN11GUIDefeated7OnEventERK5Event(struct GUIDefeated *self, const struct Event *event);

void _ZN11GUIDefeated8OnRenderEv(struct GUIDefeated *self);

void _ZN11GUIDefeated8OnUpdateEf(struct GUIDefeated *self, float time);

void _ZN11GUIDefeated4InitERK7GUIRect(struct GUIDefeated *self, const struct GUIRect *rect);

void _ZN11GUIDefeated12HideDefeatedEv(struct GUIDefeated *self);

void _ZN11GUIDefeated12ShowDefeatedEP8CCountry(struct GUIDefeated *self, struct CCountry *country);

__END_DECLS

__sub_struct(GUIAIProgress, GUIElement)
    struct ecImage *Image_aiprogress;
    struct ecImage *Image_progressbar;
    struct ecImage *Image_flag;
    int ProgressCount;
#ifdef __cplusplus

    void OnRender();

    void Init(const GUIRect &);

    void SetCurCountryName(const char *CountryName);

#ifdef extends_GUIAIProgress
    extends_GUIAIProgress
#endif
#endif
__end_struct

__BEGIN_DECLS
void _ZN13GUIAIProgressC1Ev(struct GUIAIProgress *self);

void _ZN13GUIAIProgressD1Ev(struct GUIAIProgress *self);

void _ZN13GUIAIProgress8OnRenderEv(struct GUIAIProgress *self);

void _ZN13GUIAIProgress4InitERK7GUIRect(struct GUIAIProgress *self, const struct GUIRect *);

void _ZN13GUIAIProgress17SetCurCountryNameEPKc(struct GUIAIProgress *self, const char *CountryName);

__END_DECLS

__sub_struct(GUIArmyItem, GUIButton)
    struct CArmy *Army;
#ifdef __cplusplus

    void OnRender();

#ifdef extends_GUIArmyItem
    extends_GUIArmyItem
#endif
#endif
__end_struct

__BEGIN_DECLS
void _ZN11GUIArmyItemC1Ev(struct GUIArmyItem *self);

void _ZN11GUIArmyItemD1Ev(struct GUIArmyItem *self);

void _ZN11GUIArmyItem8OnRenderEv(struct GUIArmyItem *self);

__END_DECLS

__sub_struct(GUISelArmy, GUIElement)
    struct ecImage *Image_broad;
    struct GUIArmyItem *ArmyItem[4];
    int ArmyCount;
    int AreaID;
    int TargetArmyIndex;
    bool UseCard;
#ifdef __cplusplus

    bool OnEvent(const Event &event);

    void OnRender();

    void Init(const GUIRect &);

    void MoveArmyToFront(int index);

    void SetArea(int AreaID);

    void TargetArmy(int index);

#ifdef extends_GUISelArmy
    extends_GUISelArmy
#endif
#endif
__end_struct

__BEGIN_DECLS
void _ZN10GUISelArmyC1Ev(struct GUISelArmy *self);

void _ZN10GUISelArmyD1Ev(struct GUISelArmy *self);

bool _ZN10GUISelArmy7OnEventERK5Event(struct GUISelArmy *self, const struct Event *event);

void _ZN10GUISelArmy8OnRenderEv(struct GUISelArmy *self);

void _ZN10GUISelArmy4InitERK7GUIRect(struct GUISelArmy *self, const struct GUIRect *);

void _ZN10GUISelArmy15MoveArmyToFrontEi(struct GUISelArmy *self, int index);

void _ZN10GUISelArmy7SetAreaEi(struct GUISelArmy *self, int AreaID);

void _ZN10GUISelArmy10TargetArmyEi(struct GUISelArmy *self, int index);

__END_DECLS

struct GUIBegin;
struct GUIBattleIntro;
struct GUIVictory;
struct GUITutorails;
struct GUIIap;

__sub_struct(GUIDialogue, GUIElement)
    struct ecTexture *TextureGeneral;
    struct ecImage *ImageGeneral;
    struct ecTexture *Texture_dlgboard;
    struct ecImage *Image_dlgboard;
    struct ecUniFont font;
    struct ecText text;
    int eq0;
#ifdef __cplusplus

    bool OnEvent(const Event &event);

    void OnRender();

    void OnUpdate(float time);

    void Init(const GUIRect &);

    void HideDlg();

    void ShowDlg(const char *TextName, const char *GeneralName, bool left);

#ifdef extends_GUIDialogue
    extends_GUIDialogue
#endif
#endif
__end_struct

__BEGIN_DECLS
void _ZN11GUIDialogueC1Ev(struct GUIDialogue *self);

void _ZN11GUIDialogueD1Ev(struct GUIDialogue *self);

bool _ZN11GUIDialogue7OnEventERK5Event(struct GUIDialogue *self, const struct Event *event);

void _ZN11GUIDialogue8OnRenderEv(struct GUIDialogue *self);

void _ZN11GUIDialogue8OnUpdateEf(struct GUIDialogue *self, float time);

void _ZN11GUIDialogue4InitERK7GUIRect(struct GUIDialogue *self, const struct GUIRect *);

void _ZN11GUIDialogue7HideDlgEv(struct GUIDialogue *self);

void _ZN11GUIDialogue7ShowDlgEPKcS1_b(struct GUIDialogue *self, const char *TextName,
                                      const char *GeneralName, bool left);

__END_DECLS

struct GUIBank;
struct GUIActionInfo;

__sub_struct(GUIWarning, GUIElement)
    struct GUIButtonEx *ButtonOK;
    struct GUIButton *ButtonCancle;
    struct ecTexture *Texture_warning_board;
    struct ecImage *Image_warning_board;
    struct ecLabelText LabelText1;
    struct ecLabelText LabelText2;
    int WarningType;
#ifdef __cplusplus

    bool OnEventERK5Event(const Event &event);

    void OnRenderEv();

    void OnUpdateEf(float time);

    void InitERK7GUIRecti(const GUIRect &, int type);

#ifdef extends_GUIWarning
    extends_GUIWarning
#endif
#endif
__end_struct

__BEGIN_DECLS
void _ZN10GUIWarningC1Ev(struct GUIWarning *self);

void _ZN10GUIWarningD1Ev(struct GUIWarning *self);

bool _ZN10GUIWarning7OnEventERK5Event(struct GUIWarning *self, const struct Event *event);

void _ZN10GUIWarning8OnRenderEv(struct GUIWarning *self);

void _ZN10GUIWarning8OnUpdateEf(struct GUIWarning *self, float time);

void _ZN10GUIWarning4InitERK7GUIRecti(struct GUIWarning *self, const struct GUIRect *, int type);

__END_DECLS
struct GUIEnd;

#endif //EASYTECH_GAMEGUI_H
