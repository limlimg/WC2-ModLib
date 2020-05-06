//Allow to check army stacks of other country

#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include "CStateManager/CGameState.h"
#include "CGameManager.h"
#include "CScene.h"

//control the showing of the side bar
void _ZN10CGameState8TouchEndEffi(struct CGameState *self, float x, float y, int index) {
    //check touching state
    int FirstTouchIndex = self->FirstTouchIndex;
    if (index == self->SecondTouchIndex) {
        self->SecondTouch = false;
        self->SecondTouchIndex = 0;
    }
    if (index == self->FirstTouchIndex) {
        self->FirstTouch = false;
        self->FirstTouchIndex = 0;
    }
    if (_ZN12CGameManager12IsManipulateEv(&g_GameManager)) {
        struct CountryAction CountryAction = {0, 0, 0, 0, 0};
        self->ShouldCameraAutoFixPos = false;
        if (index != FirstTouchIndex)
            return;
        _ZN13CTouchInertia8TouchEndEffi(&self->CTouchInertia, x, y, index);
        if (fabs(self->FirstTouchStartPos[0] - x) >= 15.0)
            return;
        if (fabs(self->FirstTouchStartPos[1] - y) >= 15.0)
            return;
        g_Scene.NewRoundFlashing = false;
        struct CArea *TouchArea = _ZN6CScene12ScreenToAreaEff(&g_Scene, x, y);
        if (TouchArea == NULL || !TouchArea->Enable)
            return;
        //use card
        struct CardDef *Card = _ZN10GUIBuyCard10GetSelCardEv(self->BuyCardGUI);
        if (Card != NULL && self->BuyCardGUI->CardCanTarget && !self->BuyingCard) {
            if (_ZN8CCountry19CheckCardTargetAreaEP7CardDefi(
                    _ZN12CGameManager16GetPlayerCountryEv(&g_GameManager), Card, TouchArea->ID)) {
                CountryAction.ActionType = 5;
                CountryAction.CardID = Card->ID;
                CountryAction.TargetAreaID = TouchArea->ID;
                CountryAction.ArmyIndex = 0;
                _ZN8CCountry6ActionERK13CountryAction(
                        _ZN12CGameManager16GetPlayerCountryEv(&g_GameManager), &CountryAction);
                self->BuyingCard = true;
                _ZN6GUITax7SetAreaEi(self->TaxGUI, TouchArea->ID);
            }
            return;
        }
        //select or unselect area
        struct CArea *SelectedArea = _ZN6CScene15GetSelectedAreaEv(&g_Scene);
        if (SelectedArea) {
            if (SelectedArea == TouchArea) {
                _ZN10CGameState12UnselectAreaEv(self);
                return;
            }
            //manipulating army
            if (_ZN5CArea8IsActiveEv(SelectedArea) &&
                (SelectedArea->Country == _ZN12CGameManager13GetCurCountryEv(&g_GameManager))) {
                if (SelectedArea->ArmyDrafting || SelectedArea->ArmyMovingIn ||
                    SelectedArea->ArmyMovingToFront)
                    return;
                if (_ZN6CScene13CheckMoveableEiii(&g_Scene, SelectedArea->ID, TouchArea->ID, 0)) {
                    CountryAction.ActionType = 1;
                    CountryAction.StartAreaID = SelectedArea->ID;
                    CountryAction.ArmyIndex = 0;
                    CountryAction.TargetAreaID = TouchArea->ID;
                    _ZN8CCountry6ActionERK13CountryAction(
                            _ZN12CGameManager16GetPlayerCountryEv(&g_GameManager), &CountryAction);
                } else if (_ZN6CScene15CheckAttackableEiii(&g_Scene, SelectedArea->ID,
                                                           TouchArea->ID, 0)) {
                    _ZN12GUIAttackBox9SetAttackEii(self->AttackBoxGUI, SelectedArea->ID,
                                                   TouchArea->ID);
                    _ZN10GUIElement4ShowEv((struct GUIElement *) self->AttackBoxGUI);
                }
                _ZN10CGameState12UnselectAreaEv(self);
                return;
            }
            _ZN10CGameState12UnselectAreaEv(self);
        }
        _ZN10CGameState10SelectAreaEi(self, TouchArea->ID);
    }
}

void _ZN10CGameState12UnselectAreaEv(struct CGameState *self) {
    _ZN6CScene12UnselectAreaEv(&g_Scene);
    _ZN10GUIElement4HideEv((struct GUIElement *) self->TaxGUI);
    _ZN10GUIElement4HideEv((struct GUIElement *) self->SelArmyGUI);
}

void _ZN10CGameState10SelectAreaEi(struct CGameState *self, int AreaID) {
    _ZN6CScene10SelectAreaEi(&g_Scene, AreaID);
    _ZN6GUITax7SetAreaEi(self->TaxGUI, AreaID);
    _ZN10GUIElement4ShowEv((struct GUIElement *) self->TaxGUI);
    if (_ZN6CScene7GetAreaEi(&g_Scene, AreaID)->ArmyCount > 1) {
        _ZN10GUISelArmy7SetAreaEi(self->SelArmyGUI, AreaID);
        self->SelArmyGUI->UseCard = false;
        _ZN10GUIElement4ShowEv((struct GUIElement *) self->SelArmyGUI);
    }
}

//disallow to sort other countries' army
bool _ZN10GUISelArmy7OnEventERK5Event(struct GUISelArmy *self, const struct Event *event) {
    if (event->type == Touch) {
        if (event->info.touch.type == 0 &&
            _ZN10GUIElement11CheckInRectEff((struct GUIElement *) self, event->info.touch.pos[0],
                                            event->info.touch.pos[1]))
            return true;
    } else if (event->type == GUI) {
        if (event->info.GUI.type == 0 && _ZN6CScene7GetAreaEi(&g_Scene, self->AreaID)->Country ==
                                         _ZN12CGameManager13GetCurCountryEv(&g_GameManager)) {
            int i;
            for (i = 0; i < 4; i++) {
                if (event->info.GUI.ptr == (struct GUIElement *) self->ArmyItem[i]) {
                    if (self->UseCard)
                        _ZN10GUISelArmy10TargetArmyEi(self, i);
                    else
                        _ZN10GUISelArmy15MoveArmyToFrontEi(self, i);
                    break;
                }
            }
        }
    }
    return _ZN10GUIElement7OnEventERK5Event((struct GUIElement *) self, event);
}
