#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;
    sort(n.begin(), n.end());
    vector<char> ans;
    char middle = '1';
    int run = 0;
    char prev = '1';
    char prevRun = '1';
    for (char c: n) {
        if (c == prev) {
            run++;
        } else {
            if (run % 2 == 1) {
                if (middle != '1') {
                    cout << "NO SOLUTION";
                    return 0;
                }
                middle = prevRun;
            }
            for (int i = 0; i < run /2; i++) {
                ans.push_back(prevRun);
            }
            run = 1;
            prevRun = c;
        }
        prev = c;
    }
    if (run % 2 == 1) {
        if (middle != '1') {
            cout << "NO SOLUTION";
            return 0;
        } else {
            middle = prev;
            for (int i = 0; i < run / 2; i++) {
                ans.push_back(prev);
            }
        }
    } else { 
        for (int i = 0; i < run /2; i++) {
            ans.push_back(prev);
        }
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i];
    }
    if (middle != '1') {
        cout << middle;
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    return 0;



}