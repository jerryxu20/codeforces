#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    long long cover = 0;
    for (int &coin: coins) {
        if ((long long) coin > cover + 1) {
            break;
        }
        cover += coin;
    }
    cout << cover + 1;
    return 0;
}