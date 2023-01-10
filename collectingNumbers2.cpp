#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> indexes(n);
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        nums[i]--;
        indexes[nums[i]] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (indexes[i] < indexes[i - 1]) {
            ans++;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >>  b;
        a--;
        b--;
        int idx1 = nums[b];
        int idx2 = nums[a];
        if (idx1 > 0 && indexes[idx1] < indexes[idx1 - 1]) {
            ans--;
        }
        if (idx1 + 1 < n && indexes[idx1 + 1] < indexes[idx1]) {
            ans--;
        }
        if (idx2 > 0 && idx2 != idx1 + 1 && indexes[idx2] < indexes[idx2 - 1]) {
            ans--;
        }
        if (idx2 + 1 < n && idx2 != idx1 - 1 && indexes[idx2 + 1] < indexes[idx2]) {
            ans--;
        }
        swap(indexes[idx1], indexes[idx2]);
        swap(nums[a], nums[b]);
        if (idx1 > 0 && indexes[idx1] < indexes[idx1 - 1]) {
            ans++;
        }
        if (idx1 + 1 < n && indexes[idx1 + 1] < indexes[idx1]) {
            ans++;
        }
        if (idx2 > 0 && idx2 != idx1 + 1 && indexes[idx2] < indexes[idx2 - 1]) {
            ans++;
        }
        if (idx2 + 1 < n && idx2 != idx1 - 1 && indexes[idx2 + 1] < indexes[idx2]) {
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}