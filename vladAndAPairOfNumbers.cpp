    #include <bits/stdc++.h>
    using namespace std;

    #define rep(i, a, b) for(int i = a; i < (b); ++i)
    #define all(x) begin(x), end(x)
    #define sz(x) (int)(x).size()
    typedef long long ll;
    typedef pair<int, int> pii;

    #define pb push_back
    #define mp make_pair

    void solve(int x) {
            ll first = x;
            ll second = 0;
            if (x % 2 == 1) {
                cout << -1 << endl;
                return;
            }
            for (int i = 30; i > 0; i--) {
                if (x & (1 << i)) {
                    if (x & (1 << (i - 1))) {
                        cout << -1 << endl;
                        return;
                    }
                    first += (1 << (i - 1));
                    second += (1 << (i - 1));
                };
            }
            cout << first << " " << second << endl;
            // cout << (first + second) / 2 << " " << x << endl;
            // cout << (first ^ second) << " " << x << endl;
            return;
    }


    int main() {
        ll t, x;
        cin >> t;
        while (t--) {
            cin >> x;
            solve(x);
            
        }
        return 0;
    }