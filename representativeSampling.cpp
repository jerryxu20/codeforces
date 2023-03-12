#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define pb push_back
#define mp make_pair

int terminates[1000007], height[1000007];
vector<int> adj[1000007];
int nxt[1000007][26];
vector<int> dp[1000007];
 
void dfs(int node, int k) {
    int sz = terminates[node];
    for (auto &to: adj[node]) {
        dfs(to, k);
        terminates[node] += terminates[to];
    }
    dp[node].resize(min(k + 1, terminates[node] + 1));
    for (int i = 1; i <= min(k, sz); i++) {
        dp[node][i] = i * (i - 1) / 2 * height[node];
    }

    for (auto &to: adj[node]) {
        if (terminates[to] == 0) continue;
        vector<int> current = dp[node];
        fill(all(dp[node]), 0);
        for (int i = 0; i <= sz; i++) {
            for (int j = 0; j <= terminates[to] && j + i <= k; j++) {
                dp[node][i + j] = max(dp[node][i + j], current[i] + dp[to][j] + i * j * height[node]);
            }
        }
        dp[to].clear();
        sz += terminates[to];        
    }
    return;
}


int main() {
    int n, k, N = 0;
    string s;
    cin >> n >> k;
    while (n--) {
        cin >> s;
        int node = 0;
        for (char c: s) {
            int idx = c - 'a';
            if (nxt[node][idx] == 0) {
                nxt[node][idx] = ++N;
                adj[node].pb(N);
                height[N] = height[node] + 1;
            }
            node = nxt[node][idx];
        }
        terminates[node]++;
    }
 
    // cout << sz(height) << " " << sz(nxt) << " " << sz(terminates) << sz(adj) << endl;
    dfs(0, k);
    cout << dp[0][k] << endl;
    exit(0);
    return 0;
}