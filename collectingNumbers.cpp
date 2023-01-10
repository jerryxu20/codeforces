#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> indexes(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        // a is the number;
        // i is the index;
        indexes[a - 1] = i;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (indexes[i] < indexes[i - 1]) {
            ans++;
        }
    }
    cout << ans + 1;
    return 0;
}