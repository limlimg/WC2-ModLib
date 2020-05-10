//Allow to automatically decide the number of battle in a series
//Allow the game to save up to 80 campaign rankings per series

#include "CGameSettings.h"
#include "CGameManager.h"

int GetNumBattles(int SeriesID) {
    int i = 0;
    char key[32];
    GetBattleKeyName(SeriesID, i, key);
    while (CObjectDef::Instance()->GetBattleDef(key) != NULL) {
        i++;
        GetBattleKeyName(SeriesID, i, key);
    }
    return i;
}

int CCommander::GetNumBattleStars(int SeriesID, int LevelID) {
    if (SeriesID >= 4 || LevelID >= 80)
        return 0;
    return ((int8_t *) this->CampaignStar[SeriesID])[LevelID];
}

void CCommander::SetNumBattleStars(int SeriesID, int LevelID, int star) {
    if (SeriesID < 4 || LevelID < 80)
        ((int8_t *) this->CampaignStar[SeriesID])[LevelID] = (int8_t) star;
}

//Allow to change the numbers of medals awarded for winning a campaign
//If you win a campaign a second time with a higher ranking, you will get the missed reward
void CGameManager::BattleVictory() {
    if (this->GameMode != CGameManager::Campaign || this->CampaignLevelID >= 80)
        return;
    int star = this->GetNumVictoryStars();
    if (star <= 0)
        return;
    g_Commander.SetBattlePlayed(this->CampaignSeriesID, this->CampaignLevelID);
    const int MedalReward[] = {0, 0, 5, 15, 25, 50};
    int last_star = g_Commander.GetNumBattleStars(this->CampaignSeriesID, this->CampaignLevelID);
    if (last_star >= star)
        return;
    this->CampaignRewardMedal = MedalReward[star] - MedalReward[last_star];
    g_Commander.Medal += this->CampaignRewardMedal;
    g_Commander.SetNumBattleStars(this->CampaignSeriesID, this->CampaignLevelID, star);
}
