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
    int n;
    cin >> n;
    int m = 2 * n - 2;
    vector<string>strs(m);
    for (auto &s: strs) {
        cin >> s;
    }
    sort(all(strs), [] (auto &a, auto &b) {
        return a.size() > b.size();
    });

    string s1 = strs[0];
    string s2 = strs[1];
    reverse(all(s2));
    if (s1 == s2) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
    

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}