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

void Game::chooseDifficulty(int diff) {
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

void Game::Playround(Player &pl) {
    int userGuess;
    double userBet;
    bool won;

    vector<int> rewards = {5, 10, 50, 100}; // lets make a "fair" casino (i.e.: irreal),
                                            // where the player has no losses over time
    vector<int> guessingRanges = {5, 10, 50, 100}; // Range of guessing depending on difficulty
    string difficulties[4] = {"easy", "medium", "hard", "extreme"};

    cout << "Welcome to the guessing game!" << endl;
    cout << "How much money do you want to bet? You have " << pl.getBalance() << "€ aviable" << endl;
    cin >> userBet;
    pl.substractMoney(userBet);
    cout << "The current difficulty is set to " << difficulties[difficulty];
    cout << ", so you have to guess a number between 1 and " << guessingRanges[difficulty] << endl;
    
    cin >> userGuess;
    won = ((userGuess == secretNumber) ? true : false);
    if (won) {
        pl.addMoney(rewards[difficulty]*userBet);
        cout << "You have guessed correctly! Now you have " << pl.getBalance() << "€" << endl;

        pl.updateResult(won);
        return;
    }

    cout << "You have lost! Now you have " << pl.getBalance() << "€" << endl;
    pl.updateResult(won);
    return;
}
