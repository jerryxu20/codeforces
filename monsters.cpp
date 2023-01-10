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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    char c;
    queue<pair<int, int>> monsters;
    vector<vector<int>> grid(n, vector<int> (m, INT_MAX));
    pair<int, int> start;
    set<pair<int, int>> visited;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (c == '#') grid[i][j] = 0;
            if (c == 'M') {
                grid[i][j] = 0;
                monsters.push(mp(i, j));
            }
            if (c == 'A') start = mp(i, j);
        }
    }
    int i, j, ii, jj;
    vector<vector<int>> delta = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int distance = 0;
    while (true) {
        int sz = sz(monsters);
        if (sz == 0) break;
        while (sz--) {
            tie (i, j) = monsters.front();
            if (visited.count(mp(i, j))) {
                cout << "revisited some places";
            }
            visited.insert(mp(i, j));
            if (distance > grid[i][j]) continue;
            monsters.pop();
            for (auto &d: delta) {
                ii = i + d[0];
                jj = j + d[1];
                if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
                // cout << grid[ii][jj] << " " << distance + 1 << endl;
                if (grid[ii][jj] <= distance + 1) continue;
                grid[ii][jj] = distance + 1;
                monsters.push(mp(ii, jj));
            }
        }
        distance++;
    }
    distance = 0;
    queue<pair<int, int>> q;
    vector<vector<vector<int>>> ans (n, vector<vector<int>> (m));
    q.push(start);
    pair<int, int> end = {-1, -1};
    bool done = false;
    while (true) {
        int sz = sz(q);
        if (sz == 0) break;
        while (sz--) {
            end = q.front();
            tie(i, j) = end;
            q.pop();
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                done = true;
                break;
            };
            end = {-1, -1};
            if (grid[i][j] < distance) continue;
            for (auto &d: delta) {
                ii = i + d[0];
                jj = j + d[1];
                if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
                if (grid[ii][jj] <= distance + 1) continue;
                grid[ii][jj] = distance + 1;
                ans[ii][jj] = d;
                // cout << ii << " " << jj << endl;
                q.push(mp(ii, jj));
            }
        }
        if (done) break;
        distance++;
    }
    if (end.first == -1) {
        cout << "NO" << endl;
        return 0;
    }
    map<vector<int>, char> path;
    path[{1,  0}] = 'D';
    path[{-1, 0}] = 'U';
    path[{0,  1}] = 'R';
    path[{0, -1}] = 'L';
    string result = "";
    while (end != start) {
        tie (i, j) = end;
        // cout << i << " " << j << endl;
        result += path[ans[i][j]];
        // cout << "delta " << ans[i][j][0] << " " << ans[i][j][1] << endl;
        ii = i - ans[i][j][0];
        jj = j - ans[i][j][1];
        end = mp(ii, jj);
    }
    reverse(result.begin(), result.end());
    cout << "YES" << endl;
    cout << sz(result) << endl;
    cout << result << endl;
    return 0;
}