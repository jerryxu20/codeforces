#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, t;
    cin >> n >> t;
    vector<long long> machines(n);
    long long low = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> machines[i];
        low = min(low, machines[i]);
    }
    // the higest time is the fastest machine making all the them
    long long high = t * low;
    long long ans = high;
    while (low <= high) {
        long long time = (low + high) / 2;
        long long units = 0;
        // this is how much time each machine gets
        for (long long machine: machines) {
            units += time / machine;
        }
        if (units >= t) {
            // made enough units
            ans = min(ans, time);
            high = time - 1;
        } else {
            low = time + 1;
        }
    }
    cout << ans << endl;
    return 0;
}