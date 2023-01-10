#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<string>& perms, string &ans, vector<int>&oc, int n) {
    if (ans.length() == n) {
        perms.push_back(ans);
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (oc[i] > 0) {
            oc[i]--;
            ans += char(i + (int)'a');
            backtrack(perms, ans, oc, n);
            ans.pop_back();
            oc[i]++;
        }
    }
    return;
}


int main() {
    string s;
    cin >> s;
    vector<int> oc(26, 0);
    string ans = "";
    vector<string>perms;
    for (char &c: s) {
        oc[int(c - 'a')]++;
    }
    backtrack(perms, ans, oc, s.length());
    cout << perms.size() << endl;
    for (string& t: perms) {
        cout << t << endl;
    }
}


