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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> indices(m + 1);
    indices[0] = 0;
    for (int i = 1; i <= m; i++) {
        cin >> indices[i];
    }
    indices.push_back(n);
    priority_queue<int> pq;
    for (int i = 1; i <= m + 1; i++) {
        pq.push(indices[i] - indices[i - 1]);
    }
    while (k > 0 && !pq.empty()) {
        int gap = pq.top();
        if (gap == 1) break;
        int fhalf = gap / 2;
        int shalf = gap - fhalf;
        pq.pop();
        k--;
        pq.push(fhalf);
        pq.push(shalf);
    }
    int mn = pq.top();
    int mx = pq.top();
    while(!pq.empty()) {
        mn = min(mn, pq.top());
        mx = max(mx, pq.top());
        pq.pop();
    }
    cout << mx - mn << endl;



}

int main() {
    int tCase;
    cin >> tCase;
    while (tCase--) {
        solve();
    }
    return 0;
}