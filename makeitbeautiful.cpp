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
        vector<int> nums(n);
        for (auto &num: nums) {
            cin >> num;
        }
        sort(all(nums));
        vector<int> ans;
        int low = 0;
        int high = n - 1;
        while (low < high) {
            ans.push_back(nums[low]);
            ans.push_back(nums[high]);
            low++;
            high--;
        }
        if (low == high) {
            ans.push_back(nums[low]);
        }
        int sm = ans[0];
        bool good = true;
        for (int i = 1; i < n; i++) {
            if (ans[i] == sm) {
                good = false;
                break;
            }
            sm += ans[i];
        }
        if (good) {
            cout << "YES" << endl;
            for (auto num: ans) {
                cout << num << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}