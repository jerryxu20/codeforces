#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define loop(i, a, b) for(int i = a; i < (b); ++i)
// #define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n, k;
    cin >> n >> k;
    ordered_set<int> kids;
    for (int i = 1; i <= n; i++) {
        kids.insert(i);
    }
    int position = 0;
    while (!kids.empty()) {
        position %= kids.size();
        position += k;
        position %= kids.size();
        auto it = kids.find_by_order(position);
        cout << *it << endl;
        kids.erase(it);
    }
    return 0;
}