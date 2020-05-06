#ifndef EASYTECH_CSCENE_H
#define EASYTECH_CSCENE_H

#include "CArea.h"
#include "ecLibrary.h"

__BEGIN_DECLS

struct CMedal {
    float Pos[2];
    float Offset_y;
    float Alpha;
    bool AnimationCompleted;
};

void _ZN6CMedalC1Ev(struct CMedal *self);

void _ZN6CMedalC2Ev(struct CMedal *self);

void _ZN6CMedal4InitEff(struct CMedal *self, float x, float y);

void _ZN6CMedal6RenderEv(struct CMedal *self);

void _ZN6CMedal5UpateEf(struct CMedal *self, float time);

struct CAreaMark {
    int Size[2];
    short *Mark;
};

void _ZN9CAreaMarkC1Ev(struct CAreaMark *self);

void _ZN9CAreaMarkC2Ev(struct CAreaMark *self);

void _ZN9CAreaMarkD1Ev(struct CAreaMark *self);

void _ZN9CAreaMarkD2Ev(struct CAreaMark *self);

void _ZN9CAreaMark4InitEi(struct CAreaMark *self, int MapID);

void _ZN9CAreaMark7ReleaseEv(struct CAreaMark *self);

short _ZN9CAreaMark7GetMarkEii(struct CAreaMark *self, int x, int y);

struct CCamera {
    float CenterPos[2];
    float Scale;
    float Speed[2];
    float TargetPos[2];
    bool IsMoving;
    bool AutoFixPos;
    float TopLeftPos[2];
    float MapSize[2];
    float ScreenHalfSize[2];
};

void _ZN7CCameraC1Ev(struct CCamera *self);

void _ZN7CCameraC2Ev(struct CCamera *self);

void _ZN7CCamera5ApplyEv(struct CCamera *self);

void _ZN7CCamera4InitEffff(struct CCamera *self, float x, float y, float w, float h);

bool _ZN7CCamera14IsRectInCameraEffff(struct CCamera *self, float x, float y, float w, float h);

bool
_ZN7CCamera21IsRectInVisibleRegionEffff(struct CCamera *self, float x, float y, float w, float h);

bool _ZN7CCamera4MoveEffb(struct CCamera *self, float x, float y, bool border);

void _ZN7CCamera6MoveToEffb(struct CCamera *self, float x, float y, bool border);

void _ZN7CCamera13SetAutoFixPosEb(struct CCamera *self, bool enabled);

bool _ZN7CCamera6SetPosEffb(struct CCamera *self, float x, float y, const bool border);

void _ZN7CCamera14SetPosAndScaleEfff(struct CCamera *self, float x, float y, float scale);

void _ZN7CCamera12SetSceneRectEffff(struct CCamera *self, float x, float y, float w, float h);

void _ZN7CCamera5UpateEf(struct CCamera *self, float time);

struct CBackground {
    int MapSize[2];
    int MapTopRightPos[2];
    int MapCount;
    struct ecTexture *BackgroundTexture[112];
    struct ecImage *BackgroundImage[112];
    struct ecTexture *BoxTexture[3];
    struct ecImage *BoxImage[3];
};

void _ZN11CBackgroundC1Ev(struct CBackground *self);

void _ZN11CBackgroundC2Ev(struct CBackground *self);

void _ZN11CBackgroundD1Ev(struct CBackground *self);

void _ZN11CBackgroundD2Ev(struct CBackground *self);

void _ZN11CBackground4InitEiiiiiffff(struct CBackground *self, int MapID, int TotalX, int TotalY,
                                     int TotalW, int TotalH, float EnableX, float EnableY,
                                     float EnableW, float EnableH);

void _ZN11CBackground6RenderEP7CCamera(struct CBackground *self, struct CCamera *camera);

void
_ZN11CBackground9RenderBoxEP7CCameraffff(struct CBackground *self, struct CCamera *camera, float x,
                                         float y, float w, float h);

struct CBomber {
    float PlanePos[2];
    struct ecImage *PlaneImages[2];
    struct ecImage *x10PecImage;
    int StartAreaID;
    int TargetAreaID;
    float FlySpeed;
    float PlaneXPosLimit;
    float TargetPos[2];
    float ArrivedTargetPos[2];
    float EffectTimer;
    float EffectSpeed;
    bool Bombing;
    bool BombOrAirborne;
    bool EffectComplete;
    bool PlaneArrived;
    bool IsAirborne;
    int ActionType;
    int AirStrikeFireCount;
};

