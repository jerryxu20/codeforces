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
    ll n, k;
    cin >> n >> k;
    // what is the kth num in my sequence
    ll odds = n/2;
    if (n % 2 == 1) {
        odds++;
    }
    if (k <= odds) {
        cout << 2 * (k - 1) + 1 << endl;
        return 0;
    }
    k -= odds;
    cout << 2 * k << endl;
    return 0;
}