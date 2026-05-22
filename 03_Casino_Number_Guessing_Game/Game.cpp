#include <stdio.h>
#include <vector>
#include <random>
#include <iostream>
using namespace std;

#include "Game.h"

// Constructor
Game::Game(){
    secretNumber = 0;
    difficulty = 2;
}

void Game::setDifficulty(int diff) {
    switch (diff) {
        case 0:
            difficulty = 0;
            break;
        case 1:
            difficulty = 1;
            break;
        case 2:
            difficulty = 2;
            break;
        case 3:
            difficulty = 3;
            break;

        default:
            printf("UNVALID DIFFICULTY!\n The only allowed difficulties are:\n\t0 - easy \n\t1 - medium \n\t2 - hard \n\t 3 - extreme\n");
            break;
    }
}

void Game::generateNumber() {
    vector<int> guessingRanges = {5, 10, 50, 100}; // Range of guessing depending on difficulty
    
    // Generate random
    mt19937 rng(random_device{}());                               // seeded Mersenne Twister
    uniform_int_distribution<int> dist(1,guessingRanges[difficulty]);   // range [1,guessingRanges]
    secretNumber = dist(rng);                                     // random number

}

bool Game::Playround(Player &pl, double playerBet, int playerGuess) {
    bool won;

    vector<int> rewards = {5, 10, 50, 100}; // lets make a "fair" casino (i.e.: irreal),
                                            // where the player has no losses over time
    pl.substractMoney(playerBet);
    won = ((playerGuess == secretNumber) ? true : false);
    
    if (won)
        pl.addMoney(rewards[difficulty]*playerBet);

    pl.updateResult(won);
    return won;

    
}
