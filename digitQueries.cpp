#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        long long bucket = 9;
        long long digits = 1;
        while (a > bucket * digits) {
            a -= (bucket * digits); 
            bucket *= 10;
            digits++;
        }
        long long num = (bucket / 9 - 1) + ceil(a / (long double)digits);
        long long mod = (a - 1) % digits;
        string s = to_string(num);
        cout << s[mod] << endl;
    }
}