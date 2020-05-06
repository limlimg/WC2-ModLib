#ifndef EASYTECH_CGAMEMANAGER_H
#define EASYTECH_CGAMEMANAGER_H

#include "CCountry.h"
#include "cxxvector.h"

__BEGIN_DECLS

#define DefaultCommander "common3"
#define NeutralID 4

struct Belligerent {
    char id[8];
    char name[8];
    char commander[20];
    int alliance;
};

void _Z16GetBattleKeyNameiiPc(int SeriesID, int LevelID, char *name);

struct DialogueDef {
    string Commander;
    int Index;
    int AtRound;
    bool Left;
};

struct SaveHeader;
#ifndef def_St6vector_P8CCountry
#define def_St6vector_P8CCountry
def__ZSt6vector(struct CCountry *, P8CCountry)

#endif
#ifndef def_St6vector_P11DialogueDef
#define def_St6vector_P11DialogueDef
def__ZSt6vector(struct DialogueDef*, P11DialogueDef)

#endif
struct CGameManager {
    _ZSt6vector(P8CCountry) Country;
    _ZSt6vector(P8CCountry) DefeatCountry;//List of countries that can be defeated
    _ZSt6vector(P11DialogueDef) DialogueList;
    int CurrentCountryIndex;
    int CurrentDialogueIndex;
    int CurrentTurnNumMinusOne;
    int RandomRewardMedal;
    int GameMode;
    int AlwaysZero;
    int MapID;
    char AreasEnable[32];
    char BattleFileName[32];
    char LoadFileName[16];
    char PlayerCountryName[8][4];
    char ConquestPlayerCountryID[8];
    bool IsNewGame;
    bool LocalHost;
    bool Result;
    bool ResultWin;
    bool SelectNextBattle;
    int CampaignSeriesID;
    int CampaignLevelID;
    int VictoryTurn;
    int GreatVictoryTurn;
    int CampaignRewardMedal;
};

void _ZN12CGameManagerC1Ev(struct CGameManager *self);

void _ZN12CGameManagerC2Ev(struct CGameManager *self);

void _ZN12CGameManagerD1Ev(struct CGameManager *self);

void _ZN12CGameManagerD2Ev(struct CGameManager *self);

void _ZN12CGameManager13BattleVictoryEv(struct CGameManager *self);

bool _ZN12CGameManager17CheckAndSetResultEv(struct CGameManager *self);

void _ZN12CGameManager11ClearBattleEv(struct CGameManager *self);

void _ZN12CGameManager7EndTurnEv(struct CGameManager *self);

struct CCountry *_ZN12CGameManager11FindCountryEPKc(struct CGameManager *self, const char *ID);

void _ZN12CGameManager10GameUpdateEf(struct CGameManager *self, float time);

struct CCountry *_ZN12CGameManager17GetCountryByIndexEi(struct CGameManager *self, int index);

struct CCountry *_ZN12CGameManager13GetCurCountryEv(struct CGameManager *self);

struct DialogueDef *_ZN12CGameManager14GetCurDialogueEv(struct CGameManager *self);

bool _ZN12CGameManager20GetCurDialogueStringEPc(struct CGameManager *self, char *result);

struct DialogueDef _ZN12CGameManager18GetDialogueByIndexEi(struct CGameManager *self, int index);

struct CCountry *_ZN12CGameManager21GetLocalPlayerCountryEv(struct CGameManager *self);

struct CCountry *_ZN12CGameManager21GetNewDefeatedCountryEv(struct CGameManager *self);

int _ZN12CGameManager15GetNumCountriesEv(struct CGameManager *self);

int _ZN12CGameManager15GetNumDialoguesEv(struct CGameManager *self);

int _ZN12CGameManager18GetNumVictoryStarsEv(struct CGameManager *self);

struct CCountry *_ZN12CGameManager16GetPlayerCountryEv(struct CGameManager *self);

const char *_ZN12CGameManager20GetPlayerCountryNameEi(struct CGameManager *self, int index);

int _ZN12CGameManager11GetPlayerNoEPKc(struct CGameManager *self, const char *);

void
_ZN12CGameManager13GetSaveHeaderEPKcR10SaveHeader(struct CGameManager *self, const char *FileName,
                                                  struct SaveHeader *);

void _ZN12CGameManager10InitBattleEv(struct CGameManager *self);

void _ZN12CGameManager13InitCameraPosEv(struct CGameManager *self);

bool _ZN12CGameManager12IsLastBattleEv(struct CGameManager *self);

bool _ZN12CGameManager12IsManipulateEv(struct CGameManager *self);

void _ZN12CGameManager10LoadBattleEPKc(struct CGameManager *self, const char *FileName);

void _ZN12CGameManager8LoadGameEPKc(struct CGameManager *self, const char *FileName);

void _ZN12CGameManager24MovePlayerCountryToFrontEv(struct CGameManager *self);

void
_ZN12CGameManager7NewGameEiiii(struct CGameManager *self, int GameMode, int, int CampaignSeriesID,
                               int LevelID);

void _ZN12CGameManager4NextEv(struct CGameManager *self);

void _ZN12CGameManager12NextDialogueEv(struct CGameManager *self);

void _ZN12CGameManager12RealLoadGameEPKc(struct CGameManager *self, const char *filename);

void _ZN12CGameManager7ReleaseEv(struct CGameManager *self);

void _ZN12CGameManager9RetryGameEv(struct CGameManager *self);

void _ZN12CGameManager10SaveBattleEPKc(struct CGameManager *self, const char *FileName);

void _ZN12CGameManager8SaveGameEPKc(struct CGameManager *self, const char *FileName);

void _ZN12CGameManager26SetConquestPlayerCountryIDEPKc(struct CGameManager *self, const char *ID);

void _ZN12CGameManager20SetPlayercountrynameEiPKc(struct CGameManager *self, int index,
                                                  const char *name);

void _ZN12CGameManager9TurnBeginEv(struct CGameManager *self);

void _ZN12CGameManager7TurnEndEv(struct CGameManager *self);

extern struct CGameManager g_GameManager;

__END_DECLS

#endif //EASYTECH_CGAMEMANAGER_H
