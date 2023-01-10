#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

const ll LINF = 1e18;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> nums(n);
    vector<ll> prefix(n + 1);
    for (ll &num: nums) {
        cin >> num;
    }
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }
    multiset<ll> ms;
    ll ans = LLONG_MIN;
    for (int i = a; i <= n; i++) {
        if (i > b) {
            ms.erase(ms.find(prefix[i - b - 1]));
        }
        ms.insert(prefix[i - a]);
        ans = max(ans, prefix[i] - *ms.begin());
    }
    cout << ans << endl;
    return 0;
}