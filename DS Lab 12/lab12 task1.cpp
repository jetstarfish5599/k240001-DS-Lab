#include <iostream>
#include <string>
using namespace std;

void bruteForceSearch(string text, string pattern) {
int n = text.length();
int m = pattern.length();
int comparisons = 0; //comparisons

cout << "Matches at indices: ";

for (int i = 0; i <= n - m; i++) {
    int j = 0;

    while (j < m) {
        comparisons++; //comp counted
        if (text[i + j] != pattern[j]) break;
        j++;
    }

    if (j == m) { //matched
        cout << i << " ";
    }
}

cout << "\nTotal comparisons: " << comparisons << endl;
}

int main() {
string text = "the quick brown fox jumps over the lazy dog";
string pattern = "the";

bruteForceSearch(text, pattern);

return 0;
}
