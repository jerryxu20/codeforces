#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> tii;

#define pb push_back
#define mp make_pair

double distance(tii &a, tii&b) {
    auto [i, j, k] = a;
    auto [ii, jj, kk] = b;
    double dx = abs(i - ii);
    double dy = abs(j - jj);
    double dz = abs(k - kk);
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    int n;
    cin >> n;
    vector<tii> nodes(n);
    for (auto &[a, b, c]: nodes) {
        cin >> a >> b >> c;
    }
    double ans = INT_MAX;
    for (int i = 1; i + 1 < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double tour = distance(nodes[0], nodes[i]) + distance(nodes[0], nodes[j]) + distance(nodes[i], nodes[j]);
            tour /= 2;
            ans = min(ans, tour);
        }
    }
    cout << setprecision(20) <<  ans << endl;
    return 0;
}