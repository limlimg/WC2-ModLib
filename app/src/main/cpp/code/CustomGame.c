//Customize game rule

#include "CScene.h"
#include "CActionAI.h"

bool _ZN6CScene13CheckMoveableEiii(struct CScene *self, int StartAreaID, int TargetAreaID,
                                   int ArmyIndex) {
    if (!_ZN6CScene13CheckAdjacentEii(self, StartAreaID, TargetAreaID))
        return false;
    return _ZN13CActionAssist15aiCheckMoveableEiiii(_ZN13CActionAssist8InstanceEv(), StartAreaID,
                                                    TargetAreaID, ArmyIndex, StartAreaID);
}

bool _ZN13CActionAssist17aiCheckAttackableEiiii(struct CActionAssist *self, int StartAreaID,
                                                int TargetAreaID, int ArmyIndex, int ArmyAreaID);

bool _ZN6CScene15CheckAttackableEiii(struct CScene *self, int StartAreaID, int TargetAreaID,
                                     int ArmyIndex) {
    if (!_ZN13CActionAssist17aiCheckAttackableEiiii(_ZN13CActionAssist8InstanceEv(), StartAreaID,
                                                    TargetAreaID, ArmyIndex, StartAreaID))
        return false;
    struct CArea *StartArea = _ZN6CScene7GetAreaEi(&g_Scene, StartAreaID);
    int ArmyType = _ZN5CArea7GetArmyEi(StartArea, ArmyIndex)->BasicAbilities->ID;
    if (ArmyType == ArmyType_Rocket) {
        int i;
        for (i = 0; i < _ZN6CScene19GetNumAdjacentAreasEi(self, StartAreaID); i++)
            if (_ZN6CScene13CheckAdjacentEii(self,
                                             _ZN6CScene17GetAdjacentAreaIDEii(self, StartAreaID, i),
                                             TargetAreaID))
                return true;
        return false;
    } else if (ArmyType == ArmyType_AircraftCarrier) {
        float d = _ZN6CScene19GetTwoAreasDistanceEii(self, StartAreaID, TargetAreaID);
        return (d > 0.0 && d < _ZN8CCountry15AirstrikeRadiusEv(StartArea->Country));
    } else
        return _ZN6CScene13CheckAdjacentEii(self, StartAreaID, TargetAreaID);
}
