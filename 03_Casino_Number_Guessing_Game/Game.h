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

    void setDifficulty(int diff);
    void generateNumber();
    bool Playround(Player &pl, double playerBet, int playerGuess);
};
#endif /*GAME_H*/
