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
    int n;
    cin >> n;
    map<int, int> res;
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        sum += a;
        int m1 = sum % n;
        if (m1 == 0) {
            ans += ++res[0];
            continue;
        }
        int m2;
        if (m1 < 0) {
            m2 = n + m1;
        } else {
            m2 = m1 - n;
        }
        ans += res[m1]++;
        ans += res[m2];
    }
    cout << ans << endl;
    return 0;
}