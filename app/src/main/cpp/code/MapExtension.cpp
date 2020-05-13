//Allow to load more map images
//Check if zone loading pattern is followed
//allow to set more areas
//Fix AI rocket melee attack

#include <cstring>
#include "_CActionAI.h"
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
        delete self->BoxImage[i];
        self->BoxImage[i] = NULL;
    }
    for (i = 0; i < 3; i++) {
        ecGraphics::Instance()->FreeTexture(self->BoxTexture[i]);
        self->BoxTexture[i] = NULL;
    }
    for (i = 0; i < self->MapCount; i++) {
        _ZN7ecImageD1Ev(ExtendedBackgroundImage[i]);
        delete ExtendedBackgroundImage[i];
        ExtendedBackgroundImage[i] = NULL;
    }
    for (i = 0; i < self->MapCount; i++) {
        ecGraphics::Instance()->FreeTexture(ExtendedBackgroundTexture[i]);
        ExtendedBackgroundTexture[i] = NULL;
    }
}

void _ZN11CBackgroundD2Ev(struct CBackground *self) __attribute__ ((alias("_ZN11CBackgroundD1Ev")));

void CBackground::Init(int MapID, int TotalX, int TotalY, int TotalW, int TotalH, float EnableX,
                       float EnableY, float EnableW, float EnableH) {
    this->MapTopRightPos[0] = TotalX;
    this->MapTopRightPos[1] = TotalY;
    this->MapSize[0] = TotalW;
    this->MapSize[1] = TotalH;
    float CurrentPos[2] = {0.0, 0.0};
    int MapGridSize[2];
    MapGridSize[0] = (TotalW + 499) / 500;
    MapGridSize[1] = (TotalH + 499) / 500;
    int EnableMapCount = 0;
    this->MapCount = MapGridSize[0] * MapGridSize[1];
    int i;
    ExtendedBackgroundTexture = new ecTexture *[this->MapCount];
    ExtendedBackgroundImage = new ecImage *[this->MapCount];
    char FileName[32];
    for (i = 0; i < this->MapCount; i++) {
        if (CurrentPos[0] < (EnableX + EnableW)
            && CurrentPos[1] < (EnableY + EnableH)
            && (CurrentPos[0] + 500.0) >= EnableX
            && (CurrentPos[1] + 500.0) >= EnableY) {
            sprintf(FileName, "map%d_%d.pkm", MapID, i + 1);
            ExtendedBackgroundTexture[i] = ecGraphics::Instance()->LoadETCTexture(FileName);
            ExtendedBackgroundImage[i] = new ecImage;
            _ZN7ecImageC1EP9ecTextureffff(ExtendedBackgroundImage[i], ExtendedBackgroundTexture[i],
                                          6.0, 6.0, 500.0, 500.0);
            EnableMapCount++;
        } else {
            ExtendedBackgroundTexture[i] = NULL;
            ExtendedBackgroundImage[i] = NULL;
        }
        CurrentPos[0] += 500.0;
        if (CurrentPos[0] >= (float) this->MapSize[0]) {
            CurrentPos[1] += 500.0;
            CurrentPos[0] = 0.0;
        }
    }
    printf("load num bg = %d\n", EnableMapCount);
    const ecTextureRect rect[] = {{0.0, 0.0, 82.0,  82.0,  0.0, 0.0},
                                  {1.0, 0.0, 139.0, 82.0,  0.0, 0.0},
                                  {0.0, 1.0, 82.0,  139.0, 0.0, 0.0}};
    for (i = 0; i < 3; i++) {
        sprintf(FileName, "box%d.png", i + 1);
        this->BoxTexture[i] = ecGraphics::Instance()->LoadTexture(FileName);
        this->BoxImage[i] = new ecImage;
        _ZN7ecImageC1EP9ecTextureRK13ecTextureRect(this->BoxImage[i], this->BoxTexture[i],
                                                   &rect[i]);
    }
}

void CBackground::Render(CCamera *camera) {
    float CurrentPos[2] = {0.0, 0.0};
    int i;
    for (i = 0; i < this->MapCount; i++) {
        if (ExtendedBackgroundImage[i] != NULL)
            ExtendedBackgroundImage[i]->Render(CurrentPos[0], CurrentPos[1]);
        CurrentPos[0] += 500.0;
        if (CurrentPos[0] >= this->MapSize[0]) {
            CurrentPos[1] += 500.0;
            CurrentPos[0] = 0.0;
        }
    }
}

