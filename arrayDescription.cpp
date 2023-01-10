#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n, vector<ll> (m + 2));
    int a;
    cin >> a;
    if (a == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][a] = 1;
    }
    for (int i = 1; i < n; i++) {
        cin >> a;
        if (a == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];
                dp[i][j] %= 1000000007;
            }
        } else {
            for (int j = a; j <= a; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];
                dp[i][j] %= 1000000007;
            }
        }
    }
    ll ans = 0;
    for (ll count: dp.back()) {
        ans += count;
        ans %= 1000000007;
    }
    cout << ans << endl;

    return 0;
}