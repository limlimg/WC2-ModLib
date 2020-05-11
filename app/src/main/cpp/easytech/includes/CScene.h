#ifndef EASYTECH_CSCENE_H
#define EASYTECH_CSCENE_H

#include "CGameManager.h"
#include "ecLibrary.h"

struct SaveArmyInfo;

struct CArmy {
    enum Card {
        Assault, Defence, Carrier, Commander
    };
    struct ArmyDef *BasicAbilities;
    struct CCountry *Country;
    int Hp;
    int MaxHp;
    int Movement;
    int Cards;
    int Level;
    int Exp;
    int Morale;
    int MoraleUpTurn;
    float Direction;
    bool Active;
#ifdef __cplusplus

    void Init(ArmyDef *, CCountry *);

    void SaveArmy(SaveArmyInfo *);

    void LoadArmy(const SaveArmyInfo *);

    void AddExp(int exp);

    void AddStrength(int hp);

    void Breakthrough();

    int GetMaxStrength();

    int GetNumDices();

    int GetNumDicesIfLostStrength(int damage);

    bool IsNavy();

    bool LostStrength(int damage);

    void Poisoning();

    void ResetMaxStrength(bool KeepHpValue);

    void SetMorale(int morale);

    void TurnBegin();

    void TurnEnd();

    void Upgrade();

    bool HasCard(Card CardID) {
        return ((this->Cards >> CardID) & 1) != 0;
    }

#endif
};

__BEGIN_DECLS
void _ZN5CArmyC1Ev(struct CArmy *self);

void _ZN5CArmyD1Ev(struct CArmy *self);

void _ZN5CArmy4InitEP7ArmyDefP8CCountry(struct CArmy *self, struct ArmyDef *, struct CCountry *);

void _ZN5CArmy8SaveArmyEP12SaveArmyInfo(struct CArmy *self, struct SaveArmyInfo *);

void _ZN5CArmy8LoadArmyEPK12SaveArmyInfo(struct CArmy *self, const struct SaveArmyInfo *);

void _ZN5CArmy6AddExpEi(struct CArmy *self, int exp);

void _ZN5CArmy11AddStrengthEi(struct CArmy *self, int hp);

void _ZN5CArmy12BreakthroughEv(struct CArmy *self);

int _ZN5CArmy14GetMaxStrengthEv(struct CArmy *self);

int _ZN5CArmy11GetNumDicesEv(struct CArmy *self);

int _ZN5CArmy25GetNumDicesIfLostStrengthEi(struct CArmy *self, int damage);

bool _ZN5CArmy6IsNavyEv(struct CArmy *self);

bool _ZN5CArmy12LostStrengthEi(struct CArmy *self, int damage);

void _ZN5CArmy9PoisoningEv(struct CArmy *self);

void _ZN5CArmy16ResetMaxStrengthEb(struct CArmy *self, bool KeepHpValue);

void _ZN5CArmy9SetMoraleEi(struct CArmy *self, int morale);

void _ZN5CArmy9TurnBeginEv(struct CArmy *self);

void _ZN5CArmy7TurnEndEv(struct CArmy *self);

void _ZN5CArmy7UpgradeEv(struct CArmy *self);

__END_DECLS

struct AreaInfo;
struct SaveAreaInfo;

struct CArea {
    int ID;
    int AreaType;
    int Tax;
    float ArmyPos[2];
    float ConstructionPos[2];
    float InstalltionPos[2];
    bool Enable;
    bool Sea;
    int ConstructionType;
    int ConstructionLevel;
    int InstalltionType;
    struct CCountry *Country;
    struct CArmy *Army[4];
    int ArmyCount;
    struct CArmy *ArmyDrafting;
    struct CArmy *ArmyMovingIn;
    struct CArmy *ArmyMovingToFront;
    float DraftingArmyOffset;
    float MovingInArmyOffset[2];
    float MovingInArmySpeed[2];
    float MoveArmyToFrontAngle;
    bool Selected;
    bool MovingInArmyOccupy;
    bool MovingInArmyComplain;
    char *ComplainCommanderName;
    int TargetType;
    float ArrowEndOffset[2];
    float ArrowEndOffsetMinus[2];
    float ArrowStartOffset[2];
    float ArrowStartOffsetMinus[2];
#ifdef __cplusplus

