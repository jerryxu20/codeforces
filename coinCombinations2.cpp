#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int>coins (n);
    int count = 0;
    for (int &coin: coins) {
        cin >> coin;
    }
    sort(coins.begin(), coins.end());
    vector<vector<int>> ans (n, vector<int>(t + 1));
    for (int i = 0; i < n; i++) {
        ans[i][0] = 1;
    }
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) {
                ans[j][i] += ans[j - 1][i];
            }
            ans[j][i] %= 1000000007;
            if (i - coins[j] >= 0) {
                ans[j][i] += ans[j][i - coins[j]];
                ans[j][i] %= 1000000007;
                continue;
            }
            break;
        }
    }
    cout << ans[n - 1][t] + count;
    return 0;
}