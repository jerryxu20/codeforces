#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    pair<int, int> start;
    pair<int, int> end;
    vector<vector<char>> grid(n, vector<char>(m)); 
    vector<vector<char>> direction(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                start.first = i;
                start.second = j;
            } else if (grid[i][j] == 'B') {
                end.first = i;
                end.second = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push(start);
    int i;
    int j;
    while (!q.empty()) {
        auto &p = q.front();
        i = p.first;
        j = p.second;
        q.pop();
        if (i + 1 < n && direction[i + 1][j] == '.' && (grid[i + 1][j] == '.' || grid[i + 1][j] == 
        'B')) {
            pair<int, int> pi = make_pair(i + 1, j);
            direction[i + 1][j] = 'D';
            if (pi.first == end.first && pi.second == end.second) {
                break;
            }
            q.push(pi);
        }
        if (i - 1 >= 0 && direction[i - 1][j] == '.' && (grid[i - 1][j] == '.' || grid[i - 1][j] == 'B')) {
            pair<int, int> pi = make_pair(i - 1, j);
            direction[i - 1][j] = 'U';
            if (pi.first == end.first && pi.second == end.second) {
                break;
            }
            q.push(pi);
        }
        if (j + 1 < m && direction[i][j + 1] == '.' && (grid[i][j + 1] == '.' || grid[i][j + 1] == 'B')) {
            pair<int, int> pi = make_pair(i, j + 1);
            direction[i][j + 1] = 'R';
            if (pi.first == end.first && pi.second == end.second) {
                break;
            }
            q.push(make_pair(i, j + 1));
        }
        if (j - 1 >= 0 && direction[i][j - 1] == '.' && (grid[i][j - 1] == '.' || grid[i][j - 1] == 'B')) {
            pair<int, int> pi = make_pair(i, j - 1);
            direction[i][j - 1] = 'L';
            if (pi.first == end.first && pi.second == end.second) {
                break;
            }
            q.push(make_pair(i, j - 1));
        }
    }
    i = end.first;
    j = end.second;
    if (direction[i][j] == '.') {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    string ans = "";
    while (i != start.first || j != start.second) {
        char d =  direction[i][j];
        ans += d;
        if (d == 'U') {
            i++;
        } else if (d == 'D') {
            i--;
        } else if (d == 'R') {
            j--;
        } else {
            j++;
        }
    }
    cout << ans.length() << endl;
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}