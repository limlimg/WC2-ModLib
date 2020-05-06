#ifndef EASYTECH_CFIGHT_H
#define EASYTECH_CFIGHT_H

#include "CCountry.h"
#include "cxxvector.h"

__BEGIN_DECLS

#ifndef def_St6vector_i
#define def_St6vector_i
def__ZSt6vector(int, i)

#endif
struct CFight {
    _ZSt6vector(i) StartArmyDices;
    _ZSt6vector(i) TargetArmyDices;
    struct CCountry *AirStrikeCountry;
    int StartArmyNumDicesLost;
    int TargetArmyNumDicesLost;
    int StartArmyDefence;
    int StartArmyExtraAttack;
    int TargetArmyDefence;
    int TargetArmyExtraAttack;
    int x34;
    int x38;
    int StartAreaID;
    int TargetAreaID;
    int StartArmyNumDices;
    int TargetArmyNumDices;
    int StartArmyNumDices1;
    int TargetArmyNumDices1;
    int StartArmyReceiveDamage;
    int TargetArmyReceiveDamage;
    int StartArmyReceiveDamageFirst;
    int TargetArmyReceiveDamageFirst;
    int x64;
    int x68;
    int StartArmyMaxAttack;
    int StartArmyMinAttack;
    int TargetArmyMaxAttack;
    int TargetArmyMinAttack;
    int AirStrikeAttack;
    int AirStrikeType;
    bool CanCounter;
    int SecondAttackIndex;
    bool StartArmySecondAttack;
    bool TargetArmySecondAttack;
    int SecondAttackSideIndex;
    bool x94;
};

void _ZN6CFightC1Ev(struct CFight *self);

void _ZN6CFightC2Ev(struct CFight *self);

void _ZN6CFightD1Ev(struct CFight *self);

void _ZN6CFightD2Ev(struct CFight *self);

void
_ZN6CFight16AirStrikesAttackEP8CCountryii(struct CFight *self, struct CCountry *, int TargetAreaID,
                                          int type);

void _ZN6CFight16AirStrikesAttackEii(struct CFight *self, int StartAreaID, int TargetAreaID);

void _ZN6CFight11ApplyResultEv(struct CFight *self);

void _ZN6CFight11FirstAttackEii(struct CFight *self, int StartAreaID, int TargetAreaID);

int _ZN6CFight17GetAttackerResultEi(struct CFight *self, int index);

int _ZN6CFight17GetDefenderResultEi(struct CFight *self, int index);

void _ZN6CFight12NormalAttackEii(struct CFight *self, int StartAreaID, int TargetAreaID);

void _ZN6CFight12SecondAttackEv(struct CFight *self);

__END_DECLS

#endif //EASYTECH_CFIGHT_H
