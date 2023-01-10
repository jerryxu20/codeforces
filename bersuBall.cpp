#include <bits/stdc++.h>
using namespace std;


int main() {
    int b;
    cin >> b;
    vector<int> boys(b);
    for (int i = 0; i < b; i++) {
        cin >> boys[i];
    }
    int g;
    cin >> g;
    multiset<int> girls;
    for (int i = 0; i < g; i++) {
        int a;
        cin >> a;
        girls.insert(a);
    }
    sort(boys.begin(), boys.end());
    int ans = 0;
    for (int boy: boys) {
        auto it = girls.find(boy - 1);
        if (it != girls.end()) {
            girls.erase(it);
            ans++;
            continue;
        }
        it = girls.find(boy);
        if (it != girls.end()) {
            girls.erase(it);
            ans++;
            continue;
        }
        it = girls.find(boy + 1);
        if (it != girls.end()) {
            girls.erase(it);
            ans++;
        }
    }
    cout << ans;
    return 0;
}