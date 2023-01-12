#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<long long, long long> pii;

#define pb push_back
#define mp make_pair

// https://cses.fi/problemset/task/1671
int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<ll> ans (n + 1, LLONG_MAX);
    while(m--) {
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        // adj[b].pb(mp(a, c));
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    ans[1] = 0;
    pq.push(mp(0, 1));
    ll dd;
    while (!pq.empty()) {
        auto [dis, node] = pq.top();
        pq.pop();
        if (ans[node] < dis) continue;
        for (auto [nxt, weight]: adj[node]) {
            dd = dis + (ll)weight;
            if (dd >= ans[nxt]) continue;
            ans[nxt] = dd;
            pq.push(mp(dd, nxt));
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}