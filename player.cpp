#include "player.h"
#include <QString>

Player::Player(Player* team, QString pName, int pCount) {
    teammate = team;
    name = pName;
    count = pCount;
}
Player* Player::getTeammate() {
    return teammate;
}
QString Player::getName() {
    return name;
}
int Player::getCount() {
    return count;
}
