//Allow to load more map images
//Check if zone loading pattern is followed
//allow to set more areas
//Fix AI rocket melee attack

#include <stdio.h>
#include "CustomizableData.h"
#include "cxxnew.h"
#include "CScene.h"
#include "CActionAI.h"

float g_contenscalefactor = 2.0;

static struct ecTexture **ExtendedBackgroundTexture;
static struct ecImage **ExtendedBackgroundImage;

//Extending background picture
void _ZN11CBackgroundC1Ev(struct CBackground *self) {
    int i;
    for (i = 0; i < 112; i++) {
        self->BackgroundTexture[i] = NULL;
        self->BackgroundImage[i] = NULL;
    }
    self->BoxTexture[0] = NULL;
    self->BoxTexture[1] = NULL;
    self->BoxTexture[2] = NULL;
    self->BoxImage[0] = NULL;
    self->BoxImage[1] = NULL;
    self->BoxImage[2] = NULL;
}

void _ZN11CBackgroundC2Ev(struct CBackground *self) __attribute__ ((alias("_ZN11CBackgroundC1Ev")));

void _ZN11CBackgroundD1Ev(struct CBackground *self) {
    int i;
    for (i = 0; i < 3; i++) {
        _ZN7ecImageD1Ev(self->BoxImage[i]);
        free(self->BoxImage[i]);
        self->BoxImage[i] = NULL;
    }
    for (i = 0; i < 3; i++) {
        _ZN10ecGraphics11FreeTextureEP9ecTexture(_ZN10ecGraphics8InstanceEv(), self->BoxTexture[i]);
        self->BoxTexture[i] = NULL;
    }
    for (i = 0; i < self->MapCount; i++) {
        _ZN7ecImageD1Ev(ExtendedBackgroundImage[i]);
        free(ExtendedBackgroundImage[i]);
        ExtendedBackgroundImage[i] = NULL;
    }
    for (i = 0; i < self->MapCount; i++) {
        _ZN10ecGraphics11FreeTextureEP9ecTexture(_ZN10ecGraphics8InstanceEv(),
                                                 ExtendedBackgroundTexture[i]);
        ExtendedBackgroundTexture[i] = NULL;
    }
}

void _ZN11CBackgroundD2Ev(struct CBackground *self) __attribute__ ((alias("_ZN11CBackgroundD1Ev")));

void _ZN11CBackground4InitEiiiiiffff(struct CBackground *self, int MapID, int TotalX, int TotalY,
                                     int TotalW, int TotalH, float EnableX, float EnableY,
                                     float EnableW, float EnableH) {
    self->MapTopRightPos[0] = TotalX;
    self->MapTopRightPos[1] = TotalY;
    self->MapSize[0] = TotalW;
    self->MapSize[1] = TotalH;
    float CurrentPos[2] = {0.0, 0.0};
    int MapGridSize[2];
    MapGridSize[0] = (TotalW + 499) / 500;
    MapGridSize[1] = (TotalH + 499) / 500;
    int EnableMapCount = 0;
    self->MapCount = MapGridSize[0] * MapGridSize[1];
    int i;
    ExtendedBackgroundTexture = newix(struct ecTexture*, self->MapCount);
    ExtendedBackgroundImage = newix(struct ecImage*, self->MapCount);
    char FileName[32];
    for (i = 0; i < self->MapCount; i++) {
        if (CurrentPos[0] < (EnableX + EnableW)
            && CurrentPos[1] < (EnableY + EnableH)
            && (CurrentPos[0] + 500.0) >= EnableX
            && (CurrentPos[1] + 500.0) >= EnableY) {
            sprintf(FileName, "map%d_%d.pkm", MapID, i + 1);
            ExtendedBackgroundTexture[i] = _ZN10ecGraphics14LoadETCTextureEPKc(
                    _ZN10ecGraphics8InstanceEv(), FileName);
            ExtendedBackgroundImage[i] = new(struct ecImage);
            _ZN7ecImageC1EP9ecTextureffff(ExtendedBackgroundImage[i], ExtendedBackgroundTexture[i],
                                          6.0, 6.0, 500.0, 500.0);
            EnableMapCount++;
        } else {
            ExtendedBackgroundTexture[i] = NULL;
            ExtendedBackgroundImage[i] = NULL;
        }
        CurrentPos[0] += 500.0;
        if (CurrentPos[0] >= (float) self->MapSize[0]) {
            CurrentPos[1] += 500.0;
            CurrentPos[0] = 0.0;
        }
    }
    printf("load num bg = %d\n", EnableMapCount);
    const struct ecTextureRect rect[] = {{0.0, 0.0, 82.0,  82.0,  0.0, 0.0},
                                         {1.0, 0.0, 139.0, 82.0,  0.0, 0.0},
                                         {0.0, 1.0, 82.0,  139.0, 0.0, 0.0}};
    for (i = 0; i < 3; i++) {
        sprintf(FileName, "box%d.png", i + 1);
        self->BoxTexture[i] = _ZN10ecGraphics11LoadTextureEPKc(_ZN10ecGraphics8InstanceEv(),
                                                               FileName);
        self->BoxImage[i] = new(struct ecImage);
        _ZN7ecImageC1EP9ecTextureRK13ecTextureRect(self->BoxImage[i], self->BoxTexture[i],
                                                   &rect[i]);
    }
}

