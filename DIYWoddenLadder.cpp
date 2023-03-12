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
    int n;
    cin >> n;
    vector<int> sticks(n);
    for (auto &stick: sticks) {
        cin >> stick;
    }
    sort(all(sticks));
    for (int i = n - 2; i >= 0; i--) {
        int steps = n - 2;
        steps = min(steps, sticks[i] - 1);
        cout << min(steps, sticks[i] - 1) << endl;
        return;
    }
    cout << 0 << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}