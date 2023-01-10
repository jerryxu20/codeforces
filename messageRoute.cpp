#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj (n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> parent(n, -1);
    parent[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto i: adj[node]) {
            if (parent[i] == -1) {
                parent[i] = node;
                if (i == n - 1) {
                    break;
                } 
                q.push(i);
            }
        }
    }
    if(parent[n - 1] == -1) {
        cout << "IMPOSSIBLE" << '\n';
    }
    vector<int> ans;
    int node = n - 1;
    while (node != 0) {
        ans.push_back(parent[node]);
        node = parent[node];
    }
    reverse(ans.begin(), ans.end());
    ans.push_back(n - 1);
    cout << ans.size() << '\n';
    for (int &n: ans) {
        cout << n + 1 << ' ';
    }
    return 0;
}