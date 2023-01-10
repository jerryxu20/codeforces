#include <bits/stdc++.h>
using namespace std;

void solve(int size, int n, vector<bool>&nums) {
    if (n == 1) {
        nums[size - n] = !nums[size - n];
        for (int i = 0; i < size; i++) {
            cout << (int)nums[i];
        }
        cout << endl;
        return;
    } else {
        solve(size, n - 1, nums);
        nums[size-n] = !nums[size - n];
        for (int i = 0; i < size; i++) {
            cout << (int)nums[i];
        }
        cout << endl;
        solve(size,n - 1, nums);
    }
}


int main() {
    int n;
    cin >> n;
    vector<bool> ans (n, false);
    for (int i = 0; i < n; i++) {
        cout << (int)ans[i];
    }
    cout << endl;
    solve(n, n, ans);
    return 0;
}