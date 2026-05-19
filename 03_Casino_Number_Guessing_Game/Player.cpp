#include <stdio.h>
#include "Player.h"

// Constructor
Player::Player(string name, float initMoney) {
    playerName = name;
    currentMoney = initMoney;
    wins = 0;
    losses = 0;
    printf("The player %s has entered the casino with %.2f€\n", playerName.c_str(), currentMoney);
}

void Player::displayStats() {
    printf("Stats of %s:\n", playerName.c_str());
    printf("Current money: %.2f€\n", currentMoney);
    printf("%i wins of %i times played.\n", wins, (wins+losses));
    return;
}
