#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, t; 
    cin >> n >> t;

    vector<int> coins(n);
    vector<int> ans(t + 1);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    for (int i = 1; i < t + 1; i++) {
        int mn = 10e6 + 1;
        bool written = false;
        for (int &coin: coins) {
            if (i - coin < 0) {
                break;
            } else {
                if (ans[i - coin] == -1) {
                    continue;
                }
                written = true;
                mn = min(mn, ans[i - coin]); 
            }
        }
        if (!written) {
            mn = -2;
        }
        ans[i] = mn + 1;
    }
    cout << ans[t];
    return 0;
}