#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            int difference = a - b;
            a -= difference * 2;
            b -= difference;
            if (b < 0 || a < 0) {
                cout << "NO" << endl;
                continue;
            }
        } else if (b > a) {
            int difference = b - a;
            b -= difference * 2;
            a -= difference;
            if (b < 0 || a < 0) {
                cout << "NO" << endl;
                continue;
            }
        }
        if (a % 3 == 0) {
            cout << "YES" <<endl;
        } else {
            cout << "NO" <<endl;
        }
    }
    return 0;
}