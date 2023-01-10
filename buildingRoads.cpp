#include <bits/stdc++.h>
using namespace std;

void dfs(vector<bool> &connected, vector<vector<int>> &adj, int city) {
    if (connected[city]) {
        return;
    }
    connected[city] = true;
    for (int &i: adj[city]) {
        dfs(connected, adj, i);
    }
    return;
}

int main() {
    int m, n;
    cin >> n >> m;
    vector<bool> connected(n);
    vector<vector<int>> roads (n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        roads[b].push_back(a);
        roads[a].push_back(b);
    }
    int ans = 0;
    vector<int> bad;
    dfs(connected, roads, 0);
    for (int i = 1; i < n; i++) {
        if (!connected[i]) {
            ans++;
            bad.push_back(i + 1);
            dfs(connected, roads, i);
        }
    }
    cout << ans << '\n';
    for (int i: bad) {
        cout << 1 << ' ' << i << '\n';
    }
    return 0;
}