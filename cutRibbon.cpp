#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    vector<int> cuts (3);
    cin >> n >> cuts[0] >> cuts[1] >> cuts[2];
    sort(cuts.begin(), cuts.end());
    vector<int> dp (n + 1);
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int cut: cuts) {
            if (i - cut < 0) break;
            if (i - cut  == 0) {
                mx = max(mx, dp[i - cut] + 1);
            } else if (dp[i - cut] > 0) {
                mx = max(mx, dp[i - cut] + 1);
            }
        }
        dp[i] = mx;
    }
    cout << dp[n];
    return 0;
}