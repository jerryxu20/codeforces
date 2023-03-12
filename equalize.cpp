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
    int n;
    string a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (int) (a[i] != b[i]);
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == b[i]) continue;
        // consider swapping with previous
        swap(a[i], a[i - 1]);
        if (a[i] == b[i] && a[i - 1] == b[i - 1]) {
            ans--;
            continue;
        }
        //revert change
        swap(a[i], a[i - 1]);
    }
    cout << ans << endl;
    return 0;
}