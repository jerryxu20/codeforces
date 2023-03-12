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
    int n, m, q, a, b;
    ll c;
    cin >> n >> m >> q;
    vector<vector<ll>> weights(n + 1, vector<ll> (n + 1, LLONG_MAX));
    while(m--) {
        cin >> a >> b >> c;
        weights[a][b] = min(c, weights[a][b]);
        weights[b][a] = min(c, weights[b][a]);
    }
    ll through;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (weights[i][k] == LLONG_MAX || weights[k][j] == LLONG_MAX) continue;
                through = weights[i][k] + weights[k][j];
                weights[i][j] = min(through, weights[i][j]);
            }
        }
    }
    while(q--) {
        cin >> a >> b;
        if (a == b) {
            cout << 0 << endl;
            continue;
        }
        if (weights[a][b] != LLONG_MAX) {
            cout << weights[a][b] << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}