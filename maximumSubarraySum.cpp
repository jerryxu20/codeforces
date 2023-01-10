#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    long long sum;
    long long ans;
    cin >> ans;
    sum = max(ans, (long long) 0);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        ans = max(ans, sum);
        sum = max((long long) 0, sum);
    }
    cout << ans;
    return 0;
}