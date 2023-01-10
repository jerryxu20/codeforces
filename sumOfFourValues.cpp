#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }
    sort(nums.begin(), nums.end());
    for (int i = 1; i + 2 < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            int t = x - nums[i].first - nums[j].first;
            int low = i + 1;
            int high = n - 1;
            while (low < high) {
                if (nums[low].first + nums[high].first > t) {
                    high--;
                } else if (nums[low].first + nums[high].first < t) {
                    low++;
                } else {
                    cout << nums[i].second << " " << nums[j].second << " " << nums[low].second << " " << nums[high].second;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}