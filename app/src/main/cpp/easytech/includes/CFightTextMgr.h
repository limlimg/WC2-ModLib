//CFightTextMgr.h

#ifndef EASYTECH_CFIGHTTEXTMGR_H
#define EASYTECH_CFIGHTTEXTMGR_H

#include "ecLibrary.h"

__BEGIN_DECLS

struct CFightText;
#ifndef def__ZSt4list_P10CFightText
#define def__ZSt4list_P10CFightText
def__ZSt4list(struct CFightText*, P10CFightText)

#endif
#ifndef def__Z9TFreeList_10CFightText
#define def__Z9TFreeList_10CFightText
def__Z9TFreeList(struct CFightText, 10CFightText)
#endif
struct CFightTextMgr {
    _ZSt4list(P10CFightText) ExistingText;
    _Z9TFreeList(10CFightText) AvailableText;
    struct ecUniFont Font;
};

void _ZN13CFightTextMgrC1Ev(struct CFightTextMgr *self);

void _ZN13CFightTextMgrC2Ev(struct CFightTextMgr *self);

void _ZN13CFightTextMgrD1Ev(struct CFightTextMgr *self);

void _ZN13CFightTextMgrD2Ev(struct CFightTextMgr *self);

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
//End of File CFightTextMgr.h