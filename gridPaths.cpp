#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int ans[n][n];
    bool trapped = false;
    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        if (!trapped) {
            if (a == '*') {
                trapped = true;
                ans[0][i] = 0;
            } else {
                ans[0][i] = 1;
            }
        } else {
            ans[0][i] = 0;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char a;
            cin >> a;
            ans[i][j] = 0;
            if (a == '.') {
                if (i > 0) {
                    ans[i][j] += ans[i - 1][j];
                }
                if (j > 0) {
                    ans[i][j] += ans[i][j - 1];
                }
                ans[i][j] = ans[i][j] % 1000000007;
            }
        }
    }
    cout << ans[n - 1][n - 1];
    return 0;
}