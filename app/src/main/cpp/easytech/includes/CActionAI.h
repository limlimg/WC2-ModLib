#ifndef EASYTECH_CACTIONAI_H
#define EASYTECH_CACTIONAI_H

#include "CArea.h"
#include "cxxvector.h"

__BEGIN_DECLS

struct CActionNode {
    int CardID;
    int StartAreaID;
    int TargetAreaID;
    int ActionType;
    int AlwaysZero;
    int ArmyIndex;
};

struct CActionAI {
    char CurrentCountryName[16];
    struct CCountry *CurrentCountry;
    int TurnBeginMoneyQuarter;
    int TurnBeginIndustryQuarter;
    int AIProgressPercentage;
    char CurrentCountryNameShort[4];
    int TotalAIArmyAreaCount;
    int TurnBeginActiveAreaCount;
    int Unused;
    bool Action;
    int CurrentCountryIndex;
};

struct CActionAI *_ZN9CActionAI8InstanceEv();

void _ZN9CActionAID1Ev(struct CActionAI *self);

void _ZN9CActionAID2Ev(struct CActionAI *self);

void _ZN9CActionAI6InitAIEv(struct CActionAI *self);

void _ZN9CActionAI21analyseCompositePowerE(struct CActionAI *self);

bool _ZN9CActionAI11detectCardsE7CARD_ID(struct CActionAI *self, enum CARD_ID);

void _ZN9CActionAI12getAiPercentEi(struct CActionAI *self, int CountryIndex);

int _ZN9CActionAI8getMaxIdEv(struct CActionAI *self);

bool _ZN9CActionAI8getMedalEiP5CArea(struct CActionAI *self, int damage, struct CArea *TargetArea);

void _ZN9CActionAI13moveAndAttackEv(struct CActionAI *self);

bool _ZN9CActionAI12purChaseCardE7CARD_ID(struct CActionAI *self, enum CARD_ID);

void _ZN9CActionAI18setActionNodeClearEv(struct CActionAI *self);

int _ZN9CActionAI13setArmyActionEP5CArea(struct CActionAI *self, struct CArea *);

struct CActionNode *
_ZN9CActionAI16setCpuDriverbyIdEii(struct CActionAI *self, int CountryIndex, int);

void _ZN9CActionAI15sortArmyToFrontEv(struct CActionAI *self);

extern struct CActionAI *_ZN9CActionAI9_instanceE;

struct NODE {
    int ActionToNextAreaTargetId;
    int TargetValue;
    int ActionToNextAreaArmyIndex;
    bool TargetIsPlayer;
};

#ifndef def_St6vector_4NODE
#define def_St6vector_4NODE
def__ZSt6vector(struct NODE, 4NODE)

#endif
struct CActionAssist {
    int SearchNodeHead;
    int SearchNodeTail;
    bool SearchNodeVisited[1950];
    int SearchNodeQueue[512][2];
    int GetNeighbourID[50];
    int TotalSeaAreaCount;
    int TargetNodeType;
    struct CActionNode ActionNode;
    _ZSt6vector(4NODE) ActionToNextAreaTargetIdList;
    struct NODE TargetNode;
};

struct CActionAssist *_ZN13CActionAssist8InstanceEv();

void _ZN13CActionAssistD1sEv(struct CActionAssist *self);

void _ZN13CActionAssistD2Ev(struct CActionAssist *self);

void _ZN13CActionAssist16actionToNextAreaEiiii(struct CActionAssist *self, int mode, int AreaID,
                                               int ArmyIndex, int);

bool _ZN13CActionAssist15aiCheckMoveableEiiii(struct CActionAssist *self, int StartAreaID,
                                              int TargetAreaID, int ArmyIndex, int ArmyAreaID);

int _ZN13CActionAssist13calcAreaValueEP5CArea(struct CActionAssist *self, struct CArea *);

int
_ZN13CActionAssist13calcDraftTypeEbiP8CCountry(struct CActionAssist *self, bool, int TargetAreaID,
                                               struct CCountry *);

bool _ZN13CActionAssist11getAllianceEiii(struct CActionAssist *self, int AreaID_1, int AreaID_2,
                                         int mode);

int _ZN13CActionAssist11getNeighborEiiic(struct CActionAssist *self, int StartAreaID, int mode, int,
                                         char);

bool _ZN13CActionAssist4isAIEi(struct CActionAssist *self, int AreaID);

bool _ZN13CActionAssist9isBuyCardEP7CardDef(struct CActionAssist *self, struct CardDef *);

bool _ZN13CActionAssist21purChaseAirStrikeCardEv(struct CActionAssist *self);

bool _ZN13CActionAssist17purChaseCardsCardEv(struct CActionAssist *self);

bool _ZN13CActionAssist21purChaseConstructCardEv(struct CActionAssist *self);

bool _ZN13CActionAssist17purChaseDraftCardEb(struct CActionAssist *self, bool navy);

bool _ZN13CActionAssist16purChaseFortCardEv(struct CActionAssist *self);

bool _ZN13CActionAssist19purChaseSpecialCardEv(struct CActionAssist *self);

int _ZN13CActionAssist10searchNodeEii(struct CActionAssist *self, int AreaID, int ArmyIndex);

int _ZN13CActionAssist14searchNodeByIDEii(struct CActionAssist *self, int AreaID, int ArmyIndex);

extern struct CActionAssist *_ZN13CActionAssist9_instanceE;

__END_DECLS

#endif //EASYTECH_CACTIONAI_H
