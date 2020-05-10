//For conquests, countries with ai="0" are available
//If no country is available in this way, then non-neutral countries are available
//The picture of country button will use its id. If the corresponding picture isn't found, its name is used

#include "cxxlist.h"
#include "CGameManager.h"
#include "GUI/MenuGUI.h"
#include <cstring>

/* TODO: fix TinyXml issue
void GetBattleBelligerentList(const char *FileName, std::list<Belligerent> &result, bool IgnoreAI) {
    Belligerent test = {"de", "de", "common3", 1};
    result.push_back(test);
    TiXmlDocument xml(GetPath(FileName, NULL));
    if (!xml.LoadFile())
        //return;
    result.push_back(test);
    TiXmlNode *battle = xml.FirstChild("battle");
    if (battle == NULL)
        return;
    result.push_back(test);
    TiXmlElement *list;
    bool CountryFound = false;
    bool UseAlliance = false;
        for (list = battle->FirstChildElement(); list != NULL; list = list->NextSiblingElement()) {
        const char *name;
        name = list->Attribute("name");
        if (name == NULL || strcmp(name, "country") != 0)
            continue;
        do {
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
                        item.alliance = CCountry::NeutralID;
                    else
                        switch (alliance[0]) {
                            case 'a':
                                item.alliance = 1;
                                break;
                            case 'b':
                                item.alliance = 2;
                                break;
                            case 'c':
                                item.alliance = 3;
                                break;
                            default:
                                item.alliance = CCountry::NeutralID;
                        }
                    result.push_back(item);
                    CountryFound = true;
                }
            }
            if (UseAlliance)
                return;
            UseAlliance = true;
        } while (!CountryFound);
        return;
    }
}*/

void GUICountryItem::Init(const char *name, const char *id, const GUIRect &rect) {
    this->Rect = rect;
    strncpy(this->name, name, sizeof(this->name) - 1);
    strncpy(this->id, id, sizeof(this->id) - 1);
    char ButtonName[32];
    sprintf(ButtonName, "button_%s.png", id);
    ecImageAttr *imageAttr = _ZN10GUIElement12s_TextureResE.GetImage(ButtonName);
    if (imageAttr == NULL) {
        sprintf(ButtonName, "button_%s.png", name);
        imageAttr = _ZN10GUIElement12s_TextureResE.GetImage(ButtonName);
    }
    this->Image_button = new ecImage;
    _ZN7ecImageC1EP11ecImageAttr(this->Image_button, imageAttr);
    imageAttr = _ZN10GUIElement12s_TextureResE.GetImage("small_rankstar.png");
    this->Image_small_rankstar = new ecImage;
    _ZN7ecImageC1EP11ecImageAttr(this->Image_small_rankstar, imageAttr);
    this->Touched = false;
    this->Selected = false;
    this->RankStar = 0;
}
