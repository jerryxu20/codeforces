#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, t;
    cin >> n >> t;
    vector<int> coins(n);
    vector<int> ans(t + 1);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        if (coins[i] <= t) {
            ans[coins[i]] = 1;
        }
    }
    sort(coins.begin(), coins.end());
    for (int i = 1; i < t + 1; i++) {
        for (int &coin: coins) {
            if (i - coin < 0) {
                break;
            }
            ans[i] += ans[i - coin];
            ans[i] = ans[i] % 1000000007;
        }
    }
    cout << ans[t];
    return 0;
}