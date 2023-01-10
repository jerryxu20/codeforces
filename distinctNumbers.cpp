#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    set<int> freq;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (freq.find(a) != freq.end()) {
            continue;
        }
        freq.insert(a);
        count++;
    }
    cout << count;
}