void _ZN11CBackground6RenderEP7CCamera(struct CBackground *self, struct CCamera *camera) {
    float CurrentPos[2] = {0.0, 0.0};
    int i;
    for (i = 0; i < self->MapCount; i++) {
        if (ExtendedBackgroundImage[i] != NULL)
            _ZN7ecImage6RenderEff(ExtendedBackgroundImage[i], CurrentPos[0], CurrentPos[1]);
        CurrentPos[0] += 500.0;
        if (CurrentPos[0] >= self->MapSize[0]) {
            CurrentPos[1] += 500.0;
            CurrentPos[0] = 0.0;
        }
    }
}

//Check zone image
void _ZN6CScene13InitAreaImageEi(struct CScene *self, int MapID) {
    char FileName[32];
    float CurPos[2] = {0.0, 0.0}, xDir = 1000.0;
    float MapSize[2];
    MapSize[0] = (float) self->AreaMark.Size[0] * 8.0;
    MapSize[1] = (float) self->AreaMark.Size[1] * 8.0;
    int ZoneCount = (((int) MapSize[0] - 1) / 1000 + 1) * (((int) MapSize[1] - 1) / 1000 + 1);
    int AreaCount = _ZN6CScene11GetNumAreasEv(self);
    bool *ZoneLoaded = newix(bool, ZoneCount);
    int i, LoadCount = 0;
    for (i = 0; i < ZoneCount; i++) {
        if (CurPos[0] < (self->TopLeftPos[0] + self->Size[0])
            && CurPos[1] < (self->TopLeftPos[1] + self->Size[1])
            && (CurPos[0] + 1000.0) >= self->TopLeftPos[0]
            && (CurPos[1] + 1000.0) >= self->TopLeftPos[1]) {
            if (g_contenscalefactor == 1.0) {
                sprintf(FileName, "m%d_zone%d.xml", MapID, i + 1);
                if (_ZN12ecTextureRes7LoadResEPKcb(&self->AreaImage, FileName, false))
                    LoadCount += 1;
            } else if (g_contenscalefactor == 2.0) {
                sprintf(FileName, "m%d_zone%d_1.xml", MapID, i + 1);
                if (_ZN12ecTextureRes7LoadResEPKcb(&self->AreaImage, FileName, false))
                    LoadCount += 1;
                sprintf(FileName, "m%d_zone%d_2.xml", MapID, i + 1);
                if (_ZN12ecTextureRes7LoadResEPKcb(&self->AreaImage, FileName, false))
                    LoadCount += 1;
            }
            ZoneLoaded[i] = true;
        } else
            ZoneLoaded[i] = false;
        CurPos[0] += xDir;
        if (CurPos[0] >= MapSize[0]) {
            CurPos[0] -= 1000.0;
            CurPos[1] += 1000.0;
            xDir = -1000.0;
        } else if (CurPos[0] < 0.0) {
            CurPos[0] += 1000.0;
            CurPos[1] += 1000.0;
            xDir = 1000.0;
        }
    }
    printf("load num zone = %d\n", LoadCount);
    self->ZoneImage = newix(struct ecImage*, AreaCount);
    for (i = 0; i < AreaCount; i++) {
        sprintf(FileName, "%04d.png", i);
        struct ecImageAttr *p = _ZN12ecTextureRes8GetImageEPKc(&self->AreaImage, FileName);
        if (p != NULL) {
            self->ZoneImage[i] = new(struct ecImage);
            _ZN7ecImageC1EP11ecImageAttr(self->ZoneImage[i], p);
            _ZN7ecImage8SetColorEmi(self->ZoneImage[i], 0xFFFFFFFF, -1);
        } else
            self->ZoneImage[i] = NULL;
    }
    //Validation
    for (i = 0; i < AreaCount; i++) {
        if (_ZN6CScene7GetAreaEi(&g_Scene, i)->Enable && self->ZoneImage[i] == NULL) {
            //Retry failed load
            for (i = 0; i < ZoneCount; i++) {
                if (!ZoneLoaded[i]) {
                    if (g_contenscalefactor == 1.0) {
                        sprintf(FileName, "m%d_zone%d.xml", MapID, i + 1);
                        if (_ZN12ecTextureRes7LoadResEPKcb(&self->AreaImage, FileName, false))
                            LoadCount += 1;
                    } else if (g_contenscalefactor == 2.0) {
                        sprintf(FileName, "m%d_zone%d_1.xml", MapID, i + 1);
                        if (_ZN12ecTextureRes7LoadResEPKcb(&self->AreaImage, FileName, false))
                            LoadCount += 1;
                        sprintf(FileName, "m%d_zone%d_2.xml", MapID, i + 1);
                        if (_ZN12ecTextureRes7LoadResEPKcb(&self->AreaImage, FileName, false))
                            LoadCount += 1;
                    }
                }
            }
            for (i = 0; i < AreaCount; i++) {
                if (self->ZoneImage[i] == NULL) {
                    sprintf(FileName, "%04d.png", i);
                    struct ecImageAttr *p = _ZN12ecTextureRes8GetImageEPKc(&self->AreaImage,
                                                                           FileName);
                    if (p != NULL) {
                        self->ZoneImage[i] = new(struct ecImage);
                        _ZN7ecImageC1EP11ecImageAttr(self->ZoneImage[i], p);
                        _ZN7ecImage8SetColorEmi(self->ZoneImage[i], 0xFFFFFFFF, -1);
                    } else
                        self->ZoneImage[i] = NULL;
                }
            }
            break;
        }
    }
    free(ZoneLoaded);
}

