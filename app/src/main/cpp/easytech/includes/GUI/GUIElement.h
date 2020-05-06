#ifndef EASYTECH_GUIELEMENT_H
#define EASYTECH_GUIELEMENT_H

#include "../ecLibrary.h"

__BEGIN_DECLS

struct Event;

struct GUIRect {
    float Pos[2];
    float Size[2];
};

#define GUI_Shown (1<<17)

struct GUIElement;

struct GUIElement_vtable {
    void (*D1)(struct GUIElement *self);

    void (*D0)(struct GUIElement *self);

    bool (*OnEvent)(struct GUIElement *self, const struct Event *event);

    void (*OnRender)(struct GUIElement *self);

    void (*OnUpdate)(struct GUIElement *self, float time);
};

struct GUIElement {
#define GUIElement_field\
    struct GUIElement_vtable *vtable_GUIElement;\
    struct GUIElement *Parent;\
    struct GUIElement *FirstChild;\
    struct GUIElement *LastChild;\
    struct GUIElement *PreviousSibling;\
    struct GUIElement *NextSibling;\
    int ChildCount;\
    struct GUIRect Rect;\
    unsigned int Flags;\
    unsigned int Handle

    GUIElement_field;
};

void _ZN10GUIElementC1Ev(struct GUIElement *self);

void _ZN10GUIElementC2Ev(struct GUIElement *self);

void _ZN10GUIElementD0Ev(struct GUIElement *self);

void _ZN10GUIElementD1Ev(struct GUIElement *self);

void _ZN10GUIElementD2Ev(struct GUIElement *self);

bool _ZN10GUIElement7OnEventERK5Event(struct GUIElement *self, const struct Event *event);

void _ZN10GUIElement8OnRenderEv(struct GUIElement *self);

void _ZN10GUIElement8OnUpdateEf(struct GUIElement *self, float time);

void _ZN10GUIElement8AddChildEPS_b(struct GUIElement *self, struct GUIElement *, bool push_back);

void _ZN10GUIElement6CenterEv(struct GUIElement *self);

bool _ZN10GUIElement11CheckInRectEff(struct GUIElement *self, float x, float y);

bool _ZN10GUIElement11CheckInRectEffRK7GUIRect(struct GUIElement *self, float x, float y,
                                               const struct GUIRect *);

struct GUIElement *_ZN10GUIElement12FindByHandleEm(struct GUIElement *self, unsigned long);

void _ZN10GUIElement12FreeAllChildEv(struct GUIElement *self);

void _ZN10GUIElement9FreeChildEPS_(struct GUIElement *self, struct GUIElement *);

void _ZN10GUIElement10GetAbsRectER7GUIRect(struct GUIElement *self, struct GUIRect *);

void _ZN10GUIElement6GetPosERfS0_(struct GUIElement *self, float *x, float *y);

void _ZN10GUIElement4HideEv(struct GUIElement *self);

void _ZN10GUIElement4MoveEff(struct GUIElement *self, float x, float y);

bool _ZN10GUIElement11MoveToFrontEPS_(struct GUIElement *self, struct GUIElement *);

bool _ZN10GUIElement9PostEventERK5Event(struct GUIElement *self, const struct Event *);

bool _ZN10GUIElement11RemoveChildEPS_(struct GUIElement *self, struct GUIElement *);

void _ZN10GUIElement6RenderEv(struct GUIElement *self);

void _ZN10GUIElement9SetEnableEb(struct GUIElement *self, bool enable);

void _ZN10GUIElement6SetPosEff(struct GUIElement *self, float x, float y);

void _ZN10GUIElement10SetVisibleEb(struct GUIElement *self, bool visible);

void _ZN10GUIElement4ShowEv(struct GUIElement *self);

void _ZN10GUIElement6UpdateEf(struct GUIElement *self, float time);

extern struct ecTextureRes _ZN10GUIElement12s_TextureResE;

enum Event_type {
    GUI, Touch, BackPressed
};

enum Event_info_GUI_type {
    Button, ScrollBar, Warning, FadeIn, FadeOut, Other
};

struct Event_info_GUI {
    enum Event_info_GUI_type type;
    struct GUIElement *ptr;
    int info;
};

enum Event_info_Touch_type {
    begin, move, end
};

