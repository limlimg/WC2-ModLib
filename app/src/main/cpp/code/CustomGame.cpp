//Customize game rule

#include "CScene.h"
#include "CActionAI.h"
#include "modObject.h"
#include "CustomizableData.h"

bool CScene::CheckMoveable(int StartAreaID, int TargetAreaID, int ArmyIndex) {
    if (!this->CheckAdjacent(StartAreaID, TargetAreaID))
        return false;
    return CActionAssist::Instance()->aiCheckMoveable(StartAreaID, TargetAreaID, ArmyIndex,
                                                      StartAreaID);
}

bool mod::CArea::CanContainArmy(CArmy *army) {
    if (this->ArmyCount >= 4)
        return false;
    int i, TroopCount = 0, NavyCount = 0;
    for (i = 0; i < this->ArmyCount; i++)
        if (this->GetArmy(i)->IsNavy())
            NavyCount++;
        else
            TroopCount++;
    if (army->IsNavy())
        NavyCount++;
    else
        TroopCount++;
    if (NavyCount > AreaNavyLimit)
        return false;
    if (NavyCount == AreaNavyLimit && TroopCount > 0)
        return false;
    if (TroopCount > AreaTroopLimit)
        return false;
    if (TroopCount == AreaTroopLimit && NavyCount > 0)
        return false;
    if (!this->Sea)
        return !army->IsNavy();
    else
        return army->IsNavy() || army->HasCard(CArmy::Carrier);
}

bool
CActionAssist::aiCheckMoveable(int StartAreaID, int TargetAreaID, int ArmyIndex, int ArmyAreaID) {
    CArea *ArmyArea = g_Scene.GetArea(ArmyAreaID);
    CArea *TargetArea = g_Scene.GetArea(TargetAreaID);
    if (ArmyArea->Country != TargetArea->Country && TargetArea->ArmyCount != 0)
        return false;
    if (ArmyArea->ArmyCount <= ArmyIndex)
        return false;
    CArmy *Army = ArmyArea->GetArmy(ArmyIndex);
    if (Army->Movement <= 0)
        return false;
    return static_cast<mod::CArea *>(TargetArea)->CanContainArmy(Army);
}

bool CScene::CheckAttackable(int StartAreaID, int TargetAreaID, int ArmyIndex) {
    if (!static_cast<mod::CActionAssist *>(CActionAssist::Instance())->aiCheckAttackable(
            StartAreaID, TargetAreaID, ArmyIndex, StartAreaID))
        return false;
    CArea *StartArea = g_Scene.GetArea(StartAreaID);
    ArmyDef::ArmyType ArmyType = StartArea->GetArmy(ArmyIndex)->BasicAbilities->ID;
    if (ArmyType == ArmyDef::Rocket) {
        int i;
        for (i = 0; i < this->GetNumAdjacentAreas(StartAreaID); i++)
            if (this->CheckAdjacent(this->GetAdjacentAreaID(StartAreaID, i), TargetAreaID))
                return true;
        return false;
    } else if (ArmyType == ArmyDef::AircraftCarrier) {
        float d = this->GetTwoAreasDistance(StartAreaID, TargetAreaID);
        return (d > 0.0 && d < StartArea->Country->AirstrikeRadius());
    } else
        return this->CheckAdjacent(StartAreaID, TargetAreaID);
}
