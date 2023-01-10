#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> apartments;
    vector<int> desired;
    // this is n + m
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        desired.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        apartments.push_back(a);
    }
    sort(desired.begin(), desired.end());
    sort(apartments.begin(), apartments.end());
    int p = 0;
    int d = 0;
    // this is nlogn and mlogm
    int ans = 0;
    // this is lower of n + m
    while (p < m && d < n) {
        if (apartments[p] <= desired[d] + k && apartments[p] >= desired[d] - k) {
            ans++;
            p++;
            d++;
        } else if (apartments[p] > desired[d] + k) {
            d++;
        } else if (apartments[p] < desired[d] - k) {
            p++;
        }
    }
    cout << ans;
    return 0;
}