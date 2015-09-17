#ifndef PLAYERLIST_H
#define PLAYERLIST_H
#include <QList>
#include <QString>
#include "player.h"


class PlayerList {
public:
    PlayerList();
    void AddSolo(QString pName);
    void AddDuo(QString pName, QString pName2);
    QList<Player> BuildTeams(int teamSize);

private:
    QList<Player> playerList;
    int soloCount;
    int duoCount;
    void Shuffle(int teamSize);
    QList<Player> ReAddTeammates();
};

#endif // PLAYERLIST_H
