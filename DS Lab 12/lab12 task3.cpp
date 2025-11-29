#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define NO_OF_CHARS 256

void badCharHeuristic(const string& pattern, vector<int>& badChar) {
int m = pattern.length();
for (int i = 0; i < NO_OF_CHARS; i++)
badChar[i] = -1; //initialize
for (int i = 0; i < m; i++)
badChar[(int)pattern[i]] = i; //last occurrence
}

void boyerMooreSearch(const string& text, const string& pattern) {
int n = text.length();
int m = pattern.length();

vector<int> badChar(NO_OF_CHARS);
badCharHeuristic(pattern, badChar);

int s = 0; //pattern shift

while (s <= n - m) {
int j = m - 1;

//comp right left
while (j >= 0 && pattern[j] == text[s + j])
j--;

if (j < 0) {
cout << "Pattern found at index " << s << endl;
s += (s + m < n) ? m - badChar[text[s + m]] : 1;
} else {
int shift = max(1, j - badChar[text[s + j]]);
s += shift;
}
}
}

int main() {
string DNA = "ACGTACGTGACG";
string pattern = "ACG";

boyerMooreSearch(DNA, pattern);

return 0;
}
