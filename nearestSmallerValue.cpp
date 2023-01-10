#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> nums(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i].first;
        nums[i].second = i;
    }
    sort(nums.begin() + 1, nums.end());
    set<int> indices;
    vector<int> ans(n + 1);
    vector<int> todo;
    for (int i = 1; i <= n; i++) {
        //search for an index smaller than mine
        if (nums[i].first != nums[i - 1].first) {
            for (int idx: todo) {
                indices.insert(-idx);
            }
            todo = {};
        }
        auto it = indices.upper_bound(-nums[i].second);
        if (it == indices.end()) {
            ans[nums[i].second] = 0;
        } else {
            ans[nums[i].second] = -*it;
        }
        todo.push_back(nums[i].second);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}