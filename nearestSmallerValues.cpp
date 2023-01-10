#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    // vector<int> nums(n);
    map<int, int> values;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        // find something that is just smaller than me
        // upper bound means less negative, so smaller
        auto it = values.upper_bound(-a);
        if (it == values.end()) {
            cout << 0 << ' ';
            // continue;    
        } else {
            cout << it->second << ' ';
        }
        values[-a] = i;
        // cin >> nums[i];
    }

    return 0;
}