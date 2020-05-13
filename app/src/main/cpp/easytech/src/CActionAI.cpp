
#define extends_CActionAI \
CActionAI();\
~CActionAI();

#define extends_CActionAssist \
CActionAssist();\
~CActionAssist();

#include <cstring>
#include "CActionAI.h"

CActionAI *_ZN9CActionAI9_instanceE = NULL;

CActionAI *CActionAI::Instance() {
    if (_ZN9CActionAI9_instanceE == NULL) {
        static CActionAI S_ActionAi;
        _ZN9CActionAI9_instanceE = &S_ActionAi;
    }
    return _ZN9CActionAI9_instanceE;
}

CActionAI::CActionAI() {
    this->setActionNodeClear();
    memset(this->CurrentCountryName, 0, 0x10u);
    this->CurrentCountryIndex = -1;
}

CActionAI::~CActionAI() {
    this->setActionNodeClear();
}

void CActionAI::InitAI() {
    this->TotalAIArmyAreaCount = 0;
    this->TurnBeginActiveAreaCount = 0;
    CActionAssist::Instance()->TotalSeaAreaCount = 0;
    int i;
    for (i = 0; i < g_Scene.GetNumAreas(); i++) {
        CArea *area = g_Scene[i];
        if (area->Enable) {
            if (area->Sea)
                CActionAssist::Instance()->TotalSeaAreaCount += 1;
            CCountry *country = area->Country;
            if (country != NULL && country->AI && area->ArmyCount > 0)
                this->TotalAIArmyAreaCount += 1;
        }
    }
    this->AIProgressPercentage = 1;
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

int CActionAssist::calcAreaValue(CArea *area) {
    if (area == NULL)
        return -1;
    const int TypeAdd[] = {0, 250, 80, 150, 80};
    const int InstalltionAdd[] = {0, 20, 15, 10};
    return _ZN5CArea10GetRealTaxEv(area) * 2 + _ZN5CArea11GetIndustryEv(area) * 3 +
           ((area->AreaType < 5) ? TypeAdd[area->AreaType] : 0) +
           ((area->InstallationType < 4) ? InstalltionAdd[area->InstallationType] : 0);
}
