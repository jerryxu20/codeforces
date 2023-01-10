#include<iostream>
using std::cout;
using std::cin;


int main() {
    long long n;
    cin >> n;
    long long sum = 0;
    for (long long i = 1; i < n; i++) {
        long long a;
        cin >> a;
        sum += a;
    }
    cout << n * (n + 1) / 2 - sum;
    return 0;
}