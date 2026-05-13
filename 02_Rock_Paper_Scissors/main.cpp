#include <iostream>
using namespace std;
#include <random> // this is one of several ways to implement random numbers

const int result_table[3][3] { // Checks the results directly
    //      R   P   S
    /*R*/ { 0, -1,  1},
    /*P*/ { 1,  0, -1},
    /*S*/ {-1,  1,  0}
};
/*
 * Result ist given by: result_table[Player1][Player2]
 * 1 ... Wins Player1 (Loses Player2)
 * 0 ... Draw
 * -1 ... Loses Player1 (Wins Player1)
*/

const char choices[3]={'R', 'P', 'S'};

char CPUChoice() {
    mt19937 rng(random_device{}());             // seeded Mersenne Twister
    uniform_int_distribution<int> dist(0,2);    // range [0, 2]
    return dist(rng);                           // random number in [0, 2]
}

int main() {
    int User;
    int CPU = CPUChoice();
    cout << "The computer has already played" << endl;
    cout << "Enter your choice as a number (R=0, P=1 or S=2): ";
    cin >> User;
    cout << "You have played " << choices[User] << endl;
    cout << "The computer has played " << choices[CPU] << endl;

    if (result_table[User][CPU] == 1) 
        cout << "Congratulations! You win!" << endl;
    else if (result_table[User][CPU] == -1)
        cout << "Sorry, the computer wins" << endl;
    else
        cout << "Draw" << endl;

    return 0;
}