//Extend area count
bool _ZN13CActionAssist17aiCheckAttackableEiiii(struct CActionAssist *self, int StartAreaID,
                                                int TargetAreaID, int ArmyIndex, int ArmyAreaID);

int _ZN13CActionAssist10searchNodeEii(struct CActionAssist *self, int AreaID, int ArmyIndex) {
    self->SearchNodeHead++;
    int CurrentNodeAreaID = self->SearchNodeQueue[self->SearchNodeHead][0];
    int i;
    for (i = 0; i < _ZN6CScene19GetNumAdjacentAreasEi(&g_Scene, CurrentNodeAreaID); i++) {
        struct CArea *SearchArea = _ZN6CScene15GetAdjacentAreaEii(&g_Scene, CurrentNodeAreaID, i);
        int j;
        bool visited = false;
        for (j = 0; j < self->SearchNodeTail; j++)
            if (SearchArea->ID == self->SearchNodeQueue[j][0]) {
                visited = true;
                break;
            }
        if (visited)
            continue;
        if (!_ZN13CActionAssist15aiCheckMoveableEiiii(self, CurrentNodeAreaID, SearchArea->ID,
                                                      ArmyIndex, AreaID)
            && !_ZN13CActionAssist17aiCheckAttackableEiiii(self, CurrentNodeAreaID, SearchArea->ID,
                                                           ArmyIndex, AreaID))
            continue;
        if (!SearchArea->Sea
            && _ZN13CActionAssist11getAllianceEiii(self, AreaID, SearchArea->ID, 256)
            && !_ZN13CActionAssist11getAllianceEiii(self, AreaID, SearchArea->ID, 1024))
            continue;
        if (self->SearchNodeTail < 511)
            self->SearchNodeTail += 1;
        self->SearchNodeQueue[self->SearchNodeTail][0] = SearchArea->ID;
        self->SearchNodeQueue[self->SearchNodeTail][1] = self->SearchNodeHead;
        if (!_ZN13CActionAssist11getAllianceEiii(self, AreaID, SearchArea->ID, 768))
            continue;
        if (_ZN5CArmy6IsNavyEv(
                _ZN5CArea7GetArmyEi(_ZN6CScene7GetAreaEi(&g_Scene, AreaID), ArmyIndex))) {
            if (!SearchArea->Sea) {
                if (SearchArea->ArmyCount > 0)
                    self->TargetNodeType = 3;
                else
                    self->TargetNodeType = 1;
                return SearchArea->ID;
            }
            if (SearchArea->AreaType == 2) {
                self->TargetNodeType = 2;
                return SearchArea->ID;
            }
            continue;
        }
        if (!SearchArea->Sea) {
            if (_ZN13CActionAssist13calcAreaValueEP5CArea(self, SearchArea) > 80)
                self->TargetNodeType = 3;
            else
                self->TargetNodeType = (SearchArea->ArmyCount > 0) ? 2 : 1;
            return SearchArea->ID;
        }
    }
    return -1;
}

