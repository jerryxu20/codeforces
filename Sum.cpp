#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

// https://codeforces.com/contest/257/problem/D

char opp(int flips, char c) {
    if (flips % 2 == 0) return c;
    if (c == '+') return '-';
    return '+';
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &num: nums) {
        cin >> num;
    }
    string ans;
    int carry = 0;
    while (sz(nums) > 1) {
        if (carry == 0) {
            ans += "+";
            carry += nums.back();
            nums.pop_back();
            continue;
        }
        if (carry >= nums.back()) {
            // I keep carry as if and subtract the back
            ans += '-';
            carry -= nums.back();
            nums.pop_back();
        } else {
            // I flip carry and I add the the back
            ans += "f+";
            carry = nums.back() - carry;
            nums.pop_back();
        }
    }
    if (carry == 0) {
        ans += '+';
    } else if (carry >= nums.back()) {
        // I keep carry as if and subtract the back
        ans += '-';
        carry -= nums.back();
    } else {
        // I flip carry and I add the the back
        ans += "f+";
        carry = nums.back() - carry;
    }
    reverse(all(ans));
    string res = "";
    int flips = 0;
    for (char &c: ans) {
        if (c == 'f') {
            flips++;
            continue;
        }
        res += opp(flips, c);
    }
    cout << res << endl;
    return 0;
}