#ifndef EASYTECH_CARMY_H
#define EASYTECH_CARMY_H

#include "CCountry.h"

#define ArmyType_Infantry 0
#define ArmyType_Panzer 1
#define ArmyType_Artillery 2
#define ArmyType_Rocket 3
#define ArmyType_Tank 4
#define ArmyType_HeavyTank 5
#define ArmyType_Destroyer 6
#define ArmyType_Cruiser 7
#define ArmyType_Battleship 8
#define ArmyType_AircraftCarrier 9

__BEGIN_DECLS

struct SaveArmyInfo;
struct CArmy {
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
};

void _ZN5CArmyC1Ev(struct CArmy *self);

void _ZN5CArmyC2Ev(struct CArmy *self);

void _ZN5CArmyD1Ev(struct CArmy *self);

void _ZN5CArmyD2Ev(struct CArmy *self);

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

#endif //EASYTECH_CARMY_H
