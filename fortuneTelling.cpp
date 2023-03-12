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

int solve() {
    ll n, x, t;
    cin >> n >> x >> t;
    vector<ll> nums(n);
    for (auto &num: nums) {
        cin >> num;
        x += num;
        x %= 2;
    }
    
    if ((x % 2) == (t % 2)) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}