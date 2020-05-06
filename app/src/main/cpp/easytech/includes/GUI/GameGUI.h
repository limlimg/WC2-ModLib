#ifndef EASYTECH_GAMEGUI_H
#define EASYTECH_GAMEGUI_H

#include "GUIElement.h"
#include "../CArmy.h"

__BEGIN_DECLS

struct GUIGold;
struct GUITax {
    GUIElement_field;
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
};

void _ZN6GUITaxC1Ev(struct GUITax *self);

void _ZN6GUITaxC2Ev(struct GUITax *self);

void _ZN6GUITaxD0Ev(struct GUITax *self);

void _ZN6GUITaxD1Ev(struct GUITax *self);

void _ZN6GUITaxD2Ev(struct GUITax *self);

void _ZN6GUITax8OnRenderEv(struct GUITax *self);

void _ZN6GUITax4InitERK7GUIRect(struct GUITax *self, const struct GUIRect *);

void _ZN6GUITax7SetAreaEi(struct GUITax *self, int AreaID);

void _ZN6GUITax11SetIndustryEi(struct GUITax *self, int industry);

void _ZN6GUITax8SetMoneyEi(struct GUITax *self, int money);

struct GUISmallCard;
struct GUIAttackBox {
    GUIElement_field;
    struct GUIButton *x34PGUIElementButtonOK;
    struct GUIButton *x38PGUIElementButtonCancel;
    struct ecImage *Image_attack_board;
    struct ecImage *ImageStartCountry;
    struct ecImage *ImageTargetCountry;
    int StartAreaID;
    int TargetAreaID;
};

void _ZN12GUIAttackBoxC1Ev(struct GUIAttackBox *self);

void _ZN12GUIAttackBoxC2Ev(struct GUIAttackBox *self);

void _ZN12GUIAttackBoxD2Ev(struct GUIAttackBox *self);

bool _ZN12GUIAttackBox7OnEventERK5Event(struct GUIAttackBox *self, const struct Event *);

void _ZN12GUIAttackBox8OnRenderEv(struct GUIAttackBox *self);

void _ZN12GUIAttackBox4InitERK7GUIRect(struct GUIAttackBox *self, const struct GUIRect *);

void _ZN12GUIAttackBox9SetAttackEii(struct GUIAttackBox *self, int StartAreaID, int TargetAreaID);

struct GUIPauseBox {
    GUIElement_field;
    struct GUIButton *ButtonResume;
    struct GUIButton *ButtonSave;
    struct GUIButton *ButtonOption;
    struct GUIButton *ButtonRestart;
    struct GUIButton *ButtonQuit;
    struct ecTexture *ecTexture;
    struct ecImage *ImageMenuBox;
};

void _ZN11GUIPauseBoxC1Ev(struct GUIPauseBox *self);

void _ZN11GUIPauseBoxC2Ev(struct GUIPauseBox *self);

void _ZN11GUIPauseBoxD0Ev(struct GUIPauseBox *self);

void _ZN11GUIPauseBoxD1Ev(struct GUIPauseBox *self);

void _ZN11GUIPauseBoxD2Ev(struct GUIPauseBox *self);

bool _ZN11GUIPauseBox7OnEventERK5Event(struct GUIPauseBox *self, const struct Event *);

void _ZN11GUIPauseBox8OnRenderEv(struct GUIPauseBox *self);

void _ZN11GUIPauseBox4InitERK7GUIRect(struct GUIPauseBox *self, const struct GUIRect *);

struct GUICardTab;
struct GUITech;
struct GUIMedal;
struct GUICardList;
struct GUIBuyCard {
    GUIElement_field;
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
};

void _ZN10GUIBuyCardC1Ev(struct GUIBuyCard *self);

void _ZN10GUIBuyCardC2Ev(struct GUIBuyCard *self);

void _ZN10GUIBuyCardD0Ev(struct GUIBuyCard *self);

void _ZN10GUIBuyCardD1Ev(struct GUIBuyCard *self);

void _ZN10GUIBuyCardD2Ev(struct GUIBuyCard *self);

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

struct GUIOptions {
    GUIElement_field;
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
};

void _ZN10GUIOptionsC1Ev(struct GUIOptions *self);

void _ZN10GUIOptionsC2Ev(struct GUIOptions *self);

void _ZN10GUIOptionsD0Ev(struct GUIOptions *self);

void _ZN10GUIOptionsD1Ev(struct GUIOptions *self);

void _ZN10GUIOptionsD2Ev(struct GUIOptions *self);

bool _ZN10GUIOptions7OnEventERK5Event(struct GUIOptions *self, const struct Event *);

void _ZN10GUIOptions8OnRenderEv(struct GUIOptions *self);

void _ZN10GUIOptions4InitERK7GUIRect(struct GUIOptions *self, const struct GUIRect *);

struct GUISaveItem;
struct GUISave {
    GUIElement_field;
    struct GUIButton *ButtonBack;
    struct GUIButton *ButtonOK;
    struct GUISaveItem *SaveItem[7];
    struct ecTexture *Texture_commonbg;
    struct ecImage *Image_commonbg;
    int GameMode;
    bool Load;
    int SelectedItem;
};

