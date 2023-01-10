#include <bits/stdc++.h>
using namespace std;

bool match(vector<vector<int>> &friends, vector<int> &coloring, int node) {
    if (coloring[node] == 0) {
        coloring[node] = 1;
    }
    int color = coloring[node];
    for (auto &f: friends[node]) {
        if (coloring[f] == 0) {
            coloring[f] = -color;
            if (!match(friends, coloring, f)) {
                return false;
            }
        } else if (coloring[f] == color) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> friends(n);
    vector<int> coloring(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        if (coloring[i] == 0) {
            if (!match(friends, coloring, i)) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for (int &color: coloring) {
        if (color == -1) {
            cout << "2" << ' ';
        } else {
            cout << "1" << ' ';
        }
    }
    return 0;
}