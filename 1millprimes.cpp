#include <bits/stdc++.h>
using namespace std;


bool isPrime(int n) {
    if (n <= 3) return true;
    if (n % 2 == 0) return false;
    for (int d = 3; d * d <= n; d += 2) {
        if (n % d == 0) return false;
    }
    return true;
}

int main() {
    for (int i = 1; i <= 1e6; i++) {
        if (isPrime(i)) {
            cout << i << ' ' ;
        }
    }
    return 0;
}