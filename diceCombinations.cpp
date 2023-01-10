#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> ans(n + 1);
    for (int i = 1; i <= 6 && i < n + 1; i++) {
        ans[i] = 1;
    }
    for (int i = 1; i < n + 1; i++) {
        // 1 2 3 4 5 6 7
        for (int j = i - 1; j >= 0 && j >= i - 6; j--) {
            ans[i] += ans[j];
            ans[i] = ans[i] % 1000000007;
        }
    }
    cout << ans[n];
    return 0;
}