#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    set<int> kids;
    for (int i = 1; i <= n; i++) {
        kids.insert(i);
    }
    int kid = 0;
    while (! kids.empty()) {
        auto it = kids.upper_bound(kid);
        advance(it, 1000);
        // if (it == kids.end()) {
            // it = kids.begin();
        // }
        // it++;
        // if (it == kids.end()) {
        //     it = kids.begin();
        // }
        kid = *it;
        cout << kid << endl;
        kids.erase(it);
    }

    return 0;
}