struct Event_info_Touch {
    enum Event_info_Touch_type type;
    float pos[2];
    int index;
};

union Event_info {
    struct Event_info_GUI GUI;//When a GUIElement is touched
    struct Event_info_Touch touch;
};

struct Event {
    enum Event_type type;
    union Event_info info;
};

struct IEventReceiver;

struct IEventReceiver_vtable {
    void (*D1)(struct IEventReceiver *self);

    void (*D0)(struct IEventReceiver *self);

    bool (*OnEvent)(struct IEventReceiver *self, const struct Event *event);
};

struct IEventReceiver {
#define IEventReceiver_field\
    struct IEventReceiver_vtable *vtable_IEventReceiver

    IEventReceiver_field;
};

//Button that can be pressed
struct GUIButton {
#define GUIButton_field\
    GUIElement_field;\
    struct ecUniFont *TexttFont;\
    struct ecText *Text;\
    int TextHeight;\
    struct ecImage *ButtonImage[2];\
    struct ecImage *GlowImage;\
    struct ecImage *BackgroundImage;\
    struct ecImage *TextImage;\
    int iPressedDown;\
    bool bPressedDown;\
    int PressDownIndex;\
    float Alpha;\
    float GreyValue;\
    bool GreyEnable;\
    bool Sound_btn;\
    float TextOffset[2];\
    int TextAlign

    GUIButton_field;
};

void _ZN9GUIButtonC1Ev(struct GUIButton *self);

void _ZN9GUIButtonC2Ev(struct GUIButton *self);

void _ZN9GUIButtonD0Ev(struct GUIButton *self);

void _ZN9GUIButtonD1Ev(struct GUIButton *self);

void _ZN9GUIButtonD2Ev(struct GUIButton *self);

bool _ZN9GUIButton7OnEventERK5Event(struct GUIButton *self, const struct Event *);

void _ZN9GUIButton8OnRenderEv(struct GUIButton *self);

void
_ZN9GUIButton4InitEPKcS1_RK7GUIRectP9ecUniFont(struct GUIButton *self, const char *, const char *,
                                               const struct GUIRect *, struct ecUniFont *);

void _ZN9GUIButton8SetAlphaEf(struct GUIButton *self, float alhpa);

void _ZN9GUIButton13SetBackgroundEPKc(struct GUIButton *self, const char *ImageName);

void _ZN9GUIButton7SetGlowEPKc(struct GUIButton *self, const char *ImageName);

void _ZN9GUIButton7SetTextEPKc(struct GUIButton *self, const char *text);

void _ZN9GUIButton7SetTextEPKt(struct GUIButton *self, const wchar_t *text);

void _ZN9GUIButton12SetTextAlignEi(struct GUIButton *self, int);

void _ZN9GUIButton12SetTextColorEm(struct GUIButton *self, color_t color);

void _ZN9GUIButton12SetTextImageEPKc(struct GUIButton *self, const char *ImageName);

void _ZN9GUIButton13SetTextOffsetEff(struct GUIButton *self, float x, float y);

//Button with images as text
struct GUIButtonEx {
    GUIButton_field;
    struct ecImage *ImageText[2];
    float TextPos[2];
};

void _ZN11GUIButtonExC1Ev(struct GUIButtonEx *self);

void _ZN11GUIButtonExC2Ev(struct GUIButtonEx *self);

void _ZN11GUIButtonExD0Ev(struct GUIButtonEx *self);

void _ZN11GUIButtonExD1Ev(struct GUIButtonEx *self);

void _ZN11GUIButtonExD2Ev(struct GUIButtonEx *self);

void _ZN11GUIButtonEx8OnRenderEv(struct GUIButtonEx *self);

void _ZN11GUIButtonEx12SetImageTextEPKcS1_(struct GUIButtonEx *self, const char *, const char *);

//Buttons that can be selected
struct GUIRadioButton {
#define GUIRadioButton_field\
    GUIButton_field;\
    bool Selected

    GUIRadioButton_field;
};

void _ZN14GUIRadioButtonC1Ev(struct GUIRadioButton *self);

void _ZN14GUIRadioButtonC2Ev(struct GUIRadioButton *self);

void _ZN14GUIRadioButtonD0Ev(struct GUIRadioButton *self);

