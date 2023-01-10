#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, t;
    cin >> n >> t;
    int ans = 0;
    vector<int> weights(n);
    map<int, int> w_map;
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        w_map[weights[i]]++;
    }
    for (int &w: weights) {
        auto it = w_map.find(w);
        if (it == w_map.end()) {
            continue;
        }
        if (--it->second == 0) {
            w_map.erase(it);
        }
        auto it2 = w_map.upper_bound(t - w);
        // cout << "looking for " << t - w << endl;
        if (it2 == w_map.begin()) {
            ans++;
            continue;
        } else {
            it2--;
        }
        if (it2 != w_map.end()) {
            if (--it2->second == 0) {
                w_map.erase(it2);
            }
        }
        ans++;
    }
    cout << ans;

}