#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> answers (m, vector<int>(5));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            answers[j][s[j] - 'A']++;
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int w;
        cin >> w;
        int num = 0;
        for (int a: answers[i]) {
            num = max(num, a);
        }
        ans += w * num;
    }
    cout << ans;
    return 0;
}