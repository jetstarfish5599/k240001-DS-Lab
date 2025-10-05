#include <iostream>
using namespace std;

const int N = 4;
int board[N][N];

//check for safely
bool isSafe(int row, int col) {
    //check column
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    //check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    //check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

//backtracking
bool placeFlags(int row) {
// all flags placed 
    if (row >= N) return true; 

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
    // place flag
            board[row][col] = 1;       
     // next row
            if (placeFlags(row + 1))   
                return true;
             // backtrack   
            board[row][col] = 0;       
        }
    }
    return false;
}

int main() {
    //initialize board
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (placeFlags(0)) {
        cout << "Maximum flags: " << N << endl;
        cout << "Possible Board position:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << (board[i][j] ? "F " : ". ");
            cout << endl;
        }
    } else {
        cout << "No valid placement.\n";
    }
    return 0;
}