    void Init(int ID, const AreaInfo &);

    void SaveAera(SaveAreaInfo *);

    void LoadArea(const SaveAreaInfo *);

    void AddArmy(CArmy *, bool bottom);

    void AddArmyCard(int ArmyIndex, int CardID);

    void AddArmyStrength(int ArmyIndex, int Hp);

    void AllArmyPoisoning();

    bool CanConstruct(int ConstructionType);

    bool CheckEncirclement();

    void ClearAllArmy();

    void Construct(int ConstructionType);

    void DelArmyCard(int ArmyIndex, int CardID);

    void DestroyConstruction();

    struct CArmy *DraftArmy(int ArmyType);

    void Encirclement();

    CArmy *GetArmy(int ArmyIndex);

    int GetArmyIdx(CArmy *);

    int GetCityLevel();

    int GetIndustry();

    int GetIndustryLevel();

    int GetRealTax();

    bool HasArmyCard(int CardID);

    bool HasArmyCard(int ArmyIndex, int CardID);

    bool IsActive();

    bool IsArmyActive(int ArmyIndex);

    bool LostArmyStrength(int ArmyIndex, int damage);

    void MoveArmyTo(CArea *);

    void MoveArmyToFront(CArmy *, bool instantly);

    void MoveArmyToFront(int ArmyIndex, bool instantly);

    void OccupyArea(CArea *);

    void ReduceConstructionLevel();

    void RemoveArmy(CArmy *);

    void Render();

    void RenderArmy(float, float, int, CArmy *);

    void RenderBuilding();

    void RevertArmyStrength(int ArmyIndex);

    void SetAllArmyMovement(int movement);

    void SetArmyActive(int ArmyIndex, bool active);

    void SetArmyDir(int ArmyIndex, float direction);

    void SetConstruction(int ConstructionType, int ConstructionLevel);

    void SetMoveInArmy(CArea *Origin, CArmy *, bool WillOccupy, bool WillComplain,
                       const char *ComplainCommander);

    void TurnBegin();

    void TurnEnd();

    void Update(float time);

    void UpgradeArmy(int ArmyIndex);

#endif
};

__BEGIN_DECLS
void _ZN5CAreaC1Ev(struct CArea *self);

void _ZN5CAreaD1Ev(struct CArea *self);

void _ZN5CArea4InitEiRK8AreaInfo(struct CArea *self, int ID, const struct AreaInfo *);

void _ZN5CArea8SaveAeraEP12SaveAreaInfo(struct CArea *self, struct SaveAreaInfo *);

void _ZN5CArea8LoadAreaEPK12SaveAreaInfo(struct CArea *self, const struct SaveAreaInfo *);

void _ZN5CArea7AddArmyEP5CArmyb(struct CArea *self, struct CArmy *, bool bottom);

void _ZN5CArea11AddArmyCardEii(struct CArea *self, int ArmyIndex, int CardID);

void _ZN5CArea15AddArmyStrengthEii(struct CArea *self, int ArmyIndex, int Hp);

void _ZN5CArea16AllArmyPoisoningEv(struct CArea *self);

bool _ZN5CArea12CanConstructEi(struct CArea *self, int ConstructionType);

bool _ZN5CArea17CheckEncirclementEv(struct CArea *self);

void _ZN5CArea12ClearAllArmyEv(struct CArea *self);

void _ZN5CArea9ConstructEi(struct CArea *self, int ConstructionType);

