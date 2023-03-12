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
    ll T, N, move;
    cin >> T;
    while (T--) {
        cin >> N;
        ll ans = 0;
        for (int i = 0;;i++) {
            if (N == 0) break;
            if ((N % 4 == 0 && N != 4) || N % 2 == 1) {
                move = 1;
            } else {
                move = N/2;
            }
            N -= move;
            if (i % 2 == 0) {
                ans += move;
            }
        }
        cout << ans << endl;
    }
    return 0;
}