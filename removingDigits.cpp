#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> ans(n + 1);
    ans[0] = 0;
    for (int i = 1; i <= n; i++) {
        int a = i;
        int mn = INT_MAX;
        while (a > 0) {
            int digit = a % 10;
            if (digit > 0 && i - digit >= 0) {
                mn = min(mn, ans[i - digit]);
            }
            a = a / 10;
        }
        ans[i] = mn + 1;
    }
    cout << ans[n];
    return 0;
}