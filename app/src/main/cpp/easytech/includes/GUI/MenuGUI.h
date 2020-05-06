#ifndef EASYTECH_MENUGUI_H
#define EASYTECH_MENUGUI_H

#include "GUIElement.h"

__BEGIN_DECLS

struct GUICountryItem {
    GUIElement_field;
    char name[16];
    char id[16];
    int RankStar;
    struct ecImage *Image_button;
    struct ecImage *Image_small_rankstar;
    bool Touched;
    bool Selected;
};

void _ZN14GUICountryItemC1Ev(struct GUICountryItem *self);

void _ZN14GUICountryItemC2Ev(struct GUICountryItem *self);

void _ZN14GUICountryItemD0Ev(struct GUICountryItem *self);

void _ZN14GUICountryItemD1Ev(struct GUICountryItem *self);

void _ZN14GUICountryItemD2Ev(struct GUICountryItem *self);

bool _ZN14GUICountryItem7OnEventERK5Event(struct GUICountryItem *self, const struct Event *);

void _ZN14GUICountryItem8OnRenderEv(struct GUICountryItem *self);

void _ZN14GUICountryItem8OnUpdateEf(struct GUICountryItem *self, float time);

void _ZN14GUICountryItem4InitEPKcS1_RK7GUIRect(struct GUICountryItem *self, const char *name,
                                               const char *id, const struct GUIRect *rect);

void _ZN14GUICountryItem11SetSelectedEb(struct GUICountryItem *self, bool selected);

__END_DECLS

#endif //EASYTECH_MENUGUI_H
