#include<iostream>
#include<string>
#include<vector>
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::max;
using std::endl;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a;
        long long b;
        cin >> a >> b;
        // a is the row
        if (a >= b) {
            long long anchor = a * a - a + 1;
            // The row ends on anchor if it's even or the row starts on anchor if it's odd.
            if (a % 2 == 0) {
                cout << anchor + a - b << endl;
            } else {
                cout << anchor - a + b << endl;
            }
        } else {
            long long anchor = b * b - b + 1;
            // b increases if even and decreases if odd.
            if (b % 2 == 0) {
                cout << anchor - b + a << endl;
            } else {
                cout << anchor - a + b <<endl;
            }
        }
    }
    return 0;
}