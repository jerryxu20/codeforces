#include <bits/stdc++.h>
using namespace std;


int main() {
    set<int> s;
    int n;
    cin >> n;
    while (!s.count(n)) {
        cout << n << endl;
        s.insert(n);
        if (n % 10 == 0) {
            n /= 10;
        } else {
            n++;
        }
    }
    cout << s.size();
    return 0;
}