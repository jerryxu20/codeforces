#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> ranges (n);
    vector<int> ans1 (n);
    vector<int> ans2 (n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].first.first >> ranges[i].first.second;
        
        ranges[i].second = i;
    }
    sort(ranges.begin(), ranges.end(), [] (auto &a, auto &b) {
        if (a.first.first == b.first.first) return a.first.second > b.first.second;
        return a.first.first < b.first.first;
    });
    int most_right = 0;
    for (auto &range: ranges) {
        // does some other range contain me?
        if (most_right >= range.first.second) {
            ans2[range.second] = 1;
        }
        most_right = max(most_right, range.first.second);
    }
    most_right = 0;
    sort(ranges.begin(), ranges.end(), [] (auto &a, auto &b) {
        if (a.first.second == b.first.second) return a.first.first > b.first.first;
        return a.first.second < b.first.second;
    });
    for (auto &range: ranges) {
        if (most_right >= range.first.first) {
            ans1[range.second] = 1;
        }
        most_right = max(most_right, range.first.first);
    }
    for (int i: ans1) {
        cout << i << ' ';
    }
    cout << endl;
    for (int i: ans2) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}