void _ZN7GUISaveC1Ev(struct GUISave *self);

void _ZN7GUISaveC2Ev(struct GUISave *self);

void _ZN7GUISaveD0Ev(struct GUISave *self);

void _ZN7GUISaveD1Ev(struct GUISave *self);

void _ZN7GUISaveD2Ev(struct GUISave *self);

bool _ZN7GUISave7OnEventERK5Event(struct GUISave *self, const struct Event *);

void _ZN7GUISave8OnRenderEv(struct GUISave *self);

void _ZN7GUISave4InitERK7GUIRectib(struct GUISave *self, const struct GUIRect *, int GameMode,
                                   bool Load);

void _ZN7GUISave7SelItemEi(struct GUISave *self, int index);

struct GUIBattle;
struct GUIResult;
struct GUIDefeated {
    GUIElement_field;
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
};
struct GUIAIProgress;
struct GUIArmyItem {
    GUIButton_field;
    struct CArmy *Army;
};

void _ZN11GUIArmyItemC1Ev(struct GUIArmyItem *self);

void _ZN11GUIArmyItemC2Ev(struct GUIArmyItem *self);

void _ZN11GUIArmyItemD0Ev(struct GUIArmyItem *self);

void _ZN11GUIArmyItemD1Ev(struct GUIArmyItem *self);

void _ZN11GUIArmyItemD2Ev(struct GUIArmyItem *self);

void _ZN11GUIArmyItem8OnRenderEv(struct GUIArmyItem *self);

struct GUISelArmy {
    GUIElement_field;
    struct ecImage *Image_broad;
    struct GUIArmyItem *ArmyItem[4];
    int ArmyCount;
    int AreaID;
    int TargetArmyIndex;
    bool UseCard;
};

void _ZN10GUISelArmyC1Ev(struct GUISelArmy *self);

void _ZN10GUISelArmyC2Ev(struct GUISelArmy *self);

void _ZN10GUISelArmyD0Ev(struct GUISelArmy *self);

void _ZN10GUISelArmyD1Ev(struct GUISelArmy *self);

void _ZN10GUISelArmyD2Ev(struct GUISelArmy *self);

bool _ZN10GUISelArmy7OnEventERK5Event(struct GUISelArmy *self, const struct Event *event);

void _ZN10GUISelArmy8OnRenderEv(struct GUISelArmy *self);

void _ZN10GUISelArmy4InitERK7GUIRect(struct GUISelArmy *self, const struct GUIRect *);

void _ZN10GUISelArmy15MoveArmyToFrontEi(struct GUISelArmy *self, int index);

void _ZN10GUISelArmy7SetAreaEi(struct GUISelArmy *self, int AreaID);

void _ZN10GUISelArmy10TargetArmyEi(struct GUISelArmy *self, int index);

struct GUIBegin;
struct GUIBattleIntro;
struct GUIVictory;
struct GUITutorails;
struct GUIIap;
struct GUIDialogue {
    GUIElement_field;
    struct ecTexture *TextureGeneral;
    struct ecImage *ImageGeneral;
    struct ecTexture *Texture_dlgboard;
    struct ecImage *Image_dlgboard;
    struct ecUniFont font;
    struct ecText text;
    int eq0;
};

void _ZN11GUIDialogueC2Ev(struct GUIDialogue *self);

void _ZN11GUIDialogueD2Ev(struct GUIDialogue *self);

bool _ZN11GUIDialogue7OnEventERK5Event(struct GUIDialogue *self, const struct Event *event);

void _ZN11GUIDialogue8OnRenderEv(struct GUIDialogue *self);

void _ZN11GUIDialogue8OnUpdateEf(struct GUIDialogue *self, float time);

void _ZN11GUIDialogue4InitERK7GUIRect(struct GUIDialogue *self, const struct GUIRect *);

void _ZN11GUIDialogue7HideDlgEv(struct GUIDialogue *self);

void _ZN11GUIDialogue7ShowDlgEPKcS1_b(struct GUIDialogue *self, const char *TextName,
                                      const char *GeneralName, bool left);

struct GUIBank;
struct GUIActionInfo;
struct GUIWarning {
    GUIElement_field;
    struct GUIButtonEx *ButtonOK;
    struct GUIButton *ButtonCancle;
    struct ecTexture *Texture_warning_board;
    struct ecImage *Image_warning_board;
    struct ecLabelText LabelText1;
    struct ecLabelText LabelText2;
    int WarningType;
};

void _ZN10GUIWarningC2Ev(struct GUIWarning *self);

void _ZN10GUIWarningD2Ev(struct GUIWarning *self);

bool _ZN10GUIWarning7OnEventERK5Event(struct GUIWarning *self, const struct Event *event);

void _ZN10GUIWarning8OnRenderEv(struct GUIWarning *self);

void _ZN10GUIWarning8OnUpdateEf(struct GUIWarning *self, float time);

void _ZN10GUIWarning4InitERK7GUIRecti(struct GUIWarning *self, const struct GUIRect *, int type);

struct GUIEnd;

__END_DECLS

#endif //EASYTECH_GAMEGUI_H
