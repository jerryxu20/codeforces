#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int>apples(n);
    long long weight = 0;
    for (int i = 0; i < n; i++) {
        cin >> apples[i];
        weight += apples[i];
    }
    long long mn = LLONG_MAX;
    for (int mask = 0; mask < (1 << n); mask++) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += apples[i];
            }
        }
        mn = min(mn, abs(weight - sum - sum));
    }
    cout << mn;
}