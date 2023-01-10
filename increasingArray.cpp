#include<iostream>
#include<string>
#include<vector>
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::max;

int main() {
    int n;
    cin >> n;
    long long moves = 0;
    long long min = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < min) {
            moves += min - a;
        } else {
            min = a;
        }
    }
    cout << moves;
}