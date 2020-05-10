//Defines new functions here because I tend to not put declarations not from the original .so in the easytech folder

#ifndef EASYMOD_MODOBJECT_H
#define EASYMOD_MODOBJECT_H

#include "CGameRes.h"
#include "CActionAI.h"
#include "GUI/GUIElement.h"
#include "CStateManager/CGameState.h"

namespace mod __attribute__ ((visibility("hidden"))) {
    struct CGameRes : ::CGameRes {
        static unsigned long HpColor(int HP, int MaxHP);

        void
        RenderUIArmy(const char *CountryName, float x, float y, int ArmyType, int HP, int MaxHP,
                     int Movement, int Cards, int Level, int CommonType, bool AI);
    };

    struct CGameState : ::CGameState {
        void OpenSaveGUI(bool load);

        bool OpenLoadEvent(const Event &event);

        bool CloseLoadEvent(const Event &event);

        bool CancelLoadEvent(const Event &event);
    };

    struct CActionAssist : ::CActionAssist {
        bool aiCheckAttackable(int StartAreaID, int TargetAreaID, int ArmyIndex, int ArmyAreaID);
    };

    struct CArea : ::CArea {
        bool CanContainArmy(CArmy *army);
    };
}

#endif //EASYMOD_MODOBJECT_H
