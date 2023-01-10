#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> nums(n);
    // threesum
    for (int i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i + 2 < n; i++) {
        int t = x - nums[i].first;
        int low = i + 1;
        int high = n - 1;
        while (low < high) {
            if (nums[low].first + nums[high].first > t) {
                high--;
            } else if (nums[low].first + nums[high].first < t) {
                low++;
            } else {
                cout << nums[low].second << " " << nums[high].second << " " << nums[i].second;
                return 0;
            }            
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}