#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, l;
    cin >> n >> l;
    vector<int> distances (n);
    for (int i = 0; i < n; i++) {
        cin >> distances[i];
    }
    sort(distances.begin(), distances.end());
    float mx = -1;
    mx = max(mx, (float) distances[0]);
    mx = max(mx, (float) l - distances.back());
    for (int i = 1; i < n; i++) {
        mx = max(mx, (distances[i] - distances[i - 1]) / (float)2.0);
    }
    cout << setprecision(10) << mx;
    return 0;
}