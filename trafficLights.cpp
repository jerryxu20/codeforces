#include <bits/stdc++.h>
using namespace std;


int main() {
    int x, n;
    cin >> x >> n;
    map<int, int> maxes;
    maxes[x]++;
    set<int> nums;
    nums.insert(0);
    nums.insert(x);
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        auto it = nums.upper_bound(d);
        int upper = *it;
        it--;
        int lower = *it;
        if(--maxes[upper - lower] == 0) {
            maxes.erase(upper - lower);
        }
        nums.insert(d);
        maxes[upper - d]++;
        maxes[d - lower]++;
        auto it2 = --maxes.end();
        cout << it2->first << endl;
    } 
    return 0;
}