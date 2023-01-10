#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

void tower(int n, int current, int empty, int goal, vector<pair<int, int>> &ans) {
    if (n == 1) {
        ans.pb(mp(current, goal));
        // cout << current << " " << goal << endl;
        return;
    }
    // since we want to get to goal we have to make sure it's freed up
    // in the end
    tower(n - 1, current, goal, empty, ans);
    ans.pb(mp(current, goal));
    // cout << current << " " << goal << endl;
    tower(n - 1, empty, current, goal, ans);
    return;
}

int main() {
    // there are three stacks L M R and n disks 
    // move all disks from L to R
    int n;
    vector<pair<int, int>> ans;
    cin >> n;
    tower(n, 1, 2, 3, ans);
    cout << ans.size() << endl;
    for (auto &p: ans) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}