bool _ZN5CArmy7HasCardEi(struct CArmy *self, int CardID) {
    return ((self->Cards >> CardID) & 1) != 0;
}

bool _ZN5CArea14CanContainArmyEP5CArmy(struct CArea *self, struct CArmy *army) {
    if (self->ArmyCount >= 4)
        return false;
    int i, TroopCount = 0, NavyCount = 0;
    for (i = 0; i < self->ArmyCount; i++)
        if (_ZN5CArmy6IsNavyEv(_ZN5CArea7GetArmyEi(self, i)))
            NavyCount++;
        else
            TroopCount++;
    if (_ZN5CArmy6IsNavyEv(army))
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
    if (!self->Sea)
        return !_ZN5CArmy6IsNavyEv(army);
    else
        return _ZN5CArmy6IsNavyEv(army) || _ZN5CArmy7HasCardEi(army, Card_Carrier);
}

bool _ZN13CActionAssist15aiCheckMoveableEiiii(struct CActionAssist *self, int StartAreaID,
                                              int TargetAreaID, int ArmyIndex, int ArmyAreaID) {
    struct CArea *ArmyArea = _ZN6CScene7GetAreaEi(&g_Scene, ArmyAreaID);
    struct CArea *TargetArea = _ZN6CScene7GetAreaEi(&g_Scene, TargetAreaID);
    if (ArmyArea->Country != TargetArea->Country && TargetArea->ArmyCount != 0)
        return false;
    if (ArmyArea->ArmyCount <= ArmyIndex)
        return false;
    struct CArmy *Army = _ZN5CArea7GetArmyEi(ArmyArea, ArmyIndex);
    if (Army->Movement <= 0)
        return false;
    return _ZN5CArea14CanContainArmyEP5CArmy(TargetArea, Army);
}

bool _ZN13CActionAssist17aiCheckAttackableEiiii(struct CActionAssist *self, int StartAreaID,
                                                int TargetAreaID, int ArmyIndex, int ArmyAreaID) {
    if (_ZN13CActionAssist11getAllianceEiii(self, ArmyAreaID, TargetAreaID, 256))
        return false;
    struct CArea *ArmyArea = _ZN6CScene7GetAreaEi(&g_Scene, ArmyAreaID);
    if (ArmyArea->ArmyCount <= ArmyIndex)
        return false;
    struct CArea *TargetArea = _ZN6CScene7GetAreaEi(&g_Scene, TargetAreaID);
    if (TargetArea->ArmyCount <= 0)
        return false;
    struct CArmy *Army = _ZN5CArea7GetArmyEi(ArmyArea, ArmyIndex);
    //Fix AI rocket melee attack
    if (Army->BasicAbilities->ID == ArmyType_Rocket &&
        _ZN6CScene13CheckAdjacentEii(&g_Scene, ArmyAreaID, TargetAreaID))
        return false;
    return Army->Movement > 0;
}
