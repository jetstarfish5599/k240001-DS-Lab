#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int target; //random

//Recursive function
void guess(int player) {
    int g;
    cout << "Player " << player << " guess (1-100): ";
    cin >> g;

    if (g == target) {
        cout << "Player " << player << " wins!" << endl;
        return;
    }
    else if (g < target)
        cout << "Too low!" << endl;
    else
        cout << "Too high!" << endl;

    //Switch player
    guess(player == 1 ? 2 : 1);
}

int main() {
    srand(time(0));
    target = rand() % 100 + 1;

    cout << "=== Guess the Number Game ===" << endl;
    guess(1);
    return 0;
}
