#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }
    if (n == 1) {
        cout << books[0] * 2 << endl;
        return 0;
    }
    sort(books.begin(), books.end());
    long long left_time = 0;
    long long right_time = 0;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        if (left_time < right_time) {
            left_time += books[left];
            left++;
        } else {
            right_time += books[right];
            right--;
        }

    }
    if ((right == n - 2 && right_time > left_time) || (left == 1 && left_time > right_time)) {
        cout << left_time + right_time + abs(right_time - left_time);
        return 0;
    }
    cout << left_time + right_time;
    return 0;
}

// 2, 3, 8
// 8, 2, 3
// 2 5 13
// 9
