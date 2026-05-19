#include "Player.h"

#ifndef GAME_H
#define GAME_H
class Game {
private:
    int secretNumber;
    int difficulty;

public:
    // Constructor
    Game();

    void chooseDifficulty(int diff);
    void generateNumber();
    void Playround(Player &pl);
};
#endif /*GAME_H*/
