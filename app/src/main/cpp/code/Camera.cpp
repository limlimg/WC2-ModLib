//Zooming the camera without limit

#include <cmath>
#include "CScene.h"
#include "CGameSettings.h"

static const float pi = 3.141592653589793238462643383279502884197939937;

//Infinite zoom
void CCamera::SetPosAndScale(float x, float y, float scale) {
    float fWidth = (this->ScreenHalfSize[0] + this->ScreenHalfSize[0]) / this->MapSize[0];
    float fMinScale = (this->ScreenHalfSize[1] + this->ScreenHalfSize[1]) / this->MapSize[1];
    if (fMinScale > fWidth)
        fMinScale = fWidth;
    if (scale < fMinScale)
        scale = fMinScale;
    if (scale > 1.0)
        scale = 1.0;
    this->Scale = scale;
    this->SetPos(x, y, true);
}

//focus the camera on the middle when the view is bigger that the map
bool CCamera::SetPos(float x, float y, bool border) {
    this->CenterPos[0] = x;
    this->CenterPos[1] = y;
    int i;
    bool bFixed = false;
    for (i = 0; i < 2; i++) {
        float fMinPos = this->TopLeftPos[i];
        float fMaxPos = fMinPos + this->MapSize[i];
        if (border) {
            float fMinDistance = this->ScreenHalfSize[i] / this->Scale;
            fMinPos += fMinDistance;
            fMaxPos -= fMinDistance;
        }
        float fCenterPos = this->CenterPos[i];
        if (fCenterPos < fMinPos) {
            fCenterPos = fMinPos;
            bFixed = true;
        }
        if (fCenterPos > fMaxPos) {
            fCenterPos = fMaxPos;
            bFixed = true;
        }
        if (fMinPos > fMaxPos)
            fCenterPos = (fMinPos + fMaxPos) * 0.5;
        if (bFixed)
            this->CenterPos[i] = fCenterPos;
    }
    return bFixed;
}

bool CCamera::Move(float x, float y, bool border) {
    return this->SetPos(this->CenterPos[0] + x / this->Scale, this->CenterPos[1] + y / this->Scale,
                        border);
}

void CCamera::SetAutoFixPos(bool enabled) {
    this->AutoFixPos = enabled;
    if (enabled) {
        int i;
        for (i = 0; i < 2; i++) {
            float MinDistance = this->ScreenHalfSize[i] / this->Scale;
            float MinPos = this->TopLeftPos[i] + MinDistance;
            float MaxPos = this->TopLeftPos[i] + this->MapSize[i] - MinDistance;
            float TargetPos = this->CenterPos[i];
            if (TargetPos < MinPos)
                TargetPos = MinPos;
            if (TargetPos > MaxPos)
                TargetPos = MaxPos;
            if (MinPos > MaxPos)
                TargetPos = (MinPos + MaxPos) * 0.5;
            float distance = TargetPos - this->CenterPos[i];
            if (fabs(distance) > 1.0) {
                this->TargetPos[i] = TargetPos;
                this->Speed[i] = distance * 0.1;
                this->IsMoving = true;
            } else {
                this->Speed[i] = 0.0;
                this->CenterPos[i] = TargetPos;
            }
        }
    } else {
        this->Speed[0] = 0.0;
        this->Speed[1] = 0.0;
    }
}

void CCamera::MoveTo(float x, float y, bool border) {
    const float SetSpeed[5] = {0.012, 0.015, 0.02, 0.026, 0.034};
    this->TargetPos[0] = x;
    this->TargetPos[1] = y;
    int i;
    for (i = 0; i < 2; i++) {
        float fMinPos = this->TopLeftPos[i];
        float fMaxPos = fMinPos + this->MapSize[i];
        if (border) {
            float fMinDistance = this->ScreenHalfSize[i] / this->Scale;
            fMinPos += fMinDistance;
            fMaxPos -= fMinDistance;
        }
        float fTargetPos = this->TargetPos[i];
        if (fTargetPos < fMinPos)
            fTargetPos = fMinPos;
        if (fTargetPos > fMaxPos)
            fTargetPos = fMaxPos;
        if (fMinPos > fMaxPos)
            fTargetPos = (fMinPos + fMaxPos) * 0.5;
        float fStep = fTargetPos - this->CenterPos[i];
        if (fabs(fStep) > 1.0) {
            this->TargetPos[i] = fTargetPos;
            this->Speed[i] = fStep * SetSpeed[g_GameSettings.Speed];
            this->IsMoving = true;
        } else {
            this->Speed[i] = 0.0;
            this->CenterPos[i] = fTargetPos;
        }
    }
}

//Hide map showing beyond border
void CBackground::RenderBox(CCamera *camera, float x, float y, float w, float h) {
    int i;
    for (i = 0; i < (int) ((h + 139.0 - 1.0) / 139.0); i++) {
        this->BoxImage[2]->Render(x - 82.0, y + (float) i * 139.0);
        this->BoxImage[2]->RenderEx(x + w + 82.0, y + (float) i * 139.0, 0.0, -1.0, 1.0);
    }
    for (i = 0; i < (int) ((w + 139.0 - 1.0) / 139.0); i++) {
        this->BoxImage[1]->Render(x + (float) i * 139.0, y - 82.0);
        this->BoxImage[1]->RenderEx(x + (float) i * 139.0, y + h + 82.0, 0.0, 1.0, -1.0);
    }
    this->BoxImage[0]->Render(x - 82.0, y - 82.0);
    this->BoxImage[0]->RenderEx(x + w + 82.0, y - 82.0, pi * 0.5, 1.0, 0.0);
    this->BoxImage[0]->RenderEx(x + w + 82.0, y + h + 82.0, pi, 1.0, 0.0);
    this->BoxImage[0]->RenderEx(x - 82.0, y + h + 82.0, pi * 1.5, 1.0, 0.0);
    ecGraphics *Graphics = ecGraphics::Instance();
    float fx = camera->CenterPos[0] - camera->ScreenHalfSize[0] / camera->Scale;
    float fx2 = x + w + 82.0;
    float fy = camera->CenterPos[1] - camera->ScreenHalfSize[1] / camera->Scale;
    float fy2 = y + h + 82.0;
    float fWidth = x - fx - 82.0;
    float fHeight = (camera->ScreenHalfSize[1] + camera->ScreenHalfSize[1]) / camera->Scale;
    if (fWidth > 0.0)
        Graphics->RenderRect(fx, fy, fWidth, fHeight, 0xFF000000);
    fWidth = camera->CenterPos[0] + camera->ScreenHalfSize[0] / camera->Scale - fx2;
    if (fWidth > 0.0)
        Graphics->RenderRect(fx2, fy, fWidth, fHeight, 0xFF000000);
    fWidth = (camera->ScreenHalfSize[0] + camera->ScreenHalfSize[0]) / camera->Scale;
    fHeight = y - fy - 82.0;
    if (fHeight > 0.0)
        Graphics->RenderRect(fx, fy, fWidth, fHeight, 0xFF000000);
    fHeight = camera->CenterPos[1] + camera->ScreenHalfSize[1] / camera->Scale - fy2;
    if (fHeight > 0.0)
        Graphics->RenderRect(fx, fy2, fWidth, fHeight, 0xFF000000);
}
