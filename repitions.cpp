#include<iostream>
#include<string>
#include<vector>
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::max;
int main() {
    string n;
    cin >> n;
    int mx = 0;
    int run = 0;
    char prev = 'A';
    for (char c: n) {
        if (c == prev) {
            run++;
        } else {
            mx = max(mx, run);
            prev = c;
            run = 1;
        }
    }
    mx = max(mx, run);
    cout << mx;
    return 0;
}