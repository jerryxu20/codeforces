#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int len = s.length();
        if (len > 10) {
            cout << s[0] << len - 2 << s[len - 1] << endl;
        } else {
            cout << s << endl;
        }
    }
}