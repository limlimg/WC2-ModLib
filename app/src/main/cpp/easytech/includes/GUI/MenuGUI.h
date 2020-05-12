#ifndef EASYTECH_MENUGUI_H
#define EASYTECH_MENUGUI_H

#include "GUIElement.h"

__sub_struct(GUICountryItem, GUIElement)
    char name[16];
    char id[16];
    int RankStar;
    struct ecImage *Image_button;
    struct ecImage *Image_small_rankstar;
    bool Touched;
    bool Selected;
#ifdef __cplusplus

    bool OnEvent(const Event &);

    void OnRender();

    void OnUpdate(float time);

    void Init(const char *name, const char *id, const GUIRect &rect);

    void SetSelected(bool selected);

#ifdef extends_GUICountryItem
    extends_GUICountryItem
#endif
#endif
__end_struct

__BEGIN_DECLS
void _ZN14GUICountryItemC1Ev(struct GUICountryItem *self);

void _ZN14GUICountryItemD1Ev(struct GUICountryItem *self);

bool _ZN14GUICountryItem7OnEventERK5Event(struct GUICountryItem *self, const struct Event *);

void _ZN14GUICountryItem8OnRenderEv(struct GUICountryItem *self);

void _ZN14GUICountryItem8OnUpdateEf(struct GUICountryItem *self, float time);

void _ZN14GUICountryItem4InitEPKcS1_RK7GUIRect(struct GUICountryItem *self, const char *name,
                                               const char *id, const struct GUIRect *rect);

void _ZN14GUICountryItem11SetSelectedEb(struct GUICountryItem *self, bool selected);

__END_DECLS

#endif //EASYTECH_MENUGUI_H
