#include <vector>
#include <iostream>
using namespace std;

#include "Player.h"
#include "Game.h"

int main(){
    Player Juan("Juan Antonio", 100);
    Juan.displayStats();

    Game G1;
    vector<int> guessingRanges = {5, 10, 50, 100}; // Range of guessing depending on difficulty
    string difficulties[4] = {"easy", "medium", "hard", "extreme"};

    cout << "Welcome to the guessing game!" << endl;
    cout << "How much money do you want to bet? You have " << Juan.getBalance() << "€ aviable" << endl;
    int userBet;
    cin >> userBet;
    cout << "Which difficulty do you want to play with?" << endl;
    int diff;
    cin >> diff;
    G1.setDifficulty(diff);
    cout << "The current difficulty is set to " << difficulties[diff];
    cout << ", so you have to guess a number between 1 and " << guessingRanges[diff] << endl;
    
    G1.generateNumber();
    int userGuess;
    cin >> userGuess;

    bool won = G1.Playround(Juan, userBet, userGuess);
    if (won)
        cout << "You have guessed correctly! Now you have " << Juan.getBalance() << "€" << endl;
    else
        cout << "You have lost! Now you have " << Juan.getBalance() << "€" << endl;
    

    //Juan.displayStats();
    return 0;
}