void _ZN5CArea11DelArmyCardEii(struct CArea *self, int ArmyIndex, int CardID);

void _ZN5CArea19DestroyConstructionEv(struct CArea *self);

struct CArmy *_ZN5CArea9DraftArmyEi(struct CArea *self, int ArmyType);

void _ZN5CArea12EncirclementEv(struct CArea *self);

struct CArmy *_ZN5CArea7GetArmyEi(struct CArea *self, int ArmyIndex);

int _ZN5CArea10GetArmyIdxEP5CArmy(struct CArea *self, struct CArmy *);

int _ZN5CArea12GetCityLevelEv(struct CArea *self);

int _ZN5CArea11GetIndustryEv(struct CArea *self);

int _ZN5CArea16GetIndustryLevelEv(struct CArea *self);

int _ZN5CArea10GetRealTaxEv(struct CArea *self);

bool _ZN5CArea11HasArmyCardEi(struct CArea *self, int CardID);

bool _ZN5CArea11HasArmyCardEii(struct CArea *self, int ArmyIndex, int CardID);

bool _ZN5CArea8IsActiveEv(struct CArea *self);

bool _ZN5CArea12IsArmyActiveEi(struct CArea *self, int ArmyIndex);

bool _ZN5CArea16LostArmyStrengthEii(struct CArea *self, int ArmyIndex, int damage);

void _ZN5CArea10MoveArmyToEPS_(struct CArea *self, struct CArea *);

void _ZN5CArea15MoveArmyToFrontEP5CArmyb(struct CArea *self, struct CArmy *, bool instantly);

void _ZN5CArea15MoveArmyToFrontEib(struct CArea *self, int ArmyIndex, bool instantly);

void _ZN5CArea10OccupyAreaEPS_(struct CArea *self, struct CArea *);

void _ZN5CArea23ReduceConstructionLevelEv(struct CArea *self);

void _ZN5CArea10RemoveArmyEP5CArmy(struct CArea *self, struct CArmy *);

void _ZN5CArea6RenderEv(struct CArea *self);

void _ZN5CArea10RenderArmyEffiP5CArmy(struct CArea *self, float, float, int, struct CArmy *);

void _ZN5CArea14RenderBuildingEv(struct CArea *self);

void _ZN5CArea18RevertArmyStrengthEi(struct CArea *self, int ArmyIndex);

void _ZN5CArea18SetAllArmyMovementEi(struct CArea *self, int movement);

void _ZN5CArea13SetArmyActiveEib(struct CArea *self, int ArmyIndex, bool active);

void _ZN5CArea10SetArmyDirEif(struct CArea *self, int ArmyIndex, float direction);

void _ZN5CArea15SetConstructionEii(struct CArea *self, int ConstructionType, int ConstructionLevel);

void
_ZN5CArea13SetMoveInArmyEPS_P5CArmybbPKc(struct CArea *self, struct CArea *Origin, struct CArmy *,
                                         bool WillOccupy, bool WillComplain,
                                         const char *ComplainCommander);

void _ZN5CArea9TurnBeginEv(struct CArea *self);

void _ZN5CArea7TurnEndEv(struct CArea *self);

void _ZN5CArea6UpdateEf(struct CArea *self, float time);

void _ZN5CArea11UpgradeArmyEi(struct CArea *self, int ArmyIndex);

__END_DECLS

struct CMedal {
    float Pos[2];
    float Offset_y;
    float Alpha;
    bool AnimationCompleted;
#ifdef __cplusplus

    void Init(float x, float y);

    void Render();

    void Upate(float time);

#endif
};

__BEGIN_DECLS
void _ZN6CMedalC1Ev(struct CMedal *self);

void _ZN6CMedal4InitEff(struct CMedal *self, float x, float y);

void _ZN6CMedal6RenderEv(struct CMedal *self);

void _ZN6CMedal5UpateEf(struct CMedal *self, float time);

__END_DECLS

