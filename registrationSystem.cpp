#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    map<string, int> names;
    while (n--) {
        string s;
        cin >> s;
        int num = names[s]++;
        if (num == 0) {
            cout << "OK" << endl;
        } else {
            cout << s + to_string(num) << endl;
        }
    }
    return 0;
}