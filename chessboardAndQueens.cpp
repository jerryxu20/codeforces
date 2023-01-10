#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

void backtrack(set<pair<int, int>> &disallowed, set<pair<int, int>> &diagonals, set<int> &row, int i, long long &ans) {
    if (i == 8) {
        ans++;
        return;
    }
    for (int j = 0; j < 8; j++) {
        if (row.count(j)) continue;
        pair<int, int> positive = mp(1, j - i);
        pair<int, int> negative = mp(-1, i + j);
        if (diagonals.count(positive) || diagonals.count(negative)) continue;
        if (disallowed.count(mp(i, j))) continue;
        // i j is allowed
        row.insert(j);
        diagonals.insert(negative);
        diagonals.insert(positive);
        backtrack(disallowed, diagonals, row, i + 1, ans);
        row.erase(j);
        diagonals.erase(negative);
        diagonals.erase(positive);
    }
}

int main() {
    char c;
    set<pair<int, int>> disallowed;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
           cin >> c;
           if (c == '*') {
                disallowed.insert(mp(i, j));
           }
        }
    }
    set<pair<int, int>> diagonals;
    set<int> row;
    ll ans = 0;
    backtrack(disallowed, diagonals, row, 0, ans);
    cout << ans << endl;

    // what each row the queen is in
    return 0;
}