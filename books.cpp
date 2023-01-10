#include <bits/stdc++.h>
using namespace std;



int main() {
    int t, n;
    cin >> n >> t;
    vector<int> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }
    int low = 0;
    int time = 0;
    int high = 0;
    int ans = 0;
    while (true) {
        while(high < n && time + books[high] <= t) {
            time += books[high];
            ans = max(ans, high - low + 1);
            high++;
        }
        if (high == n) break;
        time -= books[low];
        low++;
    }
    cout << ans;
    return 0;
}