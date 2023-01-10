#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int , null_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> o_set;
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
    o_set nums;
    vector<int> arr(n);
    for (int &a: arr) {
        cin >> a;
    }
    int mid = k / 2;
    int low = 0;
    for (int i = 0; i < n; i++) {
        nums.insert(arr[i]);
        while (nums.size() > k) {
            nums.erase(nums.find(arr[low]));
            low++;
        }
        if (nums.size() == k) {
            cout << *nums.find_by_order(mid) << " ";
        }
    }
    return 0;
}