#ifndef EASYTECH_CGAMESETTINGS_H
#define EASYTECH_CGAMESETTINGS_H

#include "CGameManager.h"

struct CGameSettings {
    int MusicVolume;
    int SEVolume;
    int Speed;
    bool BattleAnimation;
    int AlwaysZero;
    bool FullScreen;
#ifdef __cplusplus

    void LoadSettings();

    void SaveSettings();

#ifdef extends_CGameSettings
    extends_CGameSettings
#endif
#endif
};

__BEGIN_DECLS
void _ZN13CGameSettingsC1Ev(struct CGameSettings *self);

void _ZN13CGameSettingsD1Ev(struct CGameSettings *self);

void _ZN13CGameSettings12LoadSettingsEv(struct CGameSettings *self);

void _ZN13CGameSettings12SaveSettingsEv(struct CGameSettings *self);

extern struct CGameSettings g_GameSettings;
__END_DECLS

struct CommanderData;

struct CCommander {
    bool CanSave;
    int Level;
    int Medal;
    int BoughtMedal;
    int WarMedal[6];
    int CampaignProgress[4];
    int CampaignStar[4][20];
#ifdef __cplusplus

    void BuyMedal(int medal);

    bool CheckUpgarde();

    bool CheckUpgradeWarMedal(WARMEDAL_ID);

    void GetCommanderData(CommanderData &);

    int GetNeedUpgradeMedal(WARMEDAL_ID);

    int GetNumBattleStars(int SeriesID, int LevelID);

    int GetNumPlayedBatttles(int CampaignSeriesID);

    int GetUpgradeMedal();

    int GetWarMedalLevel(WARMEDAL_ID);

    bool IsMaxLevel();

    void Load();

    void Save();

    void SetBattlePlayed(int SeriesID, int LevelID);

    void SetNumBattleStars(int SeriesID, int LevelID, int star);

    void SetNumPlayedBatttles(int CampaignSeriesID, int num);

    void Upgrade();

    void UpgradeWarMedal(WARMEDAL_ID);

#ifdef extends_CCommander
    extends_CCommander
#endif
#endif
};

__BEGIN_DECLS
void _ZN10CCommanderC1Ev(struct CCommander *self);

void _ZN10CCommanderD1Ev(struct CCommander *self);

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
