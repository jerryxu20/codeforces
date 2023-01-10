#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> prefix(n + 1);
    vector<long long> nums (n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 1; i <= n; i++) {
        // what is the to left of me?
        prefix[i] = prefix[i - 1] + nums[i - 1]; 
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << endl;
    }
    return 0;
}