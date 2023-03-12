#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int solve() {
    string s;
    int n;
    cin >> n >> s;
    int low = 0;
    int high = n - 1;
    while(low <= high) {
        if (s[low] != s[high]) {
            s[low] = 'A';
        }
        low++;
        high--;
    }
    int ans = 0;
    bool run = false;
    for (char &c: s) {
        // cout << c  << " ";
        if (c == 'A') {
            run = true;
            continue;
        }
        if (run) {
            ans++;
            run = false;
        }
    }
    // cout << endl;
    if (ans <= 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

int main() {
    int tcase;
    cin >> tcase;
    while(tcase--) {
        solve();
    }
    return 0;
}