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
    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);
    for (ll &coin: coins) {
        cin >> coin;
    }
    sort(all(coins)); 
    vector<vector<ll>>dp (x + 1, vector<ll> (n));
    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            // I am going to use the jth coin
            // there are n ways to make sum s with n - 1 coins
            if (i - coins[j] >= 0) {
                dp[i][j] += dp[i - coins[j]][j - 1];
                dp[i][j] %= 1000000007;
                continue;
            }
            break;
        }
    }
    ll ans = 0;
    for (auto &num: dp.back()) {
        ans += num;
        ans %= 1000000007;
    }
    cout << ans;
    return 0;
}