void _ZN14GUIRadioButtonD1Ev(struct GUIRadioButton *self);

void _ZN14GUIRadioButtonD2Ev(struct GUIRadioButton *self);

void _ZN14GUIRadioButton8OnRenderEv(struct GUIRadioButton *self);

struct GUILevelSel {
    GUIElement_field;
    struct ecImage *Image_block;
    int CurrentLevel;
    int TotalLevel;
};

void _ZN11GUILevelSelC1Ev(struct GUILevelSel *self);

void _ZN11GUILevelSelC2Ev(struct GUILevelSel *self);

void _ZN11GUILevelSelD0Ev(struct GUILevelSel *self);

void _ZN11GUILevelSelD1Ev(struct GUILevelSel *self);

void _ZN11GUILevelSelD2Ev(struct GUILevelSel *self);

bool _ZN11GUILevelSel7OnEventERK5Event(struct GUILevelSel *self, const struct Event *);

void _ZN11GUILevelSel8OnRenderEv(struct GUILevelSel *self);

void
_ZN11GUILevelSel4InitERK7GUIRecti(struct GUILevelSel *self, const struct GUIRect *, int TotalLevel);

struct GUIImage;
struct GUIScrollBar;

//default final grandparent of elements
struct GUIManager {
    GUIElement_field;
    size_t x34;
    size_t x38;
    struct IEventReceiver *CurrentState;
    struct GUIElement *PGUIElementFader;
    float FadeTimer;
    int Fading;
    int FadeInfo;
};

struct GUIManager *_ZN10GUIManager8InstanceEv();

void _ZN10GUIManagerC1Ev(struct GUIManager *self);

void _ZN10GUIManagerC2Ev(struct GUIManager *self);

void _ZN10GUIManagerD0Ev(struct GUIManager *self);

void _ZN10GUIManagerD1Ev(struct GUIManager *self);

void _ZN10GUIManagerD2Ev(struct GUIManager *self);

bool _ZN10GUIManager7OnEventERK5Event(struct GUIManager *self, const struct Event *);

void _ZN10GUIManager4InitERK7GUIRect(struct GUIManager *self, const struct GUIRect *);

struct GUIButton *
_ZN10GUIManager9AddButtonEPKcS1_RK7GUIRectP10GUIElementP9ecUniFont(struct GUIManager *self,
                                                                   const char *, const char *,
                                                                   const struct GUIRect *,
                                                                   struct GUIElement *,
                                                                   struct ecUniFont *);

struct GUIImage *
_ZN10GUIManager8AddImageEPKcRK7GUIRectP10GUIElement(struct GUIManager *self, const char *ImageName,
                                                    const struct GUIRect *, struct GUIElement *);

struct GUIImage *
_ZN10GUIManager8AddImageEPKcRK13ecTextureRectRK7GUIRectP10GUIElementb(struct GUIManager *self,
                                                                      const char *ImageName,
                                                                      const struct ecTextureRect *,
                                                                      const struct GUIRect *,
                                                                      struct GUIElement *, bool);

struct GUIScrollBar *
_ZN10GUIManager12AddScrollBarERK7GUIRectP10GUIElementPKcS6_iiiii(struct GUIManager *self,
                                                                 const struct GUIRect *,
                                                                 struct GUIElement *, const char *,
                                                                 const char *, int, int, int, int,
                                                                 int);

void _ZN10GUIManager6FadeInEi(struct GUIManager *self, int info);

void _ZN10GUIManager7FadeOutEiP10GUIElement(struct GUIManager *self, int info, struct GUIElement *);

void _ZN10GUIManager14LoadTextureResEPKcb(struct GUIManager *self, const char *name, bool);

bool _ZN10GUIManager9PostEventERK5Event(struct GUIManager *self, const struct Event *);

void _ZN10GUIManager16ReleaseTexureResEv(struct GUIManager *self);

void _ZN10GUIManager6RenderEv(struct GUIManager *self);

void _ZN10GUIManager13SafeFreeChildEP10GUIElement(struct GUIManager *self, struct GUIElement *);

void _ZN10GUIManager16UnloadTextureResEPKc(struct GUIManager *self, const char *name);

void _ZN10GUIManager6UpdateEf(struct GUIManager *self, float time);

__END_DECLS

#endif //EASYTECH_GUIELEMENT_H
