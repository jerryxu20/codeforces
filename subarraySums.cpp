#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int ans = 0;
    int sum = 0;
    int low = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        while (sum > x) {
            sum -= nums[low];
            low++;
        }
        if (sum == x) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}