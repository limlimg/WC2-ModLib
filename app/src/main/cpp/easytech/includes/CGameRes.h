#ifndef EASYTECH_CGAMERES_H
#define EASYTECH_CGAMERES_H

#include "ecLibrary.h"

struct CGameRes {
    struct ecTextureRes TextureRes_army;
    struct ecImage *Image_carrier;
    map(string, ecImage*) Image_soldier;
    map(string, ecImage*) Image_panzer;
    map(string, ecImage*) Image_cannon;
    map(string, ecImage*) Image_rocketlauncher;
    map(string, ecImage*) Image_tank;
    map(string, ecImage*) Image_heavytank;
    struct ecImage *Image_army_ne[10];
    struct ecImage *Image_unitbase_green[4];
    struct ecImage *Image_unitbase_blue[4];
    struct ecImage *Image_unitbase_red[4];
    struct ecImage *Image_unitbase_grey[4];
    struct ecImage *Image_unitlevelmark[4];
    struct ecImage *Image_commander_level[5];
    struct ecImage *Image_medal;
    struct ecImage *Image_medal_light;
    map(string, ecImage*) ImageCountryMedal;
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
    map(string, ecImage*) Image_flag;
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
#ifdef __cplusplus

    void Load();

    void Release();

    ecImage *GetArmyImage(const char *CountryName, int ArmyType, bool Sea);

    ecImageAttr *GetBattleBG(const char *name);

    ecImageAttr *GetFlagImage(const char *name);

    void RenderAICommanderMedal(int ArmyCount, float x, float y, const char *CountryName,
                                int CommonType);

    void
    RenderArmy(const char *CountryName, int Alliance, int ArmyCount, float x, float y, int ArmyType,
               unsigned long Color, bool Sea, float Direction);

    void RenderArmyHP(float x, float y, int HP, int MaxHP);

    void RenderArmyInfo(int ArmyCount, float x, float y, int HP, int MaxHP, int Movement, int Cards,
                        int Level);

    void RenderArmyLevel(float x, float y, int Level);

    void RenderArmyMovementNum(float x, float y, int Movement);

    void RenderCommanderMedal(int ArmyCount, float x, float y, int CommanderLevel);

    void RenderConstruction(int Type, int Level, float x, float y);

    void RenderFlag(const char *CountryName, float x, float y);

    void RenderInstallation(int Type, float x, float y);

    void RenderPort(float x, float y);

    void RenderUIArmy(const char *CountryName, float x, float y, int ArmyType, bool Sea, int HP,
                      int MaxHP, int Movement, int Cards, int Level);

    void
    RenderUIAttackArmy(const char *CountryName, float x, float y, int ArmyType, int HP, int MaxHP,
                       int Movement, int Cards, int Level, int CommonType, bool AI);

    void
    RenderUIDefendArmy(const char *CountryName, float x, float y, int ArmyType, int HP, int MaxHP,
                       int Movement, int Cards, int Level, int CommonType, bool AI);

#ifdef extends_CGameRes

    extends_CGameRes

#endif
#endif
};

__BEGIN_DECLS
void _ZN8CGameResC1Ev(struct CGameRes *self);

void _ZN8CGameResD1Ev(struct CGameRes *self);

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
__END_DECLS

#endif //EASYTECH_CGAMERES_H