void _ZN7CBomberC1Ev(struct CBomber *self);

void _ZN7CBomberC2Ev(struct CBomber *self);

void _ZN7CBomberD1Ev(struct CBomber *self);

void _ZN7CBomberD2Ev(struct CBomber *self);

void _ZN7CBomber4InitEv(struct CBomber *self);

void _ZN7CBomber8AirborneEi(struct CBomber *self, int TargetAreaID);

void _ZN7CBomber19AircraftCarrierBombEii(struct CBomber *self, int StartAreaID, int TargetAreaID);

void _ZN7CBomber8BombAreaEii(struct CBomber *self, int TargetAreaID, int ActionType);

bool _ZN7CBomber9IsBombingEv(struct CBomber *self);

void _ZN7CBomber6RenderEv(struct CBomber *self);

void _ZN7CBomber6UpdateEf(struct CBomber *self, float time);

#ifndef def_St6vector_P5CArea
#define def_St6vector_P5CArea
def__ZSt6vector(struct CArea *, P5CArea)
#endif
#ifndef def_St4list_P6CMedal
#define def_St4list_P6CMedal
def__ZSt4list(struct CMedal*, P6CMedal)
#endif
struct CScene {
    _ZSt6vector(P5CArea) AreaList;
    _ZSt6vector(P5CArea) RenderAreaList;
    struct CArea *AreaSelected;
    float FlashTimer;
    float FlashSpeed;
    int FightFlashAreaID[2];
    int *AreaData;
    struct ecTextureRes AreaImage;
    struct ecImage **ZoneImage;
    int AreaCount;
    struct CAreaMark AreaMark;
    struct CBackground *CBackground;
    struct CCamera CCamera;
    struct CBomber *CBomber;
    _ZSt4list(P6CMedal) MedalList;
    float VerticalArrowTimer;
    float VerticalArrowSpeed;
    float ArrowTimer;
    float ArrowSpeed;
    int *AdjoinRaw;
    int *Adjoin;
    float TopLeftPos[2];
    float Size[2];
    bool NewRoundFlashing;
};

void _ZN6CSceneC1Ev(struct CScene *self);

void _ZN6CSceneC2Ev(struct CScene *self);

void _ZN6CSceneD1Ev(struct CScene *self);

void _ZN6CSceneD2Ev(struct CScene *self);

void _ZN6CScene4InitEPKci(struct CScene *self, const char *areasenable, int MapID);

void _ZN6CScene7ReleaseEv(struct CScene *self);

void _ZN6CScene25AdjacentAreasEncirclementEi(struct CScene *self, int AreaID);

void _ZN6CScene8AirborneEi(struct CScene *self, int TargetAreaID);

void _ZN6CScene19AircraftCarrierBombEii(struct CScene *self, int StartAreaID, int TargetAreaID);

void _ZN6CScene20AllAreasEncirclementEv(struct CScene *self);

void _ZN6CScene20AreaDisableOutofRectEiiii(struct CScene *self, int x, int y, int w, int h);

void _ZN6CScene8BombAreaEii(struct CScene *self, int TargetAreaID, int ActionType);

void
_ZN6CScene12CalSceneRectERfS0_S0_S0_(struct CScene *self, float *x, float *y, float *w, float *h);

bool _ZN6CScene13CheckAdjacentEii(struct CScene *self, int AreaID_1, int AreaID_2);

void _ZN6CScene17CheckAdjacentDataEv(struct CScene *self);

bool _ZN6CScene15CheckAttackableEiii(struct CScene *self, int StartAreaID, int TargetAreaID,
                                     int ArmyIndex);

bool _ZN6CScene13CheckMoveableEiii(struct CScene *self, int StartAreaID, int TargetAreaID,
                                   int ArmyIndex);

void _ZN6CScene10ClearAreasEv(struct CScene *self);

void _ZN6CScene12ClearTargetsEv(struct CScene *self);

void _ZN6CScene11CreateArrowEii(struct CScene *self, int StartAreaID, int TargetAreaID);

