#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int count = 0;
    int t = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans.push_back(a);
        if (i == k - 1) {
            t = a;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] >= t && ans[i] > 0) {
            count++;
        }
    }
    cout << count << endl;
}