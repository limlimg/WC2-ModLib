//Zooming the camera without limit

#include <math.h>
#include <stdbool.h>
#include "CScene.h"
#include "CGameSettings.h"

const float pi = 3.141592653589793238462643383279502884197939937;

//Infinite zoom
void _ZN7CCamera14SetPosAndScaleEfff(struct CCamera *self, float x, float y, float scale) {
    float fWidth = (self->ScreenHalfSize[0] + self->ScreenHalfSize[0]) / self->MapSize[0];
    float fMinScale = (self->ScreenHalfSize[1] + self->ScreenHalfSize[1]) / self->MapSize[1];
    if (fMinScale > fWidth)
        fMinScale = fWidth;
    if (scale < fMinScale)
        scale = fMinScale;
    if (scale > 1.0)
        scale = 1.0;
    self->Scale = scale;
    _ZN7CCamera6SetPosEffb(self, x, y, true);
}

//focus the camera on the middle when the view is bigger that the map
bool _ZN7CCamera6SetPosEffb(struct CCamera *self, float x, float y, const bool border) {
    self->CenterPos[0] = x;
    self->CenterPos[1] = y;
    int i;
    bool bFixed = false;
    for (i = 0; i < 2; i++) {
        float fMinPos = self->TopLeftPos[i];
        float fMaxPos = fMinPos + self->MapSize[i];
        if (border) {
            float fMinDistance = self->ScreenHalfSize[i] / self->Scale;
            fMinPos += fMinDistance;
            fMaxPos -= fMinDistance;
        }
        float fCenterPos = self->CenterPos[i];
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
            self->CenterPos[i] = fCenterPos;
    }
    return bFixed;
}

bool _ZN7CCamera4MoveEffb(struct CCamera *self, float x, float y, bool border) {
    return _ZN7CCamera6SetPosEffb(self, self->CenterPos[0] + x / self->Scale,
                                  self->CenterPos[1] + y / self->Scale, border);
}

void _ZN7CCamera13SetAutoFixPosEb(struct CCamera *self, bool enabled) {
    self->AutoFixPos = enabled;
    if (enabled) {
        int i;
        for (i = 0; i < 2; i++) {
            float MinDistance = self->ScreenHalfSize[i] / self->Scale;
            float MinPos = self->TopLeftPos[i] + MinDistance;
            float MaxPos = self->TopLeftPos[i] + self->MapSize[i] - MinDistance;
            float TargetPos = self->CenterPos[i];
            if (TargetPos < MinPos)
                TargetPos = MinPos;
            if (TargetPos > MaxPos)
                TargetPos = MaxPos;
            if (MinPos > MaxPos)
                TargetPos = (MinPos + MaxPos) * 0.5;
            float distance = TargetPos - self->CenterPos[i];
            if (fabs(distance) > 1.0) {
                self->TargetPos[i] = TargetPos;
                self->Speed[i] = distance * 0.1;
                self->IsMoving = true;
            } else {
                self->Speed[i] = 0.0;
                self->CenterPos[i] = TargetPos;
            }
        }
    } else {
        self->Speed[0] = 0.0;
        self->Speed[1] = 0.0;
    }
}

void _ZN7CCamera6MoveToEffb(struct CCamera *self, float x, float y, bool border) {
    const float SetSpeed[5] = {0.012, 0.015, 0.02, 0.026, 0.034};
    self->TargetPos[0] = x;
    self->TargetPos[1] = y;
    int i;
    for (i = 0; i < 2; i++) {
        float fMinPos = self->TopLeftPos[i];
        float fMaxPos = fMinPos + self->MapSize[i];
        if (border) {
            float fMinDistance = self->ScreenHalfSize[i] / self->Scale;
            fMinPos += fMinDistance;
            fMaxPos -= fMinDistance;
        }
        float fTargetPos = self->TargetPos[i];
        if (fTargetPos < fMinPos)
            fTargetPos = fMinPos;
        if (fTargetPos > fMaxPos)
            fTargetPos = fMaxPos;
        if (fMinPos > fMaxPos)
            fTargetPos = (fMinPos + fMaxPos) * 0.5;
        float fStep = fTargetPos - self->CenterPos[i];
        if (fabs(fStep) > 1.0) {
            self->TargetPos[i] = fTargetPos;
            self->Speed[i] = fStep * SetSpeed[g_GameSettings.Speed];
            self->IsMoving = true;
        } else {
            self->Speed[i] = 0.0;
            self->CenterPos[i] = fTargetPos;
        }
    }
}

