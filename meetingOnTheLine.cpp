#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

const int MOD_INT = 1e9 + 7;
const ll MOD = 1e9 + 7;


int main() {
    int q;
    cin >> q;
    for (int t = 1; t <= q; t++) {
        int n;
        cin >> n;
        vector<int> position (n);
        vector<int> b(n);
        double small = INT_MAX;
        double big = -1;
        
        for (int i = 0; i < n; i++) {
            cin >> position[i];
            big = max(big,(double) position[i]);
            small = min(small,(double) position[i]);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        double large = INT_MAX;
        double x0;
        while (small <= big) {
            double l = 0;
            double r = 0;
            double mid = (small + big) / 2.0;
            double total = 0;
            for (int i = 0; i < n; i++) {
                if (position[i] < mid) {
                    l += abs((double)position[i] - mid);
                    total += abs((double)position[i] - mid);
                } else if (position[i] > mid) {
                    r += abs((double)position[i] - mid);
                    total += abs((double)position[i] - mid);
                } else {
                    total += abs((double)position[i] - mid);
                }
            }
            if (total < large) {
                x0 = mid;
            }
            if (l > r) {
                big = mid - 1e-12;
            } else {
                small = mid + 1e-12;
            }
        }
        cout << "CASE" << x0 << '\n';
    }
    return 0;
}