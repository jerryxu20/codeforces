#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

bool doable(int cost, int cap, int n) {
    int gas = 0;
    for (int i = 1; i < n; i++) {
        while (cost - i >= 0 && gas < cap) {
            gas++;
            cost -= i;
        }
        if (gas < 1) return false;
        gas -= 1;
    }
    return true;
}

int main() {
    int n, v;
    cin >> n >> v;
    // the most is buying a liter at every city 1 to n
    int high = n * (n + 1) / 2;
    int low = n - 1;
    int mid;
    int ans = high;
    while (low <= high) {
        mid = (high + low) / 2;
        if (doable(mid, v, n)) {
            ans = min(ans, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    } 
    cout << ans << endl;
    return 0;
}