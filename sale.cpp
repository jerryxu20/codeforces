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
    // what is the most I can earn
    // m tv sets
    int n, m;
    cin >> n >> m;
    vector<int> tv(n);
    for (auto &x: tv) cin >> x;
    int ans = 0;
    int cur = 0;
    sort(all(tv));
    for (auto &x: tv) {
        if (m-- == 0) break; 
        cur -= x;
        cur = max(0, cur);
        ans = max(cur, ans);
    }
    cout << ans << endl;
    return 0;
}