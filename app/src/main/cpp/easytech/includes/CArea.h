#ifndef EASYTECH_CAREA_H
#define EASYTECH_CAREA_H

#include "CArmy.h"

__BEGIN_DECLS

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
};

void _ZN5CAreaC1Ev(struct CArea *self);

void _ZN5CAreaC2Ev(struct CArea *self);

void _ZN5CAreaD1Ev(struct CArea *self);

void _ZN5CAreaD2Ev(struct CArea *self);

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

#endif //EASYTECH_CAREA_H
