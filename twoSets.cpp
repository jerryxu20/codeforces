#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main(void) {
    int n;
    cin >> n;
    if (n % 4 == 0) {
        cout << "YES" << endl;
        cout << n/2 << endl;
        for (int i = 0; i < n/4; i++) {
            cout << i + 1 << ' ' << n - i << ' ';
        }
        cout << endl;
        cout << n/2 << endl;
        for (int i = n/4; i < n/2; i++) {
            cout << i + 1 << ' ' <<  n - i << ' ';
        }
        cout << endl;
    } else if (n % 2 == 1) {
        if ((n - 1) % 4 == 0) {
            cout << "NO";
        } else {
            cout << "YES" << endl;
            cout << (n + 1) / 2 << endl;
            for (int i = 0; i < (n + 1) / 4; i++) {
                cout << i + 1 << ' ' << n - 1 - i << ' ';
            }
            cout << endl;
            cout << n / 2 << endl;
            for (int i = (n + 1)/4; i < n/2; i++) {
                cout << i + 1 << ' ' <<  n - 1 - i << ' ';
            }
            cout << n <<endl;
        }
    } else {
        cout << "NO";
    }
    return 0;
}