struct CAreaMark {
    int Size[2];
    short *Mark;
#ifdef __cplusplus

    void Init(int MapID);

    void Release();

    short GetMark(int x, int y);

#endif
};

__BEGIN_DECLS
void _ZN9CAreaMarkC1Ev(struct CAreaMark *self);

void _ZN9CAreaMarkD1Ev(struct CAreaMark *self);

void _ZN9CAreaMark4InitEi(struct CAreaMark *self, int MapID);

void _ZN9CAreaMark7ReleaseEv(struct CAreaMark *self);

short _ZN9CAreaMark7GetMarkEii(struct CAreaMark *self, int x, int y);

__END_DECLS

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
#ifdef __cplusplus

    void Apply();

    void Init(float x, float y, float w, float h);

    bool IsRectInCamera(float x, float y, float w, float h);

    bool IsRectInVisibleRegion(float x, float y, float w, float h);

    bool Move(float x, float y, bool border);

    void MoveTo(float x, float y, bool border);

    void SetAutoFixPos(bool enabled);

    bool SetPos(float x, float y, bool border);

    void SetPosAndScale(float x, float y, float scale);

    void SetSceneRect(float x, float y, float w, float h);

    void Upate(float time);

#endif
};

__BEGIN_DECLS
void _ZN7CCameraC1Ev(struct CCamera *self);

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

__END_DECLS

struct CBackground {
    int MapSize[2];
    int MapTopRightPos[2];
    int MapCount;
    struct ecTexture *BackgroundTexture[112];
    struct ecImage *BackgroundImage[112];
    struct ecTexture *BoxTexture[3];
    struct ecImage *BoxImage[3];
#ifdef __cplusplus

    void
    Init(int MapID, int TotalX, int TotalY, int TotalW, int TotalH, float EnableX, float EnableY,
         float EnableW, float EnableH);

    void Render(CCamera *camera);

    void RenderBox(CCamera *camera, float x, float y, float w, float h);

#endif
};

__BEGIN_DECLS
void _ZN11CBackgroundC1Ev(struct CBackground *self);

void _ZN11CBackgroundD1Ev(struct CBackground *self);

void _ZN11CBackground4InitEiiiiiffff(struct CBackground *self, int MapID, int TotalX, int TotalY,
                                     int TotalW, int TotalH, float EnableX, float EnableY,
                                     float EnableW, float EnableH);

void _ZN11CBackground6RenderEP7CCamera(struct CBackground *self, struct CCamera *camera);

void
_ZN11CBackground9RenderBoxEP7CCameraffff(struct CBackground *self, struct CCamera *camera, float x,
                                         float y, float w, float h);

__END_DECLS

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
#ifdef __cplusplus

    void Init();

    void Airborne(int TargetAreaID);

    void AircraftCarrierBomb(int StartAreaID, int TargetAreaID);

    void BombArea(int TargetAreaID, int ActionType);

    bool IsBombing();

    void Render();

    void Update(float time);

#endif
};

__BEGIN_DECLS
void _ZN7CBomberC1Ev(struct CBomber *self);

void _ZN7CBomberD1Ev(struct CBomber *self);

void _ZN7CBomber4InitEv(struct CBomber *self);

void _ZN7CBomber8AirborneEi(struct CBomber *self, int TargetAreaID);

void _ZN7CBomber19AircraftCarrierBombEii(struct CBomber *self, int StartAreaID, int TargetAreaID);

void _ZN7CBomber8BombAreaEii(struct CBomber *self, int TargetAreaID, int ActionType);

bool _ZN7CBomber9IsBombingEv(struct CBomber *self);

void _ZN7CBomber6RenderEv(struct CBomber *self);

void _ZN7CBomber6UpdateEf(struct CBomber *self, float time);

__END_DECLS

