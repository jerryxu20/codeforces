#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    map<int, int> played;
    int ans = 0;
    int run = 0;
    int startidx = 1;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (played[a] >= startidx) {
            startidx = played[a];
            run = i - startidx;
        } else {
            run++;
        }
        played[a] = i;
        ans = max(ans, run);
    }
    cout << ans;
    return 0;
}