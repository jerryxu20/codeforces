#include <bits/stdc++.h>
using namespace std;

void search(vector<vector<char>> &grid, int i, int j, int n, int m) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return;
    }
    if (grid[i][j] == '.') {
        grid[i][j] = '#';
        search(grid, i + 1, j, n, m);
        search(grid, i - 1, j, n, m);
        search(grid, i, j + 1, n, m);
        search(grid, i, j - 1, n, m);
    }
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                ans++;
                search(grid, i, j, n, m);
            }
        }
    }
    cout << ans;
    return 0;
}