struct CScene {
    vector(CArea *) AreaList;
    vector(CArea *) RenderAreaList;
    struct CArea *AreaSelected;
    float FlashTimer;
    float FlashSpeed;
    int FightFlashAreaID[2];
    int *AreaData;
    struct ecTextureRes AreaTextureRes;
    struct ecImage **ZoneImage;
    int AreaCount;
    struct CAreaMark AreaMark;
    struct CBackground *CBackground;
    struct CCamera CCamera;
    struct CBomber *CBomber;
    list(CMedal*) MedalList;
    float VerticalArrowTimer;
    float VerticalArrowSpeed;
    float ArrowTimer;
    float ArrowSpeed;
    int *AdjoinRaw;
    int *Adjoin;
    float TopLeftPos[2];
    float Size[2];
    bool NewRoundFlashing;
#ifdef __cplusplus

    void Init(const char *areasenable, int MapID);

    void Release();

    void AdjacentAreasEncirclement(int AreaID);

    void Airborne(int TargetAreaID);

    void AircraftCarrierBomb(int StartAreaID, int TargetAreaID);

    void AllAreasEncirclement();

    void AreaDisableOutofRect(int x, int y, int w, int h);

    void BombArea(int TargetAreaID, int ActionType);

    void CalSceneRect(float &x, float &y, float &w, float &h);

    bool CheckAdjacent(int AreaID_1, int AreaID_2);

    void CheckAdjacentData();

    bool CheckAttackable(int StartAreaID, int TargetAreaID, int ArmyIndex);

    bool CheckMoveable(int StartAreaID, int TargetAreaID, int ArmyIndex);

    void ClearAreas();

    void ClearTargets();

    void CreateArrow(int StartAreaID, int TargetAreaID);

    void CreateRenderAreaList();

    void DelAdjoin(int AreaID_1, int AreaID_2);

    void GainMedal(float x, float y);

    CArea *GetAdjacentArea(int AreaID, int index);

    int GetAdjacentAreaID(int AreaID, int index);

    CArea *GetArea(int AreaID);

    unsigned int GetNumAdjacentAreas(int AreaID);

    unsigned int GetNumAreas();

    CArea *GetSelectedArea();

    float GetTwoAreasDistance(int AreaID_1, int AreaID_2);

    int GetTwoAreasDistanceSquare(int AreaID_1, int AreaID_2);

    void InitAreaImage(int MapID);

    void InitAreas(int MapID, const char *areasenable);

    bool IsAdjoin(int StartAreaID, int TargetAreaID);

    bool IsBombing();

    bool IsMoving();

    bool IsRectInSecen(float x, float y, float w, float h);

    void LoadAdjoin(int MapID);

    void LoadAreaData(int MapID);

    void LoadAreaEnable(const char *areasenable);

    void LoadAreaTax(int MapID);

    void MakeAdjoin(int AreaID_1, int AreaID_2);

    bool Move(int x, int y);

    void MoveCameraBetweenArea(int AreaID_1, int AreaID_2);

    void MoveCameraCenterToArea(int AreaID);

    void MoveCameraToArea(int AreaID);

    bool MoveTo(int x, int y);

    void NewAdjoin();

    void Render();

    void RenderSeaAreas();

    void ResetTarget();

    void SaveAdjoin(int MapID);

    void SaveAreaData(int MapID);

    void SaveAreaTax(int MapID);

    CArea *ScreenToArea(float x, float y);

    int ScreenToAreaID(float x, float y);

    void ScreenToScene(float &x, float &y);

    void SelectArea(CArea *);

    void SelectArea(int AreaID);

    void SetAreaCountry(int AreaID, CCountry *);

    void SetCameraToArea(int AreaID);

    void SetSelAreaTargets(CArea *);

    void UnselectArea();

    void Update(float time);

#endif
};

__BEGIN_DECLS
void _ZN6CSceneC1Ev(struct CScene *self);

void _ZN6CSceneD1Ev(struct CScene *self);

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
