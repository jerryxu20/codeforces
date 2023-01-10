#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    // leave, and room number
    priority_queue<pair<int, int>> leave;
    vector<vector<int>> guest (n, vector<int>(3));
    set<int> rooms;
    vector<int> print(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> guest[i][0] >> guest[i][1];
        guest[i][2] = i;
    }
    sort(guest.begin(), guest.end()); // nlogn
    for (auto g: guest) {
        while (!leave.empty() && -leave.top().first < g[0]) { //nlogn total
            rooms.insert(leave.top().second);
            leave.pop();
        }
        int room;
        if (!rooms.empty()) { // logn
            auto it = lower_bound(rooms.begin(), rooms.end(), 0);
            room = *it;
            rooms.erase(it);
        } else {
            room = ++ans;
        }
        print[g[2]] = room;
        leave.push(make_pair(-g[1], room));
    }
    cout << ans << '\n';
    for (int &i: print) {
        cout << i << ' ';
    }
    return 0;
}