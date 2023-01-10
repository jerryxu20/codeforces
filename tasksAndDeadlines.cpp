#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> tasks (n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second; 
    }
    sort(tasks.begin(), tasks.end(), [] (auto &a, auto &b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    long long time = 0;
    long long ans = 0;
    for (auto &task: tasks) {
        long long day = task.first + time;
        ans += task.second - day;
        time = day;
    }
    cout << ans << endl;
    return 0;
}