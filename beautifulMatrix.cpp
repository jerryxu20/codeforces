#include <bits/stdc++.h>
using namespace std;


int main() {
    int row;
    int col;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                row = i;
                col = j;
            }
        }
    }
    int ans = abs(2 - col) + abs(2 - row);
    cout << ans;
    return 0;
}