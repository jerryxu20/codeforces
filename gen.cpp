#include <bits/stdc++.h>
using namespace std;

long long rand(long long a, long long b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    cout << 1 << endl;
    int n = rand(2, 10);
    do {
        n = rand(2, 10);
    } while (n % 2 == 1);
    cout << n << endl;
    set<int> used;
    for (int i = 0; i < n/2; i++) {
        long long x;
        x = rand(1, n);
        cout << x << " ";
    }
    cout << endl;
    return 0;
}