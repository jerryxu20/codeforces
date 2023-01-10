#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ans.push_back({a, b});
    }
    // pair(starting, ending). Sort by ending time first, then starting time.
    sort(ans.begin(), ans.end(), [](auto &left, auto &right) {
        if (left.second == right.second) {
            return left.first > right.first;
        } else {
            return left.second < right.second;
        }
    });
    int count = 0;
    int end = 0;
    for (auto &p: ans) {
        // start of new movie must be after end
        if (p.first >= end) {
            end = p.second;
            count++;
        }
    }
    cout << count;
    return 0;
}