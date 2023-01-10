#include <bits/stdc++.h>
using namespace std;

// if number is prime squared, it is t prime. I checked primality of square with loop. Answer says to precompute, and then binary search
// I considered that, but there are 43 000 primes and I thought too many. Is editorial saying precompute during program, or by itself then paste.

bool isPrime(long long s) {
    if (s <= 3) return true;
    if (s % 2 == 0) return false;
    long long d = 3;
    while (d * d <= s) {
        if (s % d == 0) return false;
        d+=2;
    }
    return true;
}


void solve() {
    long long a; 
    cin >> a;
    long long s = sqrt(a);
    if (a > 1 && s * s == a && isPrime(s)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}