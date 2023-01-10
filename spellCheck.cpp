#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    unordered_map<char, int> freq;
    freq['T'] = 1;
    freq['i'] = 1;
    freq['m'] = 1;
    freq['u'] = 1;
    freq['r'] = 1;
    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        string s;
        cin >> s;
        if (a != 5) {
            cout << "NO" << endl;
            continue;
        }
        unordered_map<char, int> copy = freq;
        bool good = true;
        for (char &c: s) {
            if (--copy[c] < 0) {
                good = false;
                break;
            }
        }
        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}