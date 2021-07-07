#include <bits/stdc++.h>
using namespace std;
int main()
{
    string txt,pat;
    cin >> txt >> pat;
    int found = txt.find(pat);
    while (found != string::npos) {
        cout << "Pattern found at index " << found << endl;
        found = txt.find(pat, found + 1);
    }
}

