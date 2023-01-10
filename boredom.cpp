#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair


int main() {
    long long n;
    cin >> n;
    map<long long, long long> value;
    long long mx = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        value[a] += a;
        mx = max(mx, a);
    }
    vector<vector<long long>> dp(mx + 1, vector<long long>(2, 0));
    long long ans = 0;
    for (long long i = 1; i <= mx; i++) {
        // answer if I can current num;
        // 0 is don't take, 1 is take
        dp[i][1] = dp[i - 1][0] + value[i];
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        // answer if I don't take current num;
        ans = max({ans, dp[i][0], dp[i][1]});
    }
    cout << ans;
    return 0;
}