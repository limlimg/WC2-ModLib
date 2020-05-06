#ifndef EASYTECH_COBJECTDEF_H
#define EASYTECH_COBJECTDEF_H

#include "DECLS.h"
#include "cxxmap.h"
#include "cxxstring.h"

__BEGIN_DECLS

enum CARD_ID {
    Infantry,
    Armour,
    Artillery,
    Rocket,
    Tank,
    Heavy_Tank,
    Destroyer,
    Cruiser,
    BattleShip,
    Aircraft_Carrier,
    Airstrike,
    Bomber,
    Airborne_Force,
    Nuclear_Bomb,
    City,
    Industry,
    Airport,
    Land_Fort,
    Entrenchment,
    Antiaircraft,
    Radar,
    Research,
    Carrier,
    Assault_Art,
    Defend_Art,
    Commander,
    Supply_Line,
    Ace_Forces
};

//Game data definition
struct CardDef {
    string *Name;
    string *Image;
    string *Intro;
    enum CARD_ID ID;
    int Type;
    int Price;
    int Industry;
    int Round;
    int Tech;
};

struct ArmyDef {
    string Name;
    int ID;
    int Hp;
    int Movement;
    int MinAttack;
    int MaxAttack;
};

struct CommanderDef {
    string name;
    string country;
    int rank;
    int medal[6];
};

struct UnitMotions;
struct UnitPositions;
struct GeneralPhoto;
struct BattleDef;
struct ConquestDef;

struct N10CObjectDef11ArmyDefListE {
    struct ArmyDef *PArmyDef15[15];
};

#ifndef def__ZSt3map_KSs_PN10CObjectDef11ArmyDefListE
#define def__ZSt3map_KSs_PN10CObjectDef11ArmyDefListE
def__ZSt3map(string const, KSs, struct N10CObjectDef11ArmyDefListE*, PN10CObjectDef11ArmyDefListE)

#endif
#ifndef def__ZSt3map_KSs_P10UnitMotions
#define def__ZSt3map_KSs_P10UnitMotions
def__ZSt3map(string const, KSs, struct UnitMotions*, P10UnitMotions)

#endif
#ifndef def__ZSt3map_KSs_P13UnitPositions
#define def__ZSt3map_KSs_P13UnitPositions
def__ZSt3map(string const, KSs, struct UnitPositions*, P13UnitPositions)

#endif
#ifndef def__ZSt3map_KSs_P12CommanderDef
#define def__ZSt3map_KSs_P12CommanderDef
def__ZSt3map(string const, KSs, struct CommanderDef*, P12CommanderDef)

#endif
#ifndef def__ZSt3map_KSs_P12GeneralPhoto
#define def__ZSt3map_KSs_P12GeneralPhoto
def__ZSt3map(string const, KSs, struct GeneralPhoto*, P12GeneralPhoto)

#endif
#ifndef def__ZSt3map_KSs_P9BattleDef
#define def__ZSt3map_KSs_P9BattleDef
def__ZSt3map(string const, KSs, struct BattleDef*, P9BattleDef)

#endif
#ifndef def__ZSt3map_KSs_P11ConquestDef
#define def__ZSt3map_KSs_P11ConquestDef
def__ZSt3map(string const, KSs, struct ConquestDef*, P11ConquestDef)

#endif
struct CObjectDef {
    _ZSt3map(KSs, PN10CObjectDef11ArmyDefListE) mapArmyDefList;
    struct CardDef CardDef28[28];
    _ZSt3map(KSs, P10UnitMotions) mapUnitMotions;
    _ZSt3map(KSs, P13UnitPositions) mapUnitPos;
    _ZSt3map(KSs, P12CommanderDef) mapCommanderDef;
    _ZSt3map(KSs, P12GeneralPhoto) mapGeneralPhotos;
    _ZSt3map(KSs, P9BattleDef) mapBattleDef;
    _ZSt3map(KSs, P11ConquestDef) mapConquestList;
};

struct CObjectDef *_ZN10CObjectDef8InstanceEv();

void _ZN10CObjectDefC1Ev(struct CObjectDef *self);

void _ZN10CObjectDefC2Ev(struct CObjectDef *self);

void _ZN10CObjectDefD1Ev(struct CObjectDef *self);

void _ZN10CObjectDefD2Ev(struct CObjectDef *self);

void _ZN10CObjectDef4InitEv(struct CObjectDef *self);

void _ZN10CObjectDef7ReleaseEv(struct CObjectDef *self);

void _ZN10CObjectDef7DestroyEv(struct CObjectDef *self);

struct ArmyDef
_ZN10CObjectDef10GetArmyDefEiPKc(struct CObjectDef *self, int ArmyType, const char *CountryName);

struct BattleDef *_ZN10CObjectDef12GetBattleDefEPKc(struct CObjectDef *self, const char *key);

struct CardDef *_ZN10CObjectDef10GetCardDefE7CARD_ID(struct CObjectDef *self, enum CARD_ID);

int _ZN10CObjectDef17GetCardTargetTypeEP7CardDef(struct CObjectDef *self, struct CardDef *);

struct CommanderDef *
_ZN10CObjectDef15GetCommanderDefEPKc(struct CObjectDef *self, const char *name);

struct ConquestDef *_ZN10CObjectDef14GetConquestDefEPKc(struct CObjectDef *self, const char *name);

struct GeneralPhoto *
_ZN10CObjectDef15GetGeneralPhotoEPKc(struct CObjectDef *self, const char *name);

struct UnitMotions *
_ZN10CObjectDef14GetUnitMotionsEPKcS1_(struct CObjectDef *self, const char *, const char *);

struct UnitPositions *_ZN10CObjectDef16GetUnitPositionsEPKc(struct CObjectDef *self, const char *);

void _ZN10CObjectDef11LoadArmyDefEv(struct CObjectDef *self);

void _ZN10CObjectDef14LoadBattleListEv(struct CObjectDef *self);

void _ZN10CObjectDef11LoadCardDefEv(struct CObjectDef *self);

void _ZN10CObjectDef16LoadCommanderDefEv(struct CObjectDef *self);

void _ZN10CObjectDef16LoadConquestListEv(struct CObjectDef *self);

void _ZN10CObjectDef17LoadGeneralPhotosEv(struct CObjectDef *self);

void _ZN10CObjectDef15LoadUnitMotionsEv(struct CObjectDef *self);

void _ZN10CObjectDef16LoadUnitPositonsEv(struct CObjectDef *self);

void _ZN10CObjectDef14ReleaseArmyDefEv(struct CObjectDef *self);

void _ZN10CObjectDef17ReleaseBattleListEv(struct CObjectDef *self);

void _ZN10CObjectDef19ReleaseCommanderDefEv(struct CObjectDef *self);

void _ZN10CObjectDef19ReleaseConquestListEv(struct CObjectDef *self);

void _ZN10CObjectDef20ReleaseGeneralPhotosEv(struct CObjectDef *self);

void _ZN10CObjectDef18ReleaseUnitMotionsEv(struct CObjectDef *self);

void _ZN10CObjectDef20ReleaseUnitPositionsEv(struct CObjectDef *self);

extern struct CObjectDef *_ZN10CObjectDef10m_InstanceE;

__END_DECLS

#endif //EASYTECH_COBJECTDEF_H
