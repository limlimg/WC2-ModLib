#ifndef EASYTECH_CFIGHTTEXTMGR_H
#define EASYTECH_CFIGHTTEXTMGR_H

#include "ecLibrary.h"

struct CFightText;

struct CFightTextMgr {
    list(CFightText*) ExistingText;
    TFreeList(CFightText) AvailableText;
    struct ecUniFont Font;
#ifdef __cplusplus

    void Init();

    void Release();

    void AddText(float x, float y, const char *text, color_t);

    void Render();

    void Update(float time);

#ifdef extends_CFightTextMgr
    extends_CFightTextMgr
#endif
#endif
};

__BEGIN_DECLS
void _ZN13CFightTextMgrC1Ev(struct CFightTextMgr *self);

void _ZN13CFightTextMgrD1Ev(struct CFightTextMgr *self);

void _ZN13CFightTextMgr4InitEv(struct CFightTextMgr *self);

void _ZN13CFightTextMgr7ReleaseEv(struct CFightTextMgr *self);

void
_ZN13CFightTextMgr7AddTextEffPKcm(struct CFightTextMgr *self, float x, float y, const char *text,
                                  color_t);

void _ZN13CFightTextMgr6RenderEv(struct CFightTextMgr *self);

void _ZN13CFightTextMgr6UpdateEf(struct CFightTextMgr *self, float time);

extern struct CFightTextMgr g_FightTextMgr;
__END_DECLS

#endif //EASYTECH_CFIGHTTEXTMGR_H
