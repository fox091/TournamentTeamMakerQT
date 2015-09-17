#ifndef PLAYER_H
#define PLAYER_H
#include <string.h>
#include <QString>

class Player {
public:
    Player(Player* team, QString, int pCount);
    Player* getTeammate();
    int getCount();
    QString getName();

private:
    Player* teammate;
    int count;
    QString name;
};

#endif // PLAYER_H
