#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > t) {
            continue;
        }
        if (m[t - v[i]] > 0) {
            cout << i + 1 << ' ' << m[t - v[i]];
            return 0;
        }
        m[v[i]] = i + 1;
    }
    cout << "IMPOSSIBLE";
    return 0;
}