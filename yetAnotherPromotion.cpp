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


int main() {
    // seels on two days, at diff prices
    // n items
    ll t, n, m, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b >> n >> m;
        ll bundle = a * m;
        ll ans = 0;
        if (bundle < b * (m + 1)) {
            ll amount = n/(m + 1);
            ans += amount * bundle;
            n -= (m + 1) * amount;
        }
        ans += min(a, b) * n;
        cout << ans << endl;
    }
    

    return 0;
}