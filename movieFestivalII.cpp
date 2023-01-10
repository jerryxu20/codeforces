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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies(n);
    for (auto &p: movies) {
        cin >> p.second >> p.first;
    }
    ll ans = 0;
    multiset<int> times;
    for (int i = 0; i < k; i++) {
        times.insert(0);
    }
    sort(all(movies));
    for (auto &p: movies) {
        auto it = times.lower_bound(-p.second);
        if (it == times.end()) continue;
        times.erase(it);
        times.insert(-p.first);
        ans++;
    }
    cout << ans << endl;
    return 0;
}