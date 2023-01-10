#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        unordered_map<string, bool> rows;
        string s = "";
        for (int j = 0; j < a; j++) {
            char c;
            cin >> c;
            if (c == 'B') {
                s += 'G';
            } else {
                s += c;
            }
        }
        string s2 = "";
        for (int j = 0; j < a; j++) {
            char c;
            cin >> c;
            if (c == 'B') {
                s2 += 'G';
            } else {
                s2 += c;
            }
        }
        if (s == s2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}