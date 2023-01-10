#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    map<int, int> towers;
    int resuses = 0;
    for (int i = 0; i < n; i++) { 
        int k;
        cin >> k;
        auto it = towers.upper_bound(k);
        if (it != towers.end()) {
            if(--it->second == 0) {
                towers.erase(it);
            }
            resuses++;
        }
        towers[k]++;
    }
    cout << n - resuses;
    return 0;
}