void _ZN6CScene20CreateRenderAreaListEv(struct CScene *self);

void _ZN6CScene9DelAdjoinEii(struct CScene *self, int AreaID_1, int AreaID_2);

void _ZN6CScene9GainMedalEff(struct CScene *self, float x, float y);

struct CArea *_ZN6CScene15GetAdjacentAreaEii(struct CScene *self, int AreaID, int index);

int _ZN6CScene17GetAdjacentAreaIDEii(struct CScene *self, int AreaID, int index);

struct CArea *_ZN6CScene7GetAreaEi(struct CScene *self, int AreaID);

unsigned int _ZN6CScene19GetNumAdjacentAreasEi(struct CScene *self, int AreaID);

unsigned int _ZN6CScene11GetNumAreasEv(struct CScene *self);

struct CArea *_ZN6CScene15GetSelectedAreaEv(struct CScene *self);

float _ZN6CScene19GetTwoAreasDistanceEii(struct CScene *self, int AreaID_1, int AreaID_2);

int _ZN6CScene25GetTwoAreasDistanceSquareEii(struct CScene *self, int AreaID_1, int AreaID_2);

void _ZN6CScene13InitAreaImageEi(struct CScene *self, int MapID);

void _ZN6CScene9InitAreasEiPKc(struct CScene *self, int MapID, const char *areasenable);

bool _ZN6CScene8IsAdjoinEii(struct CScene *self, int StartAreaID, int TargetAreaID);

bool _ZN6CScene9IsBombingEv(struct CScene *self);

bool _ZN6CScene8IsMovingEv(struct CScene *self);

bool _ZN6CScene13IsRectInSecenEffff(struct CScene *self, float x, float y, float w, float h);

void _ZN6CScene10LoadAdjoinEi(struct CScene *self, int MapID);

void _ZN6CScene12LoadAreaDataEi(struct CScene *self, int MapID);

void _ZN6CScene14LoadAreaEnableEPKc(struct CScene *self, const char *areasenable);

void _ZN6CScene11LoadAreaTaxEi(struct CScene *self, int MapID);

void _ZN6CScene10MakeAdjoinEii(struct CScene *self, int AreaID_1, int AreaID_2);

bool _ZN6CScene4MoveEii(struct CScene *self, int x, int y);

void _ZN6CScene21MoveCameraBetweenAreaEii(struct CScene *self, int AreaID_1, int AreaID_2);

void _ZN6CScene22MoveCameraCenterToAreaEi(struct CScene *self, int AreaID);

void _ZN6CScene16MoveCameraToAreaEi(struct CScene *self, int AreaID);

bool _ZN6CScene6MoveToEii(struct CScene *self, int x, int y);

void _ZN6CScene9NewAdjoinEv(struct CScene *self);

void _ZN6CScene6RenderEv(struct CScene *self);

void _ZN6CScene14RenderSeaAreasEv(struct CScene *self);

void _ZN6CScene11ResetTargetEv(struct CScene *self);

void _ZN6CScene10SaveAdjoinEi(struct CScene *self, int MapID);

void _ZN6CScene12SaveAreaDataEi(struct CScene *self, int MapID);

void _ZN6CScene11SaveAreaTaxEi(struct CScene *self, int MapID);

struct CArea *_ZN6CScene12ScreenToAreaEff(struct CScene *self, float x, float y);

int _ZN6CScene14ScreenToAreaIDEff(struct CScene *self, float x, float y);

void _ZN6CScene13ScreenToSceneERfS0_(struct CScene *self, float *x, float *y);

void _ZN6CScene10SelectAreaEP5CArea(struct CScene *self, struct CArea *);

void _ZN6CScene10SelectAreaEi(struct CScene *self, int AreaID);

void _ZN6CScene14SetAreaCountryEiP8CCountry(struct CScene *self, int AreaID, struct CCountry *);

void _ZN6CScene15SetCameraToAreaEi(struct CScene *self, int AreaID);

void _ZN6CScene17SetSelAreaTargetsEP5CArea(struct CScene *self, struct CArea *);

void _ZN6CScene12UnselectAreaEv(struct CScene *self);

void _ZN6CScene6UpdateEf(struct CScene *self, float time);

extern struct CScene g_Scene;

__END_DECLS

#endif //EASYTECH_CSCENE_H
