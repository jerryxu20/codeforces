#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    // find when the array decreases
    int dec = -1;
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i - 1]) {
            dec = i - 1;
            break;
        }
    }
    if (dec == - 1) {
        cout << "yes" << endl;
        cout << 1 << ' ' << 1;
        return 0;
    }
    // find when the array increase from back
    int inc = -1;
    for (int i =  n - 2; i >= 0; i--) {
        if (nums[i] > nums[i + 1]) {
            inc = i + 1;
            break;    
        }
    }
    int low = dec;
    int high = inc;
    while (high >= low) {
        swap(nums[high], nums[low]);
        high--;
        low++;
    }
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i - 1]) {
            cout << "no";
            return 0;
        }
    }
    cout << "yes" << endl;
    cout << dec + 1 << ' ' << inc + 1;  
    return 0;
}


// 1, 2 , 3, 100, 90, 89, 20;