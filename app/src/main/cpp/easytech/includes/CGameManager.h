#ifndef EASYTECH_CGAMEMANAGER_H
#define EASYTECH_CGAMEMANAGER_H

#include "CObjectDef.h"
#include "cxxlist.h"
#include "cxxvector.h"

static const char DefaultCommander[] = "common3";

enum WARMEDAL_ID {
    InfantryMedal, AirForceMedal, ArtilleryMedal, ArmourMedal, NavyMedal, CommerceMedal
};

struct CountryAction {
    enum ActionType {
        NoAction,
        ArmyMoveAction,
        ArmyInactiveAction,
        ArmyAttackAction,
        ArmyMoveFrontAction,
        UseCardAction,
        CameraMoveAction
    } ActionType;
    enum CARD_ID CardID;
    int StartAreaID;
    int TargetAreaID;
    int ArmyIndex;
};

struct SaveCountryInfo;

struct CCountry {
    int Alliance;
    int DefeatType;
    list(int) AreaIDList;
    list(int) CapitalIDList;
    int Money;
    int Industry;
    float TaxRate;
    char ID[16];
    char Name[16];
    unsigned char R;
    unsigned char B;
    unsigned char G;
    unsigned char A;
    bool AI;
    bool Defeated;
    struct CountryAction CAction;
    float ActionTimer;
    float ActionDelayTime;
    bool ActionWaitCamera;
    int Tech;
    int TechTurn;
    int CardRound[28];
    list(int) AOECardTargetIDList;
    void *AOECardCurTargetID;
    int DestroyCount[10];
    struct CommanderDef *PvCommanderDef;
    int CommanderTurn;
    bool CommanderAlive;
    int WarMedal[6];
    bool BorrowedLoan;
    void *PvPlayer;
#ifdef __cplusplus
    static const int NeutralID = 4;

    void Init(const char *ID, const char *Name);

    void SaveCountry(SaveCountryInfo *);

    void LoadCountry(const SaveCountryInfo *);

    void Action(const CountryAction &);

    void AddArea(int AreaID);

    void AddDestroy(int ArmyType);

    float AirstrikeRadius();

    void BeConquestedBy(CCountry *);

    bool CanBuyCard(CardDef *);

    bool CanUseCommander();

    bool CheckCardTargetArea(CardDef *, int id);

    bool CheckCardTargetArmy(CardDef *, int AreaID, int ArmyIndex);

    void CollectIndustrys();

    void CollectTaxes();

    void CommanderDie();

    void DoAction();

    int FindAdjacentAreaID(int AreaID, bool HasArmy);

    int FindAdjacentLandAreaID(int AreaID, bool HasArmy);

    bool FindArea(int AreaID);

    void FinishAction();

    int GetCardIndustry(CardDef *);

    int GetCardPrice(CardDef *);

    int GetCardRounds(CARD_ID);

    int GetCommanderLevel();

    const char *GetCommanderName();

    int GetCurCardTarget();

    int GetFirstCapital();

    int GetHighestValueArea();

    int GetIndustrys();

    float GetMinDstToAirport(int AreaID);

    int GetNumAirport();

    int GetTaxes();

    int GetWarMedalLevel(WARMEDAL_ID);

    bool IsActionFinish();

    bool IsCardUnlock(CardDef *);

    bool IsConquested();

    bool IsEnoughIndustry(CardDef *);

    bool IsEnoughMoney(CardDef *);

    bool IsLocalPlayer();

    void NextCardTarget();

    void RemoveArea(int AreaID);

    void SetCardTargets(CardDef *);

    void SetCommander(const char *name);

    void SetWarMedalLevel(WARMEDAL_ID, int level);

    void TurnBegin();

    void TurnEnd();

    void Update(float time);

    void UseCard(CardDef *, int TargetAreaID, int ArmyIndex);

#endif
};

__BEGIN_DECLS
void _ZN8CCountryC1Ev(struct CCountry *self);

void _ZN8CCountryC2Ev(struct CCountry *self);

void _ZN8CCountryD1Ev(struct CCountry *self);

void _ZN8CCountryD2Ev(struct CCountry *self);

void _ZN8CCountry4InitEPKcS1_(struct CCountry *self, const char *ID, const char *Name);

void _ZN8CCountry11SaveCountryEP15SaveCountryInfo(struct CCountry *self, struct SaveCountryInfo *);

void _ZN8CCountry11LoadCountryEPK15SaveCountryInfo(struct CCountry *self,
                                                   const struct SaveCountryInfo *);

void _ZN8CCountry6ActionERK13CountryAction(struct CCountry *self, const struct CountryAction *);

void _ZN8CCountry7AddAreaEi(struct CCountry *self, int AreaID);

void _ZN8CCountry10AddDestroyEi(struct CCountry *self, int ArmyType);

float _ZN8CCountry15AirstrikeRadiusEv(struct CCountry *self);

void _ZN8CCountry14BeConquestedByEPS_(struct CCountry *self, struct CCountry *);

bool _ZN8CCountry10CanBuyCardEP7CardDef(struct CCountry *self, struct CardDef *);

bool _ZN8CCountry15CanUseCommanderEv(struct CCountry *self);

bool _ZN8CCountry19CheckCardTargetAreaEP7CardDefi(struct CCountry *self, struct CardDef *, int id);

bool
_ZN8CCountry19CheckCardTargetArmyEP7CardDefii(struct CCountry *self, struct CardDef *, int AreaID,
                                              int ArmyIndex);

void _ZN8CCountry16CollectIndustrysEv(struct CCountry *self);

void _ZN8CCountry12CollectTaxesEv(struct CCountry *self);

void _ZN8CCountry12CommanderDieEv(struct CCountry *self);

void _ZN8CCountry8DoActionEv(struct CCountry *self);

