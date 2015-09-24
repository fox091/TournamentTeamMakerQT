#include "playerlist.h"
#include "player.h"
#include <QList>
#include <time.h>

PlayerList::PlayerList() {
    soloCount = 0;
    duoCount = 0;
    totalPlayers = 0;
}

int PlayerList::getTotalPlayers() {
    return totalPlayers;
}

void PlayerList::AddSolo(QString pName) {
    playerList.append(*(new Player(NULL, pName, 1)));
    soloCount++;
    totalPlayers++;
}

void PlayerList::AddDuo(QString pName, QString pName2) {
    Player* teammate = new Player(NULL, pName2, 0);
    playerList.append(*(new Player(teammate, pName, 2)));
    soloCount++;
    totalPlayers += 2;
}

void PlayerList::Shuffle(int teamSize) {
    srand(time(NULL));
    int n = playerList.size();
    int teamCount;
    bool runAgain;
    do {
        teamCount = 0;
        runAgain = false;
        while (n > 1)
        {
            n--;
            int k = rand() % n;
            Player tempPlayer = playerList[k];
            playerList[k] = playerList[n];
            playerList[n] = tempPlayer;
        }
        foreach (Player p, playerList)
        {
            if (!runAgain)
            {
                teamCount += p.getCount();
                if (teamCount == teamSize)
                    teamCount = 0;
                else if (teamCount > teamSize)
                    runAgain = true;
            }
        }
    } while (runAgain);
}

QList<Player> PlayerList::BuildTeams(int teamSize) {
    if (soloCount * (teamSize / 2) < duoCount)
        return *(new QList<Player>());
    Shuffle(teamSize);
    return ReAddTeammates();
}

QList<Player> PlayerList::ReAddTeammates() {
    QList<Player> tempList;
    foreach (Player p, playerList)
    {
        if (p.getTeammate() == NULL)
            tempList.append(p);
        else
        {
            tempList.append(p);
            tempList.append(*(p.getTeammate()));
        }
    }
    return tempList;
}
