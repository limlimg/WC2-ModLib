#ifndef EASYTECH_GUIELEMENT_H
#define EASYTECH_GUIELEMENT_H

#include "../ecLibrary.h"

struct Event;

struct GUIRect {
    float Pos[2];
    float Size[2];
#ifdef __cplusplus

    GUIRect &operator=(const GUIRect &a) {
        this->Pos[0] = a.Pos[0];
        this->Pos[1] = a.Pos[1];
        this->Size[0] = a.Size[0];
        this->Size[1] = a.Size[1];
    }

#endif
};

struct GUIElement;

struct _ZTV10GUIElement {
    void (*D1)(struct GUIElement *self);

    void (*D0)(struct GUIElement *self);

    bool (*OnEvent)(struct GUIElement *self, const struct Event *event);

    void (*OnRender)(struct GUIElement *self);

    void (*OnUpdate)(struct GUIElement *self, float time);
};

#define struct_GUIElement \
    struct _ZTV10GUIElement *vtable_GUIElement;\
    struct GUIElement *Parent;\
    struct GUIElement *FirstChild;\
    struct GUIElement *LastChild;\
    struct GUIElement *PreviousSibling;\
    struct GUIElement *NextSibling;\
    int ChildCount;\
    struct GUIRect Rect;\
    unsigned int Flags;\
    unsigned int Handle;

struct GUIElement {
    struct_GUIElement
#define __base_GUIElement struct_GUIElement

#ifdef __cplusplus
    static const int Shown = 1 << 17;

    bool OnEvent(const Event &event);

    void OnRender();

    void OnUpdate(float time);

    void AddChild(GUIElement *, bool push_back);

    void CenterEv();

    bool CheckInRect(float x, float y);

    bool CheckInRect(float x, float y, const struct GUIRect &);

    GUIElement *FindByHandle(unsigned long);

    void FreeAllChild();

    void FreeChild(GUIElement *);

    void GetAbsRect(struct GUIRect &);

    void GetPos(float &x, float &y);

    void Hide();

    void Move(float x, float y);

    bool MoveToFront(GUIElement *);

    bool PostEvent(const Event &);

    bool RemoveChild(GUIElement *);

    void Render();

    void SetEnable(bool enable);

    void SetPos(float x, float y);

    void SetVisible(bool visible);

    void Show();

    void Update(float time);

#endif
};

__BEGIN_DECLS
void _ZN10GUIElementC1Ev(struct GUIElement *self);

void _ZN10GUIElementD1Ev(struct GUIElement *self);

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
__END_DECLS

struct Event {
    enum EventType {
        GUI, Touch, BackPressed
    } type;
    union info {
        struct GUI {
            enum GUIType {
                Button, ScrollBar, Warning, FadeIn, FadeOut, Other
            } type;
            struct GUIElement *ptr;
            int info;
        } GUI;//When a GUIElement is touched
        struct Touch {
            enum TouchType {
                begin, move, end
            } type;
            float pos[2];
            int index;
        } touch;
    } info;
};

struct IEventReceiver;

struct _ZTV14IEventReceiver {
    void (*D1)(struct IEventReceiver *self);

    void (*D0)(struct IEventReceiver *self);

    bool (*OnEvent)(struct IEventReceiver *self, const struct Event *event);
};

#define struct_IEventReceiver \
    struct _ZTV14IEventReceiver *vtable_IEventReceiver;

struct IEventReceiver {
    struct_IEventReceiver
#define __base_IEventReceiver struct_IEventReceiver
};

//Button that can be pressed
#define struct_GUIButton \
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
    int TextAlign;

__sub_struct(GUIButton, GUIElement)
    struct_GUIButton
#define __base_GUIButton __base_GUIElement struct_GUIButton
#ifdef __cplusplus

    bool OnEvent(const Event &);

    void OnRender();

    void Init(const char *, const char *, const GUIRect &, struct ecUniFont *);

    void SetAlpha(float alhpa);

    void SetBackground(const char *ImageName);

    void SetGlow(const char *ImageName);

    void SetText(const char *text);

    void SetText(const wchar_t *text);

    void SetTextAlign(int);

    void SetTextColor(color_t color);

    void SetTextImage(const char *ImageName);

    void SetTextOffset(float x, float y);

