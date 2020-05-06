#ifndef EASYTECH_CCOUNTRY_H
#define EASYTECH_CCOUNTRY_H

#include "CObjectDef.h"
#include "cxxlist.h"

__BEGIN_DECLS

enum WARMEDAL_ID {
    InfantryMedal, AirForceMedal, ArtilleryMedal, ArmourMedal, NavyMedal, CommerceMedal
};

struct CountryAction {
    int ActionType;
    int CardID;
    int StartAreaID;
    int TargetAreaID;
    int ArmyIndex;
};

struct SaveCountryInfo;
#ifndef def_St4list_i
#define def_St4list_i
def__ZSt4list(int, i)
#endif
struct CCountry {
    int Alliance;
    int DefeatType;
    _ZSt4list(i) AreaIDList;
    _ZSt4list(i) CapitalIDList;
    int Money;
    int Industry;
    float TaxRate;
    char ID[16];
    char Name[16];
    unsigned char R;
    unsigned char B;
    unsigned char G;
    unsigned char A;
    bool AI;
    bool Defeated;
    struct CountryAction CAction;
    float ActionTimer;
    float ActionDelayTime;
    bool ActionWaitCamera;
    int Tech;
    int TechTurn;
    int CardRound[28];
    _ZSt4list(i) AOECardTargetIDList;
    _ZNSt4list8iteratorE(i) *AOECardCurTargetID;
    int DestroyCount[10];
    struct CommanderDef *PvCommanderDef;
    int CommanderTurn;
    bool CommanderAlive;
    int WarMedal[6];
    bool BorrowedLoan;
    void *PvPlayer;
};

void _ZN8CCountryC1Ev(struct CCountry *self);

void _ZN8CCountryC2Ev(struct CCountry *self);

void _ZN8CCountryD1Ev(struct CCountry *self);

void _ZN8CCountryD2Ev(struct CCountry *self);

void _ZN8CCountry4InitEPKcS1_(struct CCountry *self, const char *ID, const char *Name);

void _ZN8CCountry11SaveCountryEP15SaveCountryInfo(struct CCountry *self, struct SaveCountryInfo *);

void _ZN8CCountry11LoadCountryEPK15SaveCountryInfo(struct CCountry *self,
                                                   const struct SaveCountryInfo *);

void _ZN8CCountry6ActionERK13CountryAction(struct CCountry *self, const struct CountryAction *);

void _ZN8CCountry7AddAreaEi(struct CCountry *self, int AreaID);

void _ZN8CCountry10AddDestroyEi(struct CCountry *self, int ArmyType);

float _ZN8CCountry15AirstrikeRadiusEv(struct CCountry *self);

void _ZN8CCountry14BeConquestedByEPS_(struct CCountry *self, struct CCountry *);

bool _ZN8CCountry10CanBuyCardEP7CardDef(struct CCountry *self, struct CardDef *);

bool _ZN8CCountry15CanUseCommanderEv(struct CCountry *self);

bool _ZN8CCountry19CheckCardTargetAreaEP7CardDefi(struct CCountry *self, struct CardDef *, int id);

bool
_ZN8CCountry19CheckCardTargetArmyEP7CardDefii(struct CCountry *self, struct CardDef *, int AreaID,
                                              int ArmyIndex);

void _ZN8CCountry16CollectIndustrysEv(struct CCountry *self);

void _ZN8CCountry12CollectTaxesEv(struct CCountry *self);

void _ZN8CCountry12CommanderDieEv(struct CCountry *self);

void _ZN8CCountry8DoActionEv(struct CCountry *self);

int _ZN8CCountry18FindAdjacentAreaIDEib(struct CCountry *self, int AreaID, bool HasArmy);

int _ZN8CCountry22FindAdjacentLandAreaIDEib(struct CCountry *self, int AreaID, bool HasArmy);

bool _ZN8CCountry8FindAreaEi(struct CCountry *self, int AreaID);

void _ZN8CCountry12FinishActionEv(struct CCountry *self);

int _ZN8CCountry15GetCardIndustryEP7CardDef(struct CCountry *self, struct CardDef *);

int _ZN8CCountry12GetCardPriceEP7CardDef(struct CCountry *self, struct CardDef *);

int _ZN8CCountry13GetCardRoundsE7CARD_ID(struct CCountry *self, enum CARD_ID);

int _ZN8CCountry17GetCommanderLevelEv(struct CCountry *self);

const char *_ZN8CCountry16GetCommanderNameEv(struct CCountry *self);

int _ZN8CCountry16GetCurCardTargetEv(struct CCountry *self);

int _ZN8CCountry15GetFirstCapitalEv(struct CCountry *self);

int _ZN8CCountry19GetHighestValueAreaEv(struct CCountry *self);

int _ZN8CCountry12GetIndustrysEv(struct CCountry *self);

float _ZN8CCountry18GetMinDstToAirportEi(struct CCountry *self, int AreaID);

int _ZN8CCountry13GetNumAirportEv(struct CCountry *self);

int _ZN8CCountry8GetTaxesEv(struct CCountry *self);

int _ZN8CCountry16GetWarMedalLevelE11WARMEDAL_ID(struct CCountry *self, enum WARMEDAL_ID);

bool _ZN8CCountry14IsActionFinishEv(struct CCountry *self);

bool _ZN8CCountry12IsCardUnlockEP7CardDef(struct CCountry *self, struct CardDef *);

bool _ZN8CCountry12IsConquestedEv(struct CCountry *self);

bool _ZN8CCountry16IsEnoughIndustryEP7CardDef(struct CCountry *self, struct CardDef *);

bool _ZN8CCountry13IsEnoughMoneyEP7CardDef(struct CCountry *self, struct CardDef *);

bool _ZN8CCountry13IsLocalPlayerEv(struct CCountry *self);

void _ZN8CCountry14NextCardTargetEv(struct CCountry *self);

void _ZN8CCountry10RemoveAreaEi(struct CCountry *self, int AreaID);

void _ZN8CCountry14SetCardTargetsEP7CardDef(struct CCountry *self, struct CardDef *);

void _ZN8CCountry12SetCommanderEPKc(struct CCountry *self, const char *name);

void
_ZN8CCountry16SetWarMedalLevelE11WARMEDAL_IDi(struct CCountry *self, enum WARMEDAL_ID, int level);

void _ZN8CCountry9TurnBeginEv(struct CCountry *self);

void _ZN8CCountry7TurnEndEv(struct CCountry *self);

void _ZN8CCountry6UpdateEf(struct CCountry *self, float time);

void _ZN8CCountry7UseCardEP7CardDefii(struct CCountry *self, struct CardDef *, int TargetAreaID,
                                      int ArmyIndex);

__END_DECLS

#endif //EASYTECH_CCOUNTRY_H
