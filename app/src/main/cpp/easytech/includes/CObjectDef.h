#ifndef EASYTECH_COBJECTDEF_H
#define EASYTECH_COBJECTDEF_H

#include "cxx.h"
#include "cxxmap.h"
#include "cxxstring.h"

enum CARD_ID {
    NoCard,
    InfantryCard = 0,
    ArmourCard,
    ArtilleryCard,
    RocketCard,
    TankCard,
    HeavyTankCard,
    DestroyerCard,
    CruiserCard,
    BattleShipCard,
    AircraftCarrierCard,
    AirStrikeCard,
    BomberCard,
    AirborneForceCard,
    NuclearBombCard,
    CityCard,
    IndustryCard,
    AirportCard,
    LandFortCard,
    EntrenchmentCard,
    AntiaircraftCard,
    RadarCard,
    ResearchCard,
    CarrierCard,
    AssaultArtCard,
    DefendArtCard,
    CommanderCard,
    SupplyLineCard,
    AceForcesCard
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
    enum ArmyType {
        Infantry,
        Panzer,
        Artillery,
        Rocket,
        Tank,
        HeavyTank,
        Destroyer,
        Cruiser,
        Battleship,
        AircraftCarrier
    } ID;
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

struct CObjectDef {
    struct ArmyDefList {
        struct ArmyDef *Def[15];
    };
    map(const string, ArmyDefList*) mapArmyDefList;
    struct CardDef CardDef28[28];
    map(const string, UnitMotions*) mapUnitMotions;
    map(const string, UnitPositions*) mapUnitPos;
    map(const string, CommanderDef*) mapCommanderDef;
    map(const string, GeneralPhoto*) mapGeneralPhotos;
    map(const string, BattleDef*) mapBattleDef;
    map(const string, ConquestDef*) mapConquestList;
#ifdef __cplusplus

    static CObjectDef *Instance();

    void Init();

    void Release();

    void Destroy();

    ArmyDef *GetArmyDef(int ArmyType, const char *CountryName);

    BattleDef *GetBattleDef(const char *key);

    CardDef *GetCardDef(CARD_ID);

    int GetCardTargetType(CardDef *);

    CommanderDef *GetCommanderDef(const char *name);

    ConquestDef *GetConquestDef(const char *name);

    GeneralPhoto *GetGeneralPhoto(const char *name);

    UnitMotions *GetUnitMotions(const char *, const char *);

    UnitPositions *GetUnitPositions(const char *);

    void LoadArmyDef();

    void LoadBattleList();

    void LoadCardDef();

    void LoadCommanderDef();

    void LoadConquestList();

    void LoadGeneralPhotos();

    void LoadUnitMotions();

    void LoadUnitPositons();

    void ReleaseArmyDef();

    void ReleaseBattleList();

    void ReleaseCommanderDef();

    void ReleaseConquestList();

    void ReleaseGeneralPhotos();

    void ReleaseUnitMotions();

    void ReleaseUnitPositions();

#ifdef extends_CObjectDef
    extends_CObjectDef
#endif
#endif
};

__BEGIN_DECLS
struct CObjectDef *_ZN10CObjectDef8InstanceEv();

void _ZN10CObjectDefC1Ev(struct CObjectDef *self);

void _ZN10CObjectDefD1Ev(struct CObjectDef *self);

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
