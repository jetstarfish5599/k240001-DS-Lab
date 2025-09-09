#include <iostream>
using namespace std;

const int SIZE = 5;

bool haveCommonFriend(bool friends[SIZE][SIZE], int a, int b) {
    for (int i = 0; i < SIZE; i++) {
        if (friends[a][i] && friends[b][i]) return true;
    }
    return false;
}

int main() {
    //5x matrix
    bool friends[SIZE][SIZE] = {
        {0,1,0,1,0},
        {1,0,1,0,0},
        {0,1,0,1,0},
        {1,0,1,0,1},
        {0,0,0,1,0}
    };

    int p1, p2;
    cout << "Enter two people (0-4): ";
    cin >> p1 >> p2;

    if (haveCommonFriend(friends, p1, p2))
        cout << p1 << " and " << p2 << " have a common friend.\n";
    else
        cout << p1 << " and " << p2 << " do not have a common friend.\n";

    return 0;
}