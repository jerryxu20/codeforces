#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    vector<int> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    sort (sticks.begin(), sticks.end());
    long long ans = 0;
    int target = sticks[n/2];
    for (int &stick: sticks) {
        ans += abs(stick - target);
    }
    long long ans2 = 0;
    if (sticks.size() % 2 == 1) {
        target = sticks[n/2 - 1];
        for (int &stick: sticks) {
            ans2 += abs(stick - target);
        }
        ans = min(ans, ans2);
    }
    cout << ans;
    return 0;
}