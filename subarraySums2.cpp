#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n, x;
    cin >> n >> x;
    long long ans = 0;
    long long sum = 0;
    map<long long, long long> pre;
    pre[0] = 1;
    for (long long i = 0; i < n; i++) {
        long long a;
        cin >> a;
        sum += a;
        ans += pre[sum - x];
        pre[sum]++;
    }
    cout << ans;
    return 0;
}