//Check zone image
void CScene::InitAreaImage(int MapID) {
    char FileName[32];
    float CurPos[2] = {0.0, 0.0}, xDir = 1000.0;
    float MapSize[2];
    MapSize[0] = this->AreaMark.Size[0] * 8.0;
    MapSize[1] = this->AreaMark.Size[1] * 8.0;
    int ZoneCount = (((int) MapSize[0] - 1) / 1000 + 1) * (((int) MapSize[1] - 1) / 1000 + 1);
    int AreaCount = this->GetNumAreas();
    bool *ZoneLoaded = new bool[ZoneCount];
    int i, LoadCount = 0;
    for (i = 0; i < ZoneCount; i++) {
        if (CurPos[0] < (this->TopLeftPos[0] + this->Size[0])
            && CurPos[1] < (this->TopLeftPos[1] + this->Size[1])
            && (CurPos[0] + 1000.0) >= this->TopLeftPos[0]
            && (CurPos[1] + 1000.0) >= this->TopLeftPos[1]) {
            if (g_contenscalefactor == 1.0) {
                sprintf(FileName, "m%d_zone%d.xml", MapID, i + 1);
                if (this->AreaTextureRes.LoadRes(FileName, false))
                    LoadCount += 1;
            } else if (g_contenscalefactor == 2.0) {
                sprintf(FileName, "m%d_zone%d_1.xml", MapID, i + 1);
                if (this->AreaTextureRes.LoadRes(FileName, false))
                    LoadCount += 1;
                sprintf(FileName, "m%d_zone%d_2.xml", MapID, i + 1);
                if (this->AreaTextureRes.LoadRes(FileName, false))
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
    this->ZoneImage = new ecImage *[AreaCount];
    for (i = 0; i < AreaCount; i++) {
        sprintf(FileName, "%04d.png", i);
        ecImageAttr *p = this->AreaTextureRes.GetImage(FileName);
        if (p != NULL) {
            this->ZoneImage[i] = new ecImage;
            _ZN7ecImageC1EP11ecImageAttr(this->ZoneImage[i], p);
            this->ZoneImage[i]->SetColor(0xFFFFFFFF, -1);
        } else
            this->ZoneImage[i] = NULL;
    }
    //Validation
    for (i = 0; i < AreaCount; i++) {
        if (g_Scene[i]->Enable && this->ZoneImage[i] == NULL) {
            //Retry failed load
            for (i = 0; i < ZoneCount; i++) {
                if (!ZoneLoaded[i]) {
                    if (g_contenscalefactor == 1.0) {
                        sprintf(FileName, "m%d_zone%d.xml", MapID, i + 1);
                        if (this->AreaTextureRes.LoadRes(FileName, false))
                            LoadCount += 1;
                    } else if (g_contenscalefactor == 2.0) {
                        sprintf(FileName, "m%d_zone%d_1.xml", MapID, i + 1);
                        if (this->AreaTextureRes.LoadRes(FileName, false))
                            LoadCount += 1;
                        sprintf(FileName, "m%d_zone%d_2.xml", MapID, i + 1);
                        if (this->AreaTextureRes.LoadRes(FileName, false))
                            LoadCount += 1;
                    }
                }
            }
            for (i = 0; i < AreaCount; i++) {
                if (this->ZoneImage[i] == NULL) {
                    sprintf(FileName, "%04d.png", i);
                    ecImageAttr *p = this->AreaTextureRes.GetImage(FileName);
                    if (p != NULL) {
                        this->ZoneImage[i] = new ecImage;
                        _ZN7ecImageC1EP11ecImageAttr(this->ZoneImage[i], p);
                        this->ZoneImage[i]->SetColor(0xFFFFFFFF, -1);
                    } else
                        this->ZoneImage[i] = NULL;
                }
            }
            break;
        }
    }
    delete ZoneLoaded;
}

//Extend area count
int CActionAssist::searchNode(int AreaID, int ArmyIndex) {
    this->SearchNodeHead++;
    int CurrentNodeAreaID = this->SearchNodeQueue[this->SearchNodeHead][0];
    int i;
    for (i = 0; i < g_Scene.GetNumAdjacentAreas(CurrentNodeAreaID); i++) {
        CArea *SearchArea = g_Scene.GetAdjacentArea(CurrentNodeAreaID, i);
        int j;
        bool visited = false;
        for (j = 0; j < this->SearchNodeTail; j++)
            if (SearchArea->ID == this->SearchNodeQueue[j][0]) {
                visited = true;
                break;
            }
        if (visited)
            continue;
        if (!this->aiCheckMoveable(CurrentNodeAreaID, SearchArea->ID, ArmyIndex, AreaID)
            && !this->aiCheckAttackable(CurrentNodeAreaID, SearchArea->ID, ArmyIndex, AreaID))
            continue;
        if (!SearchArea->Sea
            && this->getAlliance(AreaID, SearchArea->ID, Ally)
            && !this->getAlliance(AreaID, SearchArea->ID, Self))
            continue;
        if (this->SearchNodeTail < 511)
            this->SearchNodeTail += 1;
        this->SearchNodeQueue[this->SearchNodeTail][0] = SearchArea->ID;
        this->SearchNodeQueue[this->SearchNodeTail][1] = this->SearchNodeHead;
        if (!this->getAlliance(AreaID, SearchArea->ID, Enemy))
            continue;
        if (g_Scene[AreaID]->GetArmy(ArmyIndex)->IsNavy()) {
            if (!SearchArea->Sea) {
                if (SearchArea->ArmyCount > 0)
                    this->TargetNodeType = 3;
                else
                    this->TargetNodeType = 1;
                return SearchArea->ID;
            }
            if (SearchArea->AreaType == 2) {
                this->TargetNodeType = 2;
                return SearchArea->ID;
            }
            continue;
        }
        if (!SearchArea->Sea) {
            if (this->calcAreaValue(SearchArea) > 80)
                this->TargetNodeType = 3;
            else
                this->TargetNodeType = (SearchArea->ArmyCount > 0) ? 2 : 1;
            return SearchArea->ID;
        }
    }
    return -1;
}