int _ZN8CCountry18FindAdjacentAreaIDEib(struct CCountry *self, int AreaID, bool HasArmy);

int _ZN8CCountry22FindAdjacentLandAreaIDEib(struct CCountry *self, int AreaID, bool HasArmy);

bool _ZN8CCountry8FindAreaEi(struct CCountry *self, int AreaID);

void _ZN8CCountry12FinishActionEv(struct CCountry *self);

int _ZN8CCountry15GetCardIndustryEP7CardDef(struct CCountry *self, struct CardDef *);

int _ZN8CCountry12GetCardPriceEP7CardDef(struct CCountry *self, struct CardDef *);

int _ZN8CCountry13GetCardRoundsE7CARD_ID(struct CCountry *self, enum CARD_ID);

int _ZN8CCountry17GetCommanderLevelEv(struct CCountry *self);

const char *_ZN8CCountry16GetCommanderNameEv(struct CCountry *self);

int _ZN8CCountry16GetCurCardTargetEv(struct CCountry *self);

int _ZN8CCountry15GetFirstCapitalEv(struct CCountry *self);

int _ZN8CCountry19GetHighestValueAreaEv(struct CCountry *self);

int _ZN8CCountry12GetIndustrysEv(struct CCountry *self);

float _ZN8CCountry18GetMinDstToAirportEi(struct CCountry *self, int AreaID);

int _ZN8CCountry13GetNumAirportEv(struct CCountry *self);

int _ZN8CCountry8GetTaxesEv(struct CCountry *self);

int _ZN8CCountry16GetWarMedalLevelE11WARMEDAL_ID(struct CCountry *self, enum WARMEDAL_ID);

bool _ZN8CCountry14IsActionFinishEv(struct CCountry *self);

bool _ZN8CCountry12IsCardUnlockEP7CardDef(struct CCountry *self, struct CardDef *);

bool _ZN8CCountry12IsConquestedEv(struct CCountry *self);

bool _ZN8CCountry16IsEnoughIndustryEP7CardDef(struct CCountry *self, struct CardDef *);

bool _ZN8CCountry13IsEnoughMoneyEP7CardDef(struct CCountry *self, struct CardDef *);

bool _ZN8CCountry13IsLocalPlayerEv(struct CCountry *self);

void _ZN8CCountry14NextCardTargetEv(struct CCountry *self);

void _ZN8CCountry10RemoveAreaEi(struct CCountry *self, int AreaID);

void _ZN8CCountry14SetCardTargetsEP7CardDef(struct CCountry *self, struct CardDef *);

void _ZN8CCountry12SetCommanderEPKc(struct CCountry *self, const char *name);

void
_ZN8CCountry16SetWarMedalLevelE11WARMEDAL_IDi(struct CCountry *self, enum WARMEDAL_ID, int level);

void _ZN8CCountry9TurnBeginEv(struct CCountry *self);

void _ZN8CCountry7TurnEndEv(struct CCountry *self);

void _ZN8CCountry6UpdateEf(struct CCountry *self, float time);

void _ZN8CCountry7UseCardEP7CardDefii(struct CCountry *self, struct CardDef *, int TargetAreaID,
                                      int ArmyIndex);

__END_DECLS

struct Belligerent {
    char id[8];
    char name[8];
    char commander[20];
    int alliance;
};

#ifdef __cplusplus

void GetBattleKeyName(int SeriesID, int LevelID, char *name);

#endif

__BEGIN_DECLS
void _Z16GetBattleKeyNameiiPc(int SeriesID, int LevelID, char *name);

__END_DECLS

struct DialogueDef {
    string Commander;
    int Index;
    int AtRound;
    bool Left;
};

struct SaveHeader;

struct CGameManager {
    vector(CCountry *) Country;
    vector(CCountry *) DefeatCountry;//List of countries that can be defeated
    vector(DialogueDef*) DialogueList;
    int CurrentCountryIndex;
    int CurrentDialogueIndex;
    int CurrentTurnNumMinusOne;
    int RandomRewardMedal;
    enum GameMode {
        Campaign = 1,
        Conquest,
        MultiPlayer = 4,
        Tutorial
    } GameMode;
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
#ifdef __cplusplus

    void BattleVictory();

    bool CheckAndSetResult();

    void ClearBattle();

    void EndTurn();

    struct CCountry *FindCountry(const char *ID);

    void GameUpdate(float time);

    struct CCountry *GetCountryByIndex(int index);

    struct CCountry *GetCurCountry();

    struct DialogueDef *GetCurDialogue();

    bool GetCurDialogueString(char *result);

    struct DialogueDef GetDialogueByIndex(int index);

    struct CCountry *GetLocalPlayerCountry();

    struct CCountry *GetNewDefeatedCountry();

    int GetNumCountries();

    int GetNumDialogues();

    int GetNumVictoryStars();

    struct CCountry *GetPlayerCountry();

    const char *GetPlayerCountryName(int index);

    int GetPlayerNo(const char *);

    void GetSaveHeader(const char *FileName, SaveHeader &);

    void InitBattle();

    void InitCameraPos();

    bool IsLastBattle();

    bool IsManipulate();

    void LoadBattle(const char *FileName);

    void LoadGame(const char *FileName);

    void MovePlayerCountryToFront();

    void NewGame(int GameMode, int, int CampaignSeriesID, int LevelID);

    void Next();

    void NextDialogue();

    void RealLoadGame(const char *filename);

    void Release();

    void RetryGame();

    void SaveBattle(const char *FileName);

    void SaveGame(const char *FileName);

    void SetConquestPlayerCountryID(const char *ID);

    void SetPlayercountryname(int index, const char *name);

    void TurnBegin();

    void TurnEnd();

#endif
};

__BEGIN_DECLS
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
