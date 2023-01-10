#include<vector>
#include<iostream>
using namespace std;

int main() {
    int n;
    int sum = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        sum = (2 * sum) % (int(1e9+7));
    }
    cout << sum;
}