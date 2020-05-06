
#include <vector>

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
    static CActionAI *Instance();

    CActionAI();

    ~CActionAI();

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

void _ZN9CActionAI18setActionNodeClearEv(struct CActionAI *self);

struct NODE {
    int ActionToNextAreaTargetId;
    int TargetValue;
    int ActionToNextAreaArmyIndex;
    bool TargetIsPlayer;
};

struct CActionAssist {
    static CActionAssist *Instance();

    CActionAssist();

    ~CActionAssist();

    int SearchNodeHead;
    int SearchNodeTail;
    bool SearchNodeVisited[1950];
    int SearchNodeQueue[512][2];
    int GetNeighbourID[50];
    int TotalSeaAreaCount;
    int TargetNodeType;
    struct CActionNode ActionNode;
    std::vector<NODE> ActionToNextAreaTargetIdList;
    struct NODE TargetNode;
};

extern struct CActionAssist *_ZN13CActionAssist9_instanceE;

#include <cstring>
#include "CScene.h"

CActionAI *_ZN9CActionAI9_instanceE = NULL;

CActionAI *CActionAI::Instance() {
    if (_ZN9CActionAI9_instanceE == NULL) {
        static CActionAI S_ActionAi;
        _ZN9CActionAI9_instanceE = &S_ActionAi;
    }
    return _ZN9CActionAI9_instanceE;
}

CActionAI::CActionAI() {
    _ZN9CActionAI18setActionNodeClearEv(this);
    memset(this->CurrentCountryName, 0, 0x10u);
    this->CurrentCountryIndex = -1;
}

CActionAI::~CActionAI() {
    _ZN9CActionAI18setActionNodeClearEv(this);
}

void _ZN9CActionAI6InitAIEv(struct CActionAI *self) {
    self->TotalAIArmyAreaCount = 0;
    self->TurnBeginActiveAreaCount = 0;
    CActionAssist::Instance()->TotalSeaAreaCount = 0;
    int i;
    for (i = 0; i < _ZN6CScene11GetNumAreasEv(&g_Scene); i++) {
        struct CArea *area = _ZN6CScene7GetAreaEi(&g_Scene, i);
        if (area->Enable) {
            if (area->Sea)
                CActionAssist::Instance()->TotalSeaAreaCount += 1;
            struct CCountry *country = area->Country;
            if (country != NULL && country->AI && area->ArmyCount > 0)
                self->TotalAIArmyAreaCount += 1;
        }
    }
    self->AIProgressPercentage = 1;
}

CActionAssist *_ZN13CActionAssist9_instanceE = NULL;

CActionAssist *CActionAssist::Instance() {
    if (_ZN13CActionAssist9_instanceE == NULL) {
        static CActionAssist S_ActionAssist;
        _ZN13CActionAssist9_instanceE = &S_ActionAssist;
    }
    return _ZN13CActionAssist9_instanceE;
}

CActionAssist::CActionAssist() {}

CActionAssist::~CActionAssist() {}

__END_DECLS

/*
safe_free_pointer<int8_t> HIDDEN g_SearchNodeTag;
safe_free_pointer<int> HIDDEN g_SearchNodeQueue;

int OVERRIDE CActionAssist::searchNodeByID(int AreaID, int ArmyIndex)
{
    unsigned int AreaCount = g_Scene.GetNumAreas();
    g_SearchNodeTag = new int8_t[AreaCount];
    memset((void*)g_SearchNodeTag, -1, AreaCount);
    g_SearchNodeQueue = new int[AreaCount];
    this->SearchNodeHead = -1;
    this->SearchNodeTail = 0;
    g_SearchNodeTag[AreaID] = 0;
    g_SearchNodeQueue[0] = AreaID;
    while(this->SearchNodeHead < this->SearchNodeTail)
    {
        if(this->searchNode(AreaID, ArmyIndex) != -1)
            return g_Scene.GetAdjacentArea(AreaID, g_SearchNodeTag[this->SearchNodeTail])->ID;
    }
    return -1;
}

int OVERRIDE CActionAssist::searchNode(int AreaID, int ArmyIndex)
{
    int CurrentNodeAreaID = g_SearchNodeQueue[this->SearchNodeTail];
    int AdAreaCount = g_Scene.GetNumAdjacentAreas(CurrentNodeAreaID);
    int8_t i;
    for(i = 0; i < AdAreaCount; i++)
    {
        CArea *SearchArea = g_Scene.GetAdjacentArea(CurrentNodeAreaID, i);
        if(g_SearchNodeTag[SearchArea->ID] != -1)
            continue;
        if(!this->aiCheckMoveable(CurrentNodeAreaID, SearchArea->ID, ArmyIndex, AreaID))
        //|| !this->aiCheckAttackable(CurrentNodeAreaID, SearchArea->ID, ArmyIndex, AreaID))
            continue;
        if(!SearchArea->Sea
        && this->getAlliance(AreaID, SearchArea->ID, 256)
        && !this->getAlliance(AreaID, SearchArea->ID, 1024))
            continue;
        if(CurrentNodeAreaID == AreaID)
            g_SearchNodeTag[SearchArea->ID] = i;
        else
            g_SearchNodeTag[SearchArea->ID] = g_SearchNodeTag[CurrentNodeAreaID];
        this->SearchNodeTail += 1;
        if(this->getAlliance(AreaID, SearchArea->ID, 768))
            continue;
        if(g_Scene.GetArea(AreaID)->GetArmy(ArmyIndex)->IsNavy())
        {
            if(!SearchArea->Sea)
            {
                if(SearchArea->ArmyCount > 0)
                    this->TargetNodeType = 3;
                else
                    this->TargetNodeType = 1;
                return SearchArea->ID;
            }
            if(SearchArea->AreaType == 2)
            {
                this->TargetNodeType = 2;
                return SearchArea->ID;
            }
        }
        if(!SearchArea->Sea)
        {
            if(this->calcAreaValue(SearchArea) > 80)
                this->TargetNodeType = 3;
            else
                this->TargetNodeType = (SearchArea->ArmyCount > 0)?2:1;
            return SearchArea->ID;
        }
    }
    return -1;
}
*/
