#ifndef EASYTECH_CGAMERES_H
#define EASYTECH_CGAMERES_H

#include "ecLibrary.h"

__BEGIN_DECLS

#ifndef def__ZSt3map_Ss_P7ecImage
#define def__ZSt3map_Ss_P7ecImage
def__ZSt3map(string, Ss, struct ecImage*, P7ecImage)

#endif
struct CGameRes {
    struct ecTextureRes TextureRes_army;
    struct ecImage *Image_carrier;
    _ZSt3map(Ss, P7ecImage) Image_soldier;
    _ZSt3map(Ss, P7ecImage) Image_panzer;
    _ZSt3map(Ss, P7ecImage) Image_cannon;
    _ZSt3map(Ss, P7ecImage) Image_rocketlauncher;
    _ZSt3map(Ss, P7ecImage) Image_tank;
    _ZSt3map(Ss, P7ecImage) Image_heavytank;
    struct ecImage *Image_army_ne[10];
    struct ecImage *Image_unitbase_green[4];
    struct ecImage *Image_unitbase_blue[4];
    struct ecImage *Image_unitbase_red[4];
    struct ecImage *Image_unitbase_grey[4];
    struct ecImage *Image_unitlevelmark[4];
    struct ecImage *Image_commander_level[5];
    struct ecImage *Image_medal;
    struct ecImage *Image_medal_light;
    _ZSt3map(Ss, P7ecImage) ImageCountryMedal;
    struct ecImage *Image_mark_carriers[6];
    struct ecImage *Image_maek_carriers_color[4];
    struct ecImage *Image_hpbar;
    struct ecImage *Image_hpbar_fill;
    struct ecImage *Image_movementmark[4];
    struct ecImage *Image_cardmark[3];
    struct ecImage *Image_arrow_green;
    struct ecImage *Image_arrow_yellow;
    struct ecImage *Image_arrow_red;
    struct ecImage *Image_arrow_blue;
    struct ecImage *Image_arrowshadow;
    _ZSt3map(Ss, P7ecImage) Image_flag;
    struct ecImage *Image_buildmark_installtion[4];
    struct ecImage *Image_buildmark_city[4];
    struct ecImage *Image_buildmark_factory[3];
    struct ecImage *Image_buildmark_airport;
    struct ecImage *Image_buildmark_port;
    struct ecTextureRes TextureRes_cardtex;
    struct ecImage *Image_card_shadow;
    struct ecImage *Image_card_common;
    struct ecImage *Image_card_research[5];
    struct ecTextureRes TextureRes_battlebg;
    struct ecTextureRes TextureRes_flag;
};

void _ZN8CGameResC1Ev(struct CGameRes *self);

void _ZN8CGameResC2Ev(struct CGameRes *self);

void _ZN8CGameResD1Ev(struct CGameRes *self);

void _ZN8CGameResD2Ev(struct CGameRes *self);

void _ZN8CGameRes4LoadEv(struct CGameRes *self);

void _ZN8CGameRes7ReleaseEv(struct CGameRes *self);

struct ecImage *
_ZN8CGameRes12GetArmyImageEPKcib(struct CGameRes *self, const char *CountryName, int ArmyType,
                                 bool Sea);

struct ecImageAttr *_ZN8CGameRes11GetBattleBGEPKc(struct CGameRes *self, const char *name);

struct ecImageAttr *_ZN8CGameRes12GetFlagImageEPKc(struct CGameRes *self, const char *name);

void
_ZN8CGameRes22RenderAICommanderMedalEiffPKci(struct CGameRes *self, int ArmyCount, float x, float y,
                                             const char *CountryName, int CommonType);

void
_ZN8CGameRes10RenderArmyEPKciiffimbf(struct CGameRes *self, const char *CountryName, int Alliance,
                                     int ArmyCount, float x, float y, int ArmyType,
                                     unsigned long Color, bool Sea, float Direction);

void _ZN8CGameRes12RenderArmyHPEffii(struct CGameRes *self, float x, float y, int HP, int MaxHP);

void _ZN8CGameRes14RenderArmyInfoEiffiiiii(struct CGameRes *self, int ArmyCount, float x, float y,
                                           int HP, int MaxHP, int Movement, int Cards, int Level);

void _ZN8CGameRes15RenderArmyLevelEffi(struct CGameRes *self, float x, float y, int Level);

void _ZN8CGameRes21RenderArmyMovementNumEffi(struct CGameRes *self, float x, float y, int Movement);

void _ZN8CGameRes20RenderCommanderMedalEiffi(struct CGameRes *self, int ArmyCount, float x, float y,
                                             int CommanderLevel);

void
_ZN8CGameRes18RenderConstructionEiiff(struct CGameRes *self, int Type, int Level, float x, float y);

void
_ZN8CGameRes10RenderFlagEPKcff(struct CGameRes *self, const char *CountryName, float x, float y);

void _ZN8CGameRes18RenderInstallationEiff(struct CGameRes *self, int Type, float x, float y);

void _ZN8CGameRes10RenderPortEff(struct CGameRes *self, float x, float y);

void
_ZN8CGameRes12RenderUIArmyEPKcffibiiiii(struct CGameRes *self, const char *CountryName, float x,
                                        float y, int ArmyType, bool Sea, int HP, int MaxHP,
                                        int Movement, int Cards, int Level);

void _ZN8CGameRes18RenderUIAttackArmyEPKcffiiiiiiib(struct CGameRes *self, const char *CountryName,
                                                    float x, float y, int ArmyType, int HP,
                                                    int MaxHP, int Movement, int Cards, int Level,
                                                    int CommonType, bool AI);

void _ZN8CGameRes18RenderUIDefendArmyEPKcffiiiiiiib(struct CGameRes *self, const char *CountryName,
                                                    float x, float y, int ArmyType, int HP,
                                                    int MaxHP, int Movement, int Cards, int Level,
                                                    int CommonType, bool AI);

extern struct CGameRes g_GameRes;

static inline unsigned long HpColor(int HP, int MaxHP) {
    int r, g, b;
    if (HP * 2 <= MaxHP) {
        r = 0;
        g = 255 - 255 * (MaxHP - 2 * HP) / MaxHP;
        b = 255;
    } else {
        g = 255;
        b = 255 - 255 * (2 * HP - MaxHP) / MaxHP;
        r = 128 - (b >> 1);
    }
    return b + (g << 8) + (r << 16) - 0x1000000ul;
}

__END_DECLS

#endif //EASYTECH_CGAMERES_H
