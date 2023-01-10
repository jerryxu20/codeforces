#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (a * m <= b) {
        cout << n * a;
        return 0;
    } else {
        int multi = n / m;
        n -= multi * m;
        int ans = multi * b;
        ans += min(a * n, b);
        cout << ans;
    }
 
    return 0;
}