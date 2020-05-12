//extends CGameState for Save/Load input functions

#ifndef EASYMOD_INGAMELOAD_H
#define EASYMOD_INGAMELOAD_H

#define extends_CGameState \
void OpenSaveGUI(bool load);\
bool OpenLoadEvent(const Event &event);\
bool CloseLoadEvent(const Event &event);\
bool CancelLoadEvent(const Event &event);

#include "CStateManager/CGameState.h"

#endif //EASYMOD_INGAMELOAD_H
