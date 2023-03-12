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

vector<unordered_set<int>> adj;
vector<bool> online;
vector<int> degree;
int n, m, q, o, a, b;

int deg(int node) {
    return sz(adj[node]);
}

bool verge(int node) {
    return degree[node] == 622;
}
bool heavy(int node) {
    return degree[node] >= 1000;
}
int solve(int node) {
    int ans = 0;
    for (auto &nxt: adj[a]) {
        if (online[nxt]) ans++;
    }
    return ans;
}
int main() {
    char c;
    cin >> n >> m >> q >> o;
    online.resize(n + 1);
    adj.resize(n + 1);
    degree.resize(n + 1);
    while(o--) {
        cin >> a;
        online[a] = true;
    }
    while (m--) {
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    vector<int> f_online(n + 1);
    for (int i = 1; i <= n; i++) {
        degree[i] = deg(i);
    }
    vector<tuple<char, int, int>> queries;
    while (q--) {
        cin >> c >> a;
        if (c == 'O' || c == 'F' || c == 'C') {
            queries.pb({c, a, -1});
            continue;
        }
        cin >> b;
        queries.pb({c, a, b});
        if (c == 'A') {
            degree[b]++;
            degree[a]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (online[i] == false) continue;
        for (auto &nxt: adj[i]) {
            if (heavy(nxt)) f_online[nxt] ++;
        }
    }
    for (auto query: queries) {
        tie (c, a, b) = query;
        if (c  == 'O') {
            online[a] = true;
            for (auto &nxt: adj[a]) {
                if (heavy(nxt)) f_online[nxt]++;
            }
        } else if (c == 'F') {
            online[a] = false;
            for (auto &nxt: adj[a]) {
                if (heavy(nxt)) f_online[nxt]--;
            }
        } else if (c == 'A') {
            adj[a].insert(b);
            adj[b].insert(a);
            f_online[a] += (int) online[b];
            f_online[b] += (int) online[a];
        } else if (c == 'D') {
            adj[a].erase(b);
            adj[b].erase(a);
            f_online[a] -= (int) online[b];
            f_online[b] -= (int) online[a];
        } else {
            if (heavy(a)) {
                cout << f_online[a] << endl;
            } else {
                cout << solve(a) << endl;
            }
        }
    }
    return 0;
}