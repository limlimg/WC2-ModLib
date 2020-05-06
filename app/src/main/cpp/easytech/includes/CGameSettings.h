#ifndef EASYTECH_CGAMESETTINGS_H
#define EASYTECH_CGAMESETTINGS_H

#include "CCountry.h"

__BEGIN_DECLS

typedef signed char int8_t;

struct CGameSettings {
    int MusicVolume;
    int SEVolume;
    int Speed;
    bool BattleAnimation;
    int AlwaysZero;
    bool FullScreen;
};

void _ZN13CGameSettingsC1Ev(struct CGameSettings *self);

void _ZN13CGameSettingsC2Ev(struct CGameSettings *self);

void _ZN13CGameSettingsD1Ev(struct CGameSettings *self);

void _ZN13CGameSettingsD2Ev(struct CGameSettings *self);

void _ZN13CGameSettings12LoadSettingsEv(struct CGameSettings *self);

void _ZN13CGameSettings12SaveSettingsEv(struct CGameSettings *self);

extern struct CGameSettings g_GameSettings;

struct CommanderData;
struct CCommander {
    bool CanSave;
    int Level;
    int Medal;
    int BoughtMedal;
    int WarMedal[6];
    int CampaignProgress[4];
    int CampaignStar[4][20];
};

void _ZN10CCommanderC1Ev(struct CCommander *self);

void _ZN10CCommanderC2Ev(struct CCommander *self);

void _ZN10CCommanderD1Ev(struct CCommander *self);

void _ZN10CCommanderD2Ev(struct CCommander *self);

void _ZN10CCommander8BuyMedalEi(struct CCommander *self, int medal);

bool _ZN10CCommander12CheckUpgardeEv(struct CCommander *self);

bool _ZN10CCommander20CheckUpgradeWarMedalE11WARMEDAL_ID(struct CCommander *self, enum WARMEDAL_ID);

void
_ZN10CCommander16GetCommanderDataER13CommanderData(struct CCommander *self, struct CommanderData *);

int _ZN10CCommander19GetNeedUpgradeMedalE11WARMEDAL_ID(struct CCommander *self, enum WARMEDAL_ID);

int _ZN10CCommander17GetNumBattleStarsEii(struct CCommander *self, int SeriesID, int LevelID);

int _ZN10CCommander20GetNumPlayedBatttlesEi(struct CCommander *self, int CampaignSeriesID);

int _ZN10CCommander15GetUpgradeMedalEv(struct CCommander *self);

int _ZN10CCommander16GetWarMedalLevelE11WARMEDAL_ID(struct CCommander *self, enum WARMEDAL_ID);

bool _ZN10CCommander10IsMaxLevelEv(struct CCommander *self);

void _ZN10CCommander4LoadEv(struct CCommander *self);

void _ZN10CCommander4SaveEv(struct CCommander *self);

void _ZN10CCommander15SetBattlePlayedEii(struct CCommander *self, int SeriesID, int LevelID);

void _ZN10CCommander17SetNumBattleStarsEiii(struct CCommander *self, int SeriesID, int LevelID,
                                            int star);

void
_ZN10CCommander20SetNumPlayedBatttlesEii(struct CCommander *self, int CampaignSeriesID, int num);

void _ZN10CCommander7UpgradeEv(struct CCommander *self);

void _ZN10CCommander15UpgradeWarMedalE11WARMEDAL_ID(struct CCommander *self, enum WARMEDAL_ID);

extern struct CCommander g_Commander;

__END_DECLS

#endif //EASYTECH_CGAMESETTINGS_H
