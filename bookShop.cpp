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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> books(n);
    for (auto &p:books) {
        cin >> p.first;
    }
    for (auto &p: books) {
        cin >> p.second;
    }
    vector<vector<int>> dp(n + 1, vector<int> (x + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            int rem = j - books[i - 1].first;
            if (rem >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][rem] + books[i - 1].second);
            }
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}