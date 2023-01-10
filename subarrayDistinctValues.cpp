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
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    vector<int> nums(n);
    for (auto &num: nums) {
        cin >> num;
    }
    map<int, int> oc;
    int low = 0;
    int unique = 0;
    for (int i = 0; i < n; i++) {
        if (oc[nums[i]]++ == 0) {
            unique++;
        }
        while (unique > k) {
            if (--oc[nums[low]] == 0) {
                unique--;
            }
            low++;
        }
        // cout << low << " " << i << endl; 
        ans += i - low + 1;
    }
    cout << ans << endl;
    return 0;
}