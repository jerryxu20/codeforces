#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        long long sum = 0;
        vector<int> nums;
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == 'L') {
                sum += j;
                nums.push_back(j);
            } else {
                sum += n - j - 1;
                nums.push_back(n - j - 1);
            }
        }
        sort(nums.begin(), nums.end());
        for (int k = 0; k < n; k++) {
            sum = max(sum, sum - nums[k] + n - 1 - nums[k]);
            cout << sum << ' ';
        }
        cout << endl;
    }
    return 0;
}