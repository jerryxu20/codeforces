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
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> list(n*n);
        int large = n * n;
        int small = 1;
        for (int i = 0; i < n*n; i+=2) {
            list[i] = large;
            list[i + 1] = small;
            large--;
            small++;
        }
        for (int i = 1; i < n; i+=2) {
            reverse(list.begin() + n * i, list.begin() + n * (i + 1));
        }
        for (int i = 1; i <= n * n; i++) {
            cout << list[i - 1] << " ";
            if (i % n == 0) {
                cout << endl;
            }
        }
    }
    return 0;
}