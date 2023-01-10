#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n;
    cin >> n;
    int ans = 0;
    while (n > 0) {
        int a = n % 10;
        n /= 10;
        if (a == 7 || a == 4) {
            ans++;
        }
    }
    if (ans == 0) {
        cout << "NO";
        return 0;
    }
    while (ans > 0) {
        int a = ans % 10;
        ans /= 10;
        if (a != 7 && a != 4) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}