#include <bits/stdc++.h>
using namespace std;


int main() {
    int d, s;
    cin >> d >> s;
    if (s <= 0 && d != 1) {
        cout << "-1 -1";
        return 0;
    }
    vector<int> digits;
    while (s >= 9) {
        digits.push_back(9);
        s -= 9;
    }
    if (s > 0) {
        digits.push_back(s);
    }
    if ((int) digits.size() > d) {
        cout << "-1 -1";
        return 0;
    }
    while ((int) digits.size() < d) {
        digits.push_back(0);
    }
    long long large = 0;
    for (int digit: digits) {
        large *= 10;
        large += digit;
    }
    vector<int> newDigits = digits;
    sort(digits.begin(), digits.end());
    if (digits[0] == 0) {
        for (int i = 1; i < (int) digits.size(); i++) {
            if (digits[i] != 0) {
                digits[i]--;
                digits[0] = 1;
                break;
            }
        }
    }
    for (int i: digits) {
        cout << i;
    }
    cout << ' ';
    sort(newDigits.begin(), newDigits.end(), greater<int>());
    for (int i: newDigits) {
        cout << i;
    }
    return 0;
}