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
    cin >> n;
    vector<int> badge(n);
    for (auto &b: badge) {
        cin >> b;
    }
    sort(all(badge));
    int cost = 0;
    for (int i = 1; i < n; i++) {
        cost += max(badge[i - 1] - badge[i] + 1, 0);
        badge[i] = max(badge[i], badge[i - 1] + 1);
    }
    cout << cost << endl;

    return 0;
}