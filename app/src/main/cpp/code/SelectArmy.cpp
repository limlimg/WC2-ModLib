//Allow to check army stacks of other country
//allow to use card on select army side bar

#define extends_CGameRes \
void RenderUIArmy(const char *CountryName, float x, float y, int ArmyType, int HP, int MaxHP, int Movement, int Cards, int Level, int CommonType, bool AI);

#include <cmath>
#include <cstddef>
#include "CStateManager/CGameState.h"
#include "CGameRes.h"

//control the showing of the side bar
void CGameState::TouchEnd(float x, float y, int index) {
    //check touching state
    int FirstTouchIndex = this->FirstTouchIndex;
    if (index == this->SecondTouchIndex) {
        this->SecondTouch = false;
        this->SecondTouchIndex = 0;
    }
    if (index == this->FirstTouchIndex) {
        this->FirstTouch = false;
        this->FirstTouchIndex = 0;
    }
    if (g_GameManager.IsManipulate()) {
        CountryAction CountryAction = {CountryAction::NoAction, NoCard, 0, 0, 0};
        this->ShouldCameraAutoFixPos = false;
        if (index != FirstTouchIndex)
            return;
        this->CTouchInertia.TouchEnd(x, y, index);
        if (fabs(this->FirstTouchStartPos[0] - x) >= 15.0)
            return;
        if (fabs(this->FirstTouchStartPos[1] - y) >= 15.0)
            return;
        g_Scene.NewRoundFlashing = false;
        CArea *TouchArea = g_Scene.ScreenToArea(x, y);
        if (TouchArea == NULL || !TouchArea->Enable)
            return;
        //use card
        CardDef *Card = this->BuyCardGUI->GetSelCard();
        if (Card != NULL && this->BuyCardGUI->CardCanTarget && !this->BuyingCard) {
            if (g_GameManager.GetPlayerCountry()->CheckCardTargetArea(Card, TouchArea->ID)) {
                CountryAction.ActionType = CountryAction::UseCardAction;
                CountryAction.CardID = Card->ID;
                CountryAction.TargetAreaID = TouchArea->ID;
                CountryAction.ArmyIndex = 0;
                g_GameManager.GetPlayerCountry()->Action(CountryAction);
                this->BuyingCard = true;
                this->TaxGUI->SetArea(TouchArea->ID);
            }
            return;
        }
        //select or unselect area
        CArea *SelectedArea = g_Scene.GetSelectedArea();
        if (SelectedArea) {
            if (SelectedArea == TouchArea) {
                this->UnselectArea();
                return;
            }
            //manipulating army
            if (SelectedArea->IsActive() &&
                (SelectedArea->Country == g_GameManager)) {
                if (SelectedArea->ArmyDrafting || SelectedArea->ArmyMovingIn ||
                    SelectedArea->ArmyMovingToFront)
                    return;
                if (g_Scene.CheckMoveable(SelectedArea->ID, TouchArea->ID, 0)) {
                    CountryAction.ActionType = CountryAction::ArmyMoveAction;
                    CountryAction.StartAreaID = SelectedArea->ID;
                    CountryAction.ArmyIndex = 0;
                    CountryAction.TargetAreaID = TouchArea->ID;
                    g_GameManager.GetPlayerCountry()->Action(CountryAction);
                } else if (g_Scene.CheckAttackable(SelectedArea->ID, TouchArea->ID, 0)) {
                    this->AttackBoxGUI->SetAttack(SelectedArea->ID, TouchArea->ID);
                    this->AttackBoxGUI->Show();
                }
                this->UnselectArea();
                return;
            }
            this->UnselectArea();
        }
        this->SelectArea(TouchArea->ID);
    }
}

void CGameState::UnselectArea() {
    g_Scene.UnselectArea();
    this->TaxGUI->Hide();
    this->SelArmyGUI->Hide();
}

void CGameState::SelectArea(int AreaID) {
    g_Scene.SelectArea(AreaID);
    this->TaxGUI->SetArea(AreaID);
    this->TaxGUI->Show();
    if (g_Scene[AreaID]->ArmyCount > 1) {
        this->SelArmyGUI->SetArea(AreaID);
        this->SelArmyGUI->UseCard = false;
        this->SelArmyGUI->Show();
    }
}

