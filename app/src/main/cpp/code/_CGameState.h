//extends CGameState for Save/Load input functions

#ifndef EASYMOD__CGAMESTATE_H
#define EASYMOD__CGAMESTATE_H

#define extends_CGameState \
void OpenSaveGUI(bool load);\
bool OpenLoadEvent(const Event &event);\
bool CloseLoadEvent(const Event &event);\
bool CancelLoadEvent(const Event &event);

#endif //EASYMOD__CGAMESTATE_H
