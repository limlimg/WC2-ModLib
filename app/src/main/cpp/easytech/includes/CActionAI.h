#ifndef EASYTECH_CACTIONAI_H
#define EASYTECH_CACTIONAI_H

#include "CScene.h"
#include "cxxvector.h"

struct CActionNode {
    enum CARD_ID CardID;
    int StartAreaID;
    int TargetAreaID;
    enum ActionNodeType {
        UseCardNode = 0x10010,
        ArmyMoveNode = 0x10020,
        ArmyAttackNode = 0x10030,
        ArmyMoveFrontNode = 0x10050
    } ActionType;
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
    bool x2C;
    bool x2D;
    bool x2E;
    bool x2F;
    bool Action;
    int CurrentCountryIndex;
#ifdef __cplusplus

    static CActionAI *Instance();

    void InitAI();

    void analyseCompositePower();

    bool detectCards(CARD_ID);

    void getAiPercent(int CountryIndex);

    int getMaxId();

    bool getMedal(int damage, CArea *TargetArea);

    void moveAndAttack();

    bool purChaseCard(CARD_ID);

    void setActionNodeClear();

    int setArmyAction(CArea *);

    struct CActionNode *setCpuDriverbyId(int CountryIndex, int);

    void sortArmyToFront();

#ifdef extends_CActionAI
    extends_CActionAI

#endif
#endif
};

__BEGIN_DECLS
struct CActionAI *_ZN9CActionAI8InstanceEv();

void _ZN9CActionAID1Ev(struct CActionAI *self);

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
__END_DECLS

struct NODE {
    int ActionToNextAreaTargetId;
    int TargetValue;
    int ActionToNextAreaArmyIndex;
    bool TargetIsPlayer;
};

struct CActionAssist {
    enum Alliance {
        Ally = 256, NotAlly = 512, Enemy = 768, Self = 1024
    };
    int SearchNodeHead;
    int SearchNodeTail;
    bool SearchNodeVisited[1950];
    int SearchNodeQueue[512][2];
    int GetNeighbourID[50];
    int TotalSeaAreaCount;
    int TargetNodeType;
    struct CActionNode ActionNode;
    vector(NODE) ActionToNextAreaTargetIdList;
    struct NODE TargetNode;
#ifdef __cplusplus

    static CActionAssist *Instance();

    void actionToNextArea(int mode, int AreaID, int ArmyIndex, int);

    bool aiCheckMoveable(int StartAreaID, int TargetAreaID, int ArmyIndex, int ArmyAreaID);

    int calcAreaValue(CArea *);

    int calcDraftType(bool, int TargetAreaID, CCountry *);

    bool getAlliance(int AreaID_1, int AreaID_2, int mode);

    int getNeighbor(int StartAreaID, int mode, int, char);

    bool isAI(int AreaID);

    bool isBuyCard(CardDef *);

    bool purChaseAirStrikeCard();

    bool purChaseCardsCard();

    bool purChaseConstructCard();

    bool purChaseDraftCard(bool navy);

    bool purChaseFortCard();

    bool purChaseSpecialCard();

    int searchNode(int AreaID, int ArmyIndex);

    int searchNodeByID(int AreaID, int ArmyIndex);

#ifdef extends_CActionAssist
    extends_CActionAssist

#endif
#endif
};

__BEGIN_DECLS
struct CActionAssist *_ZN13CActionAssist8InstanceEv();

void _ZN13CActionAssistD1sEv(struct CActionAssist *self);

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