//disallow to sort other countries' army
//allow to use card on select army side bar
bool GUISelArmy::OnEvent(const Event &event) {
    if (event.type == Event::Touch) {
        if (event.info.touch.type == Event::info::Touch::begin &&
            this->CheckInRect(event.info.touch.pos[0], event.info.touch.pos[1]))
            return true;
    } else if (event.type == Event::GUI) {
        if (event.info.GUI.type == Event::info::GUI::Button &&
            g_Scene[this->AreaID]->Country == g_GameManager) {
            int i;
            for (i = 0; i < 4; i++) {
                if (event.info.GUI.ptr == this->ArmyItem[i]) {
                    CGameState *game = static_cast<CGameState *>(CStateManager::Instance()->GetStatePtr(
                            Game));
                    if ((game->BuyCardGUI->GetSelCard() != NULL) &&
                        game->BuyCardGUI->CardCanTarget && game->BuyCardGUI->CardTargetArmy)
                        this->TargetArmy(i);
                    else
                        this->MoveArmyToFront(i);
                    break;
                }
            }
        }
    }
    return this->GUIElement::OnEvent(event);
}

//Show AI medal on sidebar
static unsigned long HpColor(int HP, int MaxHP) {
    int r, g, b;
    if (HP * 2 <= MaxHP) {
        r = 0;
        g = 255 - 255 * (MaxHP - 2 * HP) / MaxHP;
        b = 255;
    } else {
        g = 255;
        b = 255 - 255 * (2 * HP - MaxHP) / MaxHP;
        r = 128 - (b >> 1);
    }
    return b + (g << 8) + (r << 16) - 0x1000000ul;
}

void
CGameRes::RenderUIArmy(const char *CountryName, float x, float y, int ArmyType, int HP, int MaxHP,
                       int Movement, int Cards, int Level, int CommonType, bool AI) {
    ecImage *ArmyImage = this->GetArmyImage(CountryName, ArmyType, false);
    if (ArmyImage != NULL) {
        ArmyImage->SetColor(0xFFFFFFFF, -1);
        ArmyImage->RenderEx(x, y, 0.0, -1.0, 1.0);
    }
    this->Image_hpbar->Render(x - 30.0, y - 12.0);
    this->Image_hpbar_fill->SetColor(HpColor(HP, MaxHP), -1);
    this->Image_hpbar_fill->RenderEx(x - 11.0, y - 4.0, 0.0, (float) HP * 33.0 / (float) MaxHP,
                                     1.0);
    this->Image_movementmark[Movement]->Render(x - 23.0, y - 7.0);
    if (Cards & (1 << CArmy::Commander)) {
        if (AI)
            this->RenderAICommanderMedal(1, x, y + 10.0, CountryName, CommonType);
        else
            this->Image_commander_level[Level / 3]->Render(x + 8.0, y - 8.0);
    } else if (Level > 0)
        this->Image_unitlevelmark[Level - 1]->Render(x + 8.0, y - 8.0);
    if (!Cards)
        return;
    y -= 20.0;
    int i;
    for (i = 0; i < 3; i++) {
        if ((Cards >> i) & 1) {
            this->Image_cardmark[i]->Render(x + 16.0, y);
            y -= 15.0;
        }
    }
}

void GUIArmyItem::OnRender() {
    GUIRect rect;
    this->GetAbsRect(rect);
    if (this->Army == NULL)
        return;
    g_GameRes.RenderUIArmy(this->Army->Country->Name, rect.Pos[0] + rect.Size[0] * 0.5,
                           rect.Pos[1] + rect.Size[1], this->Army->BasicAbilities->ID,
                           this->Army->Hp, this->Army->GetMaxStrength(), this->Army->Movement,
                           this->Army->Cards, (this->Army->Cards & (1 << CArmy::Commander))
                                              ? this->Army->Country->GetCommanderLevel()
                                              : this->Army->Level, this->Army->Country->Alliance,
                           this->Army->Country->AI);
}
