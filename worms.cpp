#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> buckets;
    int count = 0;
    int N = 1;  
    while (n--) {
        int a;
        std::cin >> a;
        count += a;
        buckets.push_back(count);
    }
    int t;
    cin >> t;
    while (t--) {
        int w;
        cin >> w;
        auto it = lower_bound(buckets.begin(), buckets.end(), w);
        int idx = it - buckets.begin();
        idx++;
        cout << idx << endl;
        
    }
    return 0;
}