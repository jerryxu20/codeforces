#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, p; 
    cin >> n >> p;
    map<int, int> tickets;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        tickets[a]++;
    }
    for (int i = 0; i < p; i++) {
        int t;
        cin >> t;
        auto it = tickets.upper_bound(t);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
            continue;
        }
        it--;
        if (it->first > t) {
            cout << -1 << '\n';
        } else {
            cout << it->first << '\n';
            if(--it->second == 0) {
                tickets.erase(it);
            }
        }
    }
    return 0;
}