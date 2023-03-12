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


int main() {
    // buses run from a to b
    // 5 am to 11:59
    int a, ta, b, tb;
    string time;
    cin >> a >> ta >> b >> tb;
    cin >> time;
    int start_time = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
    int end_time = start_time + ta;
    int ans = 0;
    for (int i = 5 * 60; i < 24 * 60; i += b) {
        if (i + tb <= start_time) continue;
        if (i >= end_time) break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}