//Hide map showing beyond border
void
_ZN11CBackground9RenderBoxEP7CCameraffff(struct CBackground *self, struct CCamera *camera, float x,
                                         float y, float w, float h) {
    int i;
    for (i = 0; i < (int) ((h + 139.0 - 1.0) / 139.0); i++) {
        _ZN7ecImage6RenderEff(self->BoxImage[2], x - 82.0, y + (float) i * 139.0);
        _ZN7ecImage8RenderExEfffff(self->BoxImage[2], x + w + 82.0, y + (float) i * 139.0, 0.0,
                                   -1.0, 1.0);
    }
    for (i = 0; i < (int) ((w + 139.0 - 1.0) / 139.0); i++) {
        _ZN7ecImage6RenderEff(self->BoxImage[1], x + (float) i * 139.0, y - 82.0);
        _ZN7ecImage8RenderExEfffff(self->BoxImage[1], x + (float) i * 139.0, y + h + 82.0, 0.0, 1.0,
                                   -1.0);
    }
    _ZN7ecImage6RenderEff(self->BoxImage[0], x - 82.0, y - 82.0);
    _ZN7ecImage8RenderExEfffff(self->BoxImage[0], x + w + 82.0, y - 82.0, pi * 0.5, 1.0, 0.0);
    _ZN7ecImage8RenderExEfffff(self->BoxImage[0], x + w + 82.0, y + h + 82.0, pi, 1.0, 0.0);
    _ZN7ecImage8RenderExEfffff(self->BoxImage[0], x - 82.0, y + h + 82.0, pi * 1.5, 1.0, 0.0);
    struct ecGraphics *Graphics = _ZN10ecGraphics8InstanceEv();
    float fx = camera->CenterPos[0] - camera->ScreenHalfSize[0] / camera->Scale;
    float fx2 = x + w + 82.0;
    float fy = camera->CenterPos[1] - camera->ScreenHalfSize[1] / camera->Scale;
    float fy2 = y + h + 82.0;
    float fWidth = x - fx - 82.0;
    float fHeight = (camera->ScreenHalfSize[1] + camera->ScreenHalfSize[1]) / camera->Scale;
    if (fWidth > 0.0)
        _ZN10ecGraphics10RenderRectEffffm(Graphics, fx, fy, fWidth, fHeight, 0xFF000000);
    fWidth = camera->CenterPos[0] + camera->ScreenHalfSize[0] / camera->Scale - fx2;
    if (fWidth > 0.0)
        _ZN10ecGraphics10RenderRectEffffm(Graphics, fx2, fy, fWidth, fHeight, 0xFF000000);
    fWidth = (camera->ScreenHalfSize[0] + camera->ScreenHalfSize[0]) / camera->Scale;
    fHeight = y - fy - 82.0;
    if (fHeight > 0.0)
        _ZN10ecGraphics10RenderRectEffffm(Graphics, fx, fy, fWidth, fHeight, 0xFF000000);
    fHeight = camera->CenterPos[1] + camera->ScreenHalfSize[1] / camera->Scale - fy2;
    if (fHeight > 0.0)
        _ZN10ecGraphics10RenderRectEffffm(Graphics, fx, fy2, fWidth, fHeight, 0xFF000000);
}
