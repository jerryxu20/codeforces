#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

bool found(string &s, string a, string b) {
    int idx = s.find(a);
    if (idx == -1) return false;
    int idx2 = s.find(b, idx + 2);
    if (idx2 == -1) return false;
    return true;
}

int main() {
    string s;
    cin >> s;
    if (found(s, "AB", "BA") || found(s, "BA", "AB")) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}