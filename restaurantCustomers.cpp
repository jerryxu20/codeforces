#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int>enter(n);
    vector<int>leave(n);
    for (int i = 0; i < n; i++) {
        cin >> enter[i] >> leave[i];
    }
    sort(enter.begin(), enter.end());
    sort(leave.begin(), leave.end());
    int ans = 0;
    int mx = 0;
    int time = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        time = enter[i];
        mx++;
        while (leave[l] < time) {
            mx--;
            l++;
        }
        ans = max(mx, ans);
    }
    cout << ans;
    return 0;
}