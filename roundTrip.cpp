#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair


int dfs (vector<vector<int>> &adj, vector<int> &parents, int node) {
    for (int city: adj[node]) {
        if (parents[city] != 0) {
            if (parents[node] == city) continue;
            parents[city] = node;
            return node;
        }
        parents[city] = node;
        int a = dfs(adj, parents, city);
        if (a != 0) return a;
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    int a, b;
    vector<vector<int>> adj(n + 1);
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> parents (n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (parents[i] != 0) continue;
        parents[i] = i;
        ans = max(ans, dfs(adj, parents, i));
        if (ans > 0) break;
    }
    if (ans == 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int p = parents[ans];
    vector<int> cities = {ans};
    while (p != ans) {
        cities.push_back(p);
        p = parents[p];
    }
    cities.push_back(ans);
    cout << cities.size() << endl;
    for (auto city: cities) {
        cout << city << " ";
    }
    cout << endl;
    return 0;
}
