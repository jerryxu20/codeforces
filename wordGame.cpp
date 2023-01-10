#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        unordered_map<string, int> freq;
        vector<vector<string>> people (3);
        for (int i = 0; i < n; i++) {
            string s1;
            cin >> s1;
            people[0].push_back(s1);
            freq[s1]++;
        }
        for (int i = 0; i < n; i++) {
            string s1;
            cin >> s1;
            people[1].push_back(s1);
            freq[s1]++;
        }
        for (int i = 0; i < n; i++) {
            string s1;
            cin >> s1;
            people[2].push_back(s1);
            freq[s1]++;
        }
        for (int i = 0; i < 3; i++) {
            int points = 0;
            for (string &s: people[i]) {
                if (freq[s] == 1) {
                    points += 3;
                } else if (freq[s] == 2) {
                    points += 1;
                }
            }
            cout << points << ' ';
        }
        cout << endl;
    }
    return 0;
}