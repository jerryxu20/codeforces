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

int solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &num: nums) {
        cin >> num;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (gcd(nums[i], nums[j]) <= 2) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    // good if gcd is less equal len
    // beautiful if all prefixes are good
    return 0;
}