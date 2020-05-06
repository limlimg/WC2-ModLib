//Allow to check army stacks of other country

#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include "CStateManager/CGameState.h"
#include "CGameManager.h"
#include "CScene.h"
#include "CGameRes.h"

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

//Show AI medal on sidebar
static void
_ZN8CGameRes12RenderUIArmyEPKcffiiiiiiib(struct CGameRes *self, const char *CountryName, float x,
                                         float y, int ArmyType, int HP, int MaxHP, int Movement,
                                         int Cards, int Level, int CommonType, bool AI) {
    struct ecImage *ArmyImage = _ZN8CGameRes12GetArmyImageEPKcib(self, CountryName, ArmyType,
                                                                 false);
    if (ArmyImage != NULL) {
        _ZN7ecImage8SetColorEmi(ArmyImage, 0xFFFFFFFF, -1);
        _ZN7ecImage8RenderExEfffff(ArmyImage, x, y, 0.0, -1.0, 1.0);
    }
    _ZN7ecImage6RenderEff(self->Image_hpbar, x - 30.0, y - 12.0);
    _ZN7ecImage8SetColorEmi(self->Image_hpbar_fill, HpColor(HP, MaxHP), -1);
    _ZN7ecImage8RenderExEfffff(self->Image_hpbar_fill, x - 11.0, y - 4.0, 0.0,
                               (float) HP * 33.0 / (float) MaxHP, 1.0);
    _ZN7ecImage6RenderEff(self->Image_movementmark[Movement], x - 23.0, y - 7.0);
    if (Cards & 8) {
        if (AI)
            _ZN8CGameRes22RenderAICommanderMedalEiffPKci(&g_GameRes, 1, x, y + 10.0, CountryName,
                                                         CommonType);
        else
            _ZN7ecImage6RenderEff(self->Image_commander_level[Level / 3], x + 8.0, y - 8.0);
    } else if (Level > 0)
        _ZN7ecImage6RenderEff(self->Image_unitlevelmark[Level - 1], x + 8.0, y - 8.0);
    if (!Cards)
        return;
    y -= 20.0;
    int i;
    for (i = 0; i < 3; i++) {
        if ((Cards >> i) & 1) {
            _ZN7ecImage6RenderEff(self->Image_cardmark[i], x + 16.0, y);
            y -= 15.0;
        }
    }
}

void _ZN11GUIArmyItem8OnRenderEv(struct GUIArmyItem *self) {
    struct GUIRect rect;
    _ZN10GUIElement10GetAbsRectER7GUIRect((struct GUIElement *) self, &rect);
    if (self->Army == NULL)
        return;
    _ZN8CGameRes12RenderUIArmyEPKcffiiiiiiib(&g_GameRes, self->Army->Country->Name,
                                             rect.Pos[0] + rect.Size[0] * 0.5,
                                             rect.Pos[1] + rect.Size[1],
                                             self->Army->BasicAbilities->ID, self->Army->Hp,
                                             _ZN5CArmy14GetMaxStrengthEv(self->Army),
                                             self->Army->Movement, self->Army->Cards,
                                             (self->Army->Cards & 8)
                                             ? _ZN8CCountry17GetCommanderLevelEv(
                                                     self->Army->Country) : self->Army->Level,
                                             self->Army->Country->Alliance,
                                             self->Army->Country->AI);
}