#endif
__end_struct

__BEGIN_DECLS
void _ZN9GUIButtonC1Ev(struct GUIButton *self);

void _ZN9GUIButtonD1Ev(struct GUIButton *self);

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

__END_DECLS

//Button with images as text
__sub_struct(GUIButtonEx, GUIButton)
    struct ecImage *ImageText[2];
    float TextPos[2];
#ifdef __cplusplus

    void OnRender();

    void SetImageText(const char *, const char *);

#endif
__end_struct

__BEGIN_DECLS
void _ZN11GUIButtonExC1Ev(struct GUIButtonEx *self);

void _ZN11GUIButtonExD1Ev(struct GUIButtonEx *self);

void _ZN11GUIButtonEx8OnRenderEv(struct GUIButtonEx *self);

void _ZN11GUIButtonEx12SetImageTextEPKcS1_(struct GUIButtonEx *self, const char *, const char *);

__END_DECLS

//Buttons that can be selected
__sub_struct(GUIRadioButton, GUIButton)
    bool Selected;
#ifdef __cplusplus

    void OnRender();

#endif
__end_struct

__BEGIN_DECLS
void _ZN14GUIRadioButtonC1Ev(struct GUIRadioButton *self);

void _ZN14GUIRadioButtonD1Ev(struct GUIRadioButton *self);

void _ZN14GUIRadioButton8OnRenderEv(struct GUIRadioButton *self);

__END_DECLS

__sub_struct(GUILevelSel, GUIElement)
    struct ecImage *Image_block;
    int CurrentLevel;
    int TotalLevel;
#ifdef __cplusplus

    bool OnEvent(const Event &);

    void OnRender();

    void Init(const GUIRect &, int TotalLevel);

#endif
__end_struct

__BEGIN_DECLS
void _ZN11GUILevelSelC1Ev(struct GUILevelSel *self);

void _ZN11GUILevelSelD1Ev(struct GUILevelSel *self);

bool _ZN11GUILevelSel7OnEventERK5Event(struct GUILevelSel *self, const struct Event *);

void _ZN11GUILevelSel8OnRenderEv(struct GUILevelSel *self);

void
_ZN11GUILevelSel4InitERK7GUIRecti(struct GUILevelSel *self, const struct GUIRect *, int TotalLevel);

__END_DECLS

struct GUIImage;
struct GUIScrollBar;

//default final grandparent of elements
__sub_struct(GUIManager, GUIElement)
    size_t x34;
    size_t x38;
    struct IEventReceiver *CurrentState;
    struct GUIElement *PGUIElementFader;
    float FadeTimer;
    int Fading;
    int FadeInfo;
#ifdef __cplusplus

    static GUIManager *Instance();

    bool OnEvent(const Event &);

    void Init(const GUIRect &);

    GUIButton *AddButton(const char *, const char *, const GUIRect &, GUIElement *, ecUniFont *);

    GUIImage *AddImage(const char *ImageName, const GUIRect &, GUIElement *);

    GUIImage *
    AddImage(const char *ImageName, const ecTextureRect &, const GUIRect &, GUIElement *, bool);

    GUIScrollBar *
    AddScrollBar(const GUIRect &, GUIElement *, const char *, const char *, int, int, int, int,
                 int);

    void FadeIn(int info);

    void FadeOut(int info, GUIElement *);

    void LoadTextureRes(const char *name, bool);

    bool PostEvent(const Event &);

    void ReleaseTexureRes();

    void Render();

    void SafeFreeChild(GUIElement *);

    void UnloadTextureRes(const char *name);

    void Update(float time);

#endif
__end_struct

__BEGIN_DECLS
struct GUIManager *_ZN10GUIManager8InstanceEv();

void _ZN10GUIManagerC1Ev(struct GUIManager *self);

void _ZN10GUIManagerD1Ev(struct GUIManager *self);

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
