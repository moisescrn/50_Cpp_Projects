#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H
class Player {
private:
    string playerName;
    float currentMoney;
    int wins;
    int losses;

public:
    // Constructor
    Player(string name, float initMoney);


    void addMoney(int amount) { currentMoney += amount; } 
    void substractMoney(int amount) { currentMoney -= amount; }

    void updateResult(bool win) { (win) ? wins+=1 : losses+=1; }

    void getName() { printf("%s\n", playerName.c_str()); }
    float getBalance() { return currentMoney; }

    void displayStats();
};
#endif /*PLAYER_H*/
