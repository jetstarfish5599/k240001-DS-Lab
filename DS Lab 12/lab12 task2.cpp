#include <iostream>
#include <string>
using namespace std;

#define d 256 //ASCII

void rabinKarp(string text, string pattern, int q) {
int n = text.length();
int m = pattern.length();

if (m == 0 || m > n) {
cout << "Invalid pattern\n";
return;
}

int p = 0; //pattern hash
int t = 0; //text hash
int h = 1;

for (int i = 0; i < m - 1; i++) {
h = (h * d) % q;
}

for (int i = 0; i < m; i++) {
p = (d * p + pattern[i]) % q;
t = (d * t + text[i]) % q;
}

cout << "Pattern found at indices: ";

for (int i = 0; i <= n - m; i++) {

    if (p == t) {
        bool match = true;
        for (int j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            cout << i << " ";
        }
    }

    if (i < n - m) {
        t = (d * (t - text[i] * h) + text[i + m]) % q;
        if (t < 0) t = t + q;
    }
}

cout << endl;
}

int main() {
string text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
string pattern = "Algorithms";

int q = 101; //prime modulus

rabinKarp(text, pattern, q);

return 0;
}
