//Allow to automatically decide the number of battle in a series
//Allow the game to save up to 80 campaign rankings per series

#include <stdint.h>
#include "CGameSettings.h"
#include "CGameManager.h"

int _Z13GetNumBattlesi(int SeriesID) {
    int i = 0;
    char key[32];
    _Z16GetBattleKeyNameiiPc(SeriesID, i, key);
    while (_ZN10CObjectDef12GetBattleDefEPKc(_ZN10CObjectDef8InstanceEv(), key) != NULL) {
        i++;
        _Z16GetBattleKeyNameiiPc(SeriesID, i, key);
    }
    return i;
}

int _ZN10CCommander17GetNumBattleStarsEii(struct CCommander *self, int SeriesID, int LevelID) {
    if (SeriesID >= 4 || LevelID >= 80)
        return 0;
    return ((int8_t *) self->CampaignStar[SeriesID])[LevelID];
}

void _ZN10CCommander17SetNumBattleStarsEiii(struct CCommander *self, int SeriesID, int LevelID,
                                            int star) {
    if (SeriesID < 4 || LevelID < 80)
        ((int8_t *) self->CampaignStar[SeriesID])[LevelID] = (int8_t) star;
}

//Allow to change the numbers of medals awarded for winning a campaign
//If you win a campaign a second time with a higher ranking, you will get the missed reward
void _ZN12CGameManager13BattleVictoryEv(struct CGameManager *self) {
    if (self->GameMode != 1 || self->CampaignLevelID >= 80)
        return;
    int star = _ZN12CGameManager18GetNumVictoryStarsEv(self);
    if (star <= 0)
        return;
    _ZN10CCommander15SetBattlePlayedEii(&g_Commander, self->CampaignSeriesID,
                                        self->CampaignLevelID);
    const int MedalReward[] = {0, 0, 5, 15, 25, 50};
    int last_star = _ZN10CCommander17GetNumBattleStarsEii(&g_Commander, self->CampaignSeriesID,
                                                          self->CampaignLevelID);
    if (last_star >= star)
        return;
    self->CampaignRewardMedal = MedalReward[star] - MedalReward[last_star];
    g_Commander.Medal += self->CampaignRewardMedal;
    _ZN10CCommander17SetNumBattleStarsEiii(&g_Commander, self->CampaignSeriesID,
                                           self->CampaignLevelID, star);
}
