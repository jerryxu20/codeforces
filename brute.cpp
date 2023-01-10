#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

bool check_valid(vector<int> &perms, vector<int> &check) {
    int n = perms.size();
    for (int i = 0; i + 1 < n; i += 2) {
        if (max(perms[i], perms[i + 1]) != check[i]) {
            return false;
        }
    }
    return true;
} 

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        bool good = true;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                nums[i] = nums[i - 1];
            } else {
                int a;
                cin >> a;
                nums[i] = a;
            }
        }
        vector<int> perms(n);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            perms[i] = i + 1;
        }
        do {
            if (check_valid(perms, nums)) {
                if (ans.size() == 0) {
                    ans = perms;
                } else {
                    ans = min(ans, perms);
                }
            };
        } while (next_permutation(all(perms)));
        if (ans.size() == 0) {
            cout << -1 << endl;
            continue;
        }
        for (int num: ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}