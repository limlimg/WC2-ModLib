//For conquests, countries with ai="0" are available
//If no country is available in this way, then non-neutral countries are available
//The picture of country button will use its id. If the corresponding picture isn't found, its name is used

#include "cxxlist.h"
#include "CGameManager.h"
#include "GUI/MenuGUI.h"
#include "tinyxml.h"
#include <cstring>

__BEGIN_DECLS

def__ZSt4list(Belligerent, 11Belligerent)
void
GetBattleBelligerentList(const char *FileName, _ZSt4list(11Belligerent) &result, bool IgnoreAI) {
    TiXmlDocument xml(_Z7GetPathPKcS0_(FileName, NULL));
    if (!xml.LoadFile())
        return;
    TiXmlNode *battle = xml.FirstChild("battle");
    if (battle == NULL)
        return;
    TiXmlElement *list;
    bool CountryFound = false;
    bool UseAlliance = false;
    do {
        for (list = battle->FirstChildElement(); list != NULL; list = list->NextSiblingElement()) {
            const char *name;
            name = list->Attribute("name");
            if (name == NULL || strcmp(name, "country") != 0)
                continue;
            TiXmlElement *country;
            for (country = list->FirstChildElement();
                 country != NULL; country = country->NextSiblingElement()) {
                bool InvolveCountry;
                const char *alliance = country->Attribute("alliance");
                if (UseAlliance) {
                    InvolveCountry = (alliance != NULL && strcmp(alliance, "n") != 0);
                } else {
                    int ai = 0;
                    country->QueryIntAttribute("ai", &ai);
                    InvolveCountry = (ai == 0);
                }
                if (InvolveCountry) {
                    Belligerent item;
                    strncpy(item.name, country->Attribute("name"), sizeof(item.name) - 1);
                    strncpy(item.id, country->Attribute("id"), sizeof(item.id) - 1);
                    const char *commander = country->Attribute("commander");
                    if (commander != NULL)
                        strncpy(item.commander, commander, sizeof(item.commander) - 1);
                    else
                        strncpy(item.commander, DefaultCommander, sizeof(item.commander) - 1);
                    if (alliance == NULL || strcmp(alliance, "n") == 0)
                        item.alliance = NeutralID;
                    else
                        item.alliance = alliance[0] - 'a' + 1;
                    _ZNSt4list9push_backE(11Belligerent)(&result, item);
                    CountryFound = true;
                }
            }
        }
        if (UseAlliance) {
            if (!CountryFound)
                return;
            else
                break;
        }
        UseAlliance = true;
    } while (!CountryFound);
}

void _ZN14GUICountryItem4InitEPKcS1_RK7GUIRect(struct GUICountryItem *self, const char *name,
                                               const char *id, const struct GUIRect *rect) {
    self->Rect.Pos[0] = rect->Pos[0];
    self->Rect.Pos[1] = rect->Pos[1];
    self->Rect.Size[0] = rect->Size[0];
    self->Rect.Size[1] = rect->Size[1];
    strncpy(self->name, name, sizeof(self->name) - 1);
    strncpy(self->id, id, sizeof(self->id) - 1);
    char ButtonName[32];
    sprintf(ButtonName, "button_%s.png", id);
    ecImageAttr *imageAttr = _ZN12ecTextureRes8GetImageEPKc(&_ZN10GUIElement12s_TextureResE,
                                                            ButtonName);
    if (imageAttr == NULL) {
        sprintf(ButtonName, "button_%s.png", name);
        imageAttr = _ZN12ecTextureRes8GetImageEPKc(&_ZN10GUIElement12s_TextureResE, ButtonName);
    }
    self->Image_button = new ecImage;
    _ZN7ecImageC1EP11ecImageAttr(self->Image_button, imageAttr);
    imageAttr = _ZN12ecTextureRes8GetImageEPKc(&_ZN10GUIElement12s_TextureResE,
                                               "small_rankstar.png");
    self->Image_small_rankstar = new ecImage;
    _ZN7ecImageC1EP11ecImageAttr(self->Image_small_rankstar, imageAttr);
    self->Touched = false;
    self->Selected = false;
    self->RankStar = 0;
}

__END_DECLS
