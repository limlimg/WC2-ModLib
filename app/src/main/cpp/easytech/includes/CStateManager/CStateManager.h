#ifndef EASYTECH_CSTATEMANAGER_H
#define EASYTECH_CSTATEMANAGER_H

#include "../GUI/GUIElement.h"

enum EState {
    Logo, Menu, Match, Load, Game, Edit
};

struct CBaseState;

struct _ZTV10CBaseState {
    void (*D1)(struct CBaseState *self);

    void (*D0)(struct CBaseState *self);

    void (*OnEnter)(struct CBaseState *self);

    void (*OnExit)(struct CBaseState *self);

    void (*Update)(struct CBaseState *self, float time);

    void (*Render)(struct CBaseState *self);

    bool (*OnEvent)(struct CBaseState *self, struct Event const *event);

    void (*TouchBegin)(struct CBaseState *self, float x, float y, int index);

    void (*TouchMove)(struct CBaseState *self, float x, float y, int index);

    void (*TouchEnd)(struct CBaseState *self, float x, float y, int index);

    void (*BackPressed)(struct CBaseState *self);

    void (*KeyDown)(struct CBaseState *self, int);

    void (*ScrollWheel)(struct CBaseState *self, float, float, float);

    void (*EnterBackground)(struct CBaseState *self);

    void (*EnterForeground)(struct CBaseState *self);
};

#define struct_CBaseState \
    struct _ZTV10CBaseState *vtable_CBaseState;\
    enum EState StateID;\
    bool Exist;

struct CBaseState {
    struct_CBaseState
#define __base_CBaseState struct_CBaseState
#ifdef __cplusplus

    void OnEnter();

    void OnExit();

    void TouchBegin(float x, float y, int index);

    void TouchMove(float x, float y, int index);

    void TouchEnd(float x, float y, int index);

    void BackPressed();

    void KeyDown(int);

    void ScrollWheel(float, float, float);

    void EnterBackground();

    void EnterForeground();

#ifdef extends_CBaseState
    extends_CBaseState
#endif
#endif
};

__BEGIN_DECLS
void _ZN10CBaseState7OnEnterEv(struct CBaseState *self);

void _ZN10CBaseState6OnExitEv(struct CBaseState *self);

void _ZN10CBaseState10TouchBeginEffi(struct CBaseState *self, float x, float y, int index);

void _ZN10CBaseState9TouchMoveEffi(struct CBaseState *self, float x, float y, int index);

void _ZN10CBaseState8TouchEndEffi(struct CBaseState *self, float x, float y, int index);

void _ZN10CBaseState11BackPressedEv(struct CBaseState *self);

void _ZN10CBaseState7KeyDownEi(struct CBaseState *self, int);

void _ZN10CBaseState11ScrollWheelEfff(struct CBaseState *self, float, float, float);

void _ZN10CBaseState15EnterBackgroundEv(struct CBaseState *self);

void _ZN10CBaseState15EnterForegroundEv(struct CBaseState *self);

__END_DECLS

struct CStateManager {
    struct CBaseState *States[6];
    enum EState CurrentStateID;
    enum EState NextUpdateStateID;
    struct CBaseState *CurrentState;
#ifdef __cplusplus

    static CStateManager *Instance();

    void Init();

    void Term();

    void Update(float time);

    void Render();

    void TouchBegin(float x, float y, int index);

    void TouchMove(float x, float y, int index);

    void TouchEnd(float x, float y, int index);

    void BackPressed();

    void KeyDown(int);

    void ScrollWheel(float, float, float);

    void EnterBackground();

    void EnterForeground();

    CBaseState *GetStatePtr(EState);

    void RegisterState(CBaseState *);

    void SetCurState(EState);

#ifdef extends_CStateManager
    extends_CStateManager
#endif
#endif
};

__BEGIN_DECLS
struct CStateManager *_ZN13CStateManager8InstanceEv();

void _ZN13CStateManagerC1Ev(struct CStateManager *self);

void _ZN13CStateManagerD1Ev(struct CStateManager *self);

void _ZN13CStateManager4InitEv(struct CStateManager *self);

void _ZN13CStateManager4TermEv(struct CStateManager *self);

void _ZN13CStateManager6UpdateEf(struct CStateManager *self, float time);

void _ZN13CStateManager6RenderEv(struct CStateManager *self);

void _ZN13CStateManager10TouchBeginEffi(struct CStateManager *self, float x, float y, int index);

void _ZN13CStateManager9TouchMoveEffi(struct CStateManager *self, float x, float y, int index);

void _ZN13CStateManager8TouchEndEffi(struct CStateManager *self, float x, float y, int index);

void _ZN13CStateManager11BackPressedEv(struct CStateManager *self);

void _ZN13CStateManager7KeyDownEi(struct CStateManager *self, int);

void _ZN13CStateManager11ScrollWheelEfff(struct CStateManager *self, float, float, float);

void _ZN13CStateManager15EnterBackgroundEv(struct CStateManager *self);

void _ZN13CStateManager15EnterForegroundEv(struct CStateManager *self);

struct CBaseState *_ZN13CStateManager11GetStatePtrE6EState(struct CStateManager *self, enum EState);

void
_ZN13CStateManager13RegisterStateEP10CBaseState(struct CStateManager *self, struct CBaseState *);

void _ZN13CStateManager11SetCurStateE6EState(struct CStateManager *self, enum EState);

__END_DECLS

//Smoothens touch pattern
struct CTouchInertia {
    float x0Unused;
    float x4Unused;
    float cosAngle;
    float sinAngle;
    float Speed;
    float Slowdown;
    bool Touching;
    int TouchIndex;
    float TouchTime;
    float Trackpoint[5][3];
    int TrackPointIndex;
    int TrackPointCount;
#ifdef  __cplusplus

    void Init();

    void AddTrackPoint(float x, float y);

    bool GetSpeed(float &x, float &y);

    float *GetStartPoint();

    void Stop();

    bool TouchBegin(float x, float y, int index);

    bool TouchMove(float x, float y, int index);

    bool TouchEnd(float x, float y, int index);

    void Update(float time);

#ifdef extends_CTouchInertia
    extends_CTouchInertia
#endif
#endif
};

__BEGIN_DECLS
void _ZN13CTouchInertiaC1Ev(struct CTouchInertia *self);

void _ZN13CTouchInertiaD1Ev(struct CTouchInertia *self);

void _ZN13CTouchInertia4InitEv(struct CTouchInertia *self);

void _ZN13CTouchInertia13AddTrackPointEff(struct CTouchInertia *self, float x, float y);

bool _ZN13CTouchInertia8GetSpeedERfS0_(struct CTouchInertia *self, float *x, float *y);

float *_ZN13CTouchInertia13GetStartPointEv(struct CTouchInertia *self);

void _ZN13CTouchInertia4StopEv(struct CTouchInertia *self);

bool _ZN13CTouchInertia10TouchBeginEffi(struct CTouchInertia *self, float x, float y, int index);

bool _ZN13CTouchInertia9TouchMoveEffi(struct CTouchInertia *self, float x, float y, int index);

bool _ZN13CTouchInertia8TouchEndEffi(struct CTouchInertia *self, float x, float y, int index);

void _ZN13CTouchInertia6UpdateEf(struct CTouchInertia *self, float time);

__END_DECLS

#endif //EASYTECH_CSTATEMANAGER_H
