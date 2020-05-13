//fix original game bugs
//Fix: AI rocket melee attack

#include "_CActionAI.h"
#include "CActionAI.h"

bool CActionAssist::aiCheckAttackable(int StartAreaID, int TargetAreaID, int ArmyIndex,
                                           int ArmyAreaID) {
    if (this->getAlliance(ArmyAreaID, TargetAreaID, Ally))
        return false;
    CArea *ArmyArea = g_Scene[ArmyAreaID];
    if (ArmyArea->ArmyCount <= ArmyIndex)
        return false;
    CArea *TargetArea = g_Scene[TargetAreaID];
    if (TargetArea->ArmyCount <= 0)
        return false;
    CArmy *Army = ArmyArea->GetArmy(ArmyIndex);
    //Fix AI rocket melee attack
    if (Army->BasicAbilities->ID == ArmyDef::Rocket &&
        g_Scene.CheckAdjacent(ArmyAreaID, TargetAreaID))
        return false;
    return Army->Movement > 0;
}



