#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

ll count_fact(int n, int d) {
    ll ans = 0;
    while(n % d == 0) {
        ans++;
        n /= d;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    ll twos = 0;
    ll fives = 0;
    for (int i = 5; i <= n; i+=5) {
        fives += count_fact(i, 5);
    }
    cout << fives << endl;
    return 0;
}
