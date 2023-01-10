#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    for (int _a = 0; _a < t; _a++) {
        int n;
        int m;
        cin >> n >> m;
        vector<vector<char>> mat (n, vector<char>(m));
        // row, columns;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                cin >> mat[j][i];
            }
        }
        for (int j = 0; j < n; j++) {
            bool bad = false;
            for (int i = 0; i < m; i++) {
                if (mat[j][i] == '*') {
                    int count = 1;
                    if (mat[j][i + 1] == '*') {
                        count++;
                    }
                    if (mat[j + 1][i] == '*') {
                        count++;
                    }
                    if (mat[j + 1][i + 1] == '*') {
                        count++;
                    }
                    if (count != 3) {
                        bad = true;
                        break;
                    }
                    if (mat[j][i + 1] == '*') {
                        mat[j][i + 1] = '+';
                    } else {
                        mat[j - 1][i + 2] = '*';
                    }
                    if (mat[j + 1][i] == '*') {
                        mat[j + 1][i] = '.';
                    } else {
                        mat[j + 2][i - 1] = '.'
                    }
                    if (mat[j + 1][i + 1] == '*') {
                        mat[j + 1][i] = '+';
                    } else {
                        mat[j + 2][i + 2] = '.';
                    }
                    for (int x = max(i - 1, 0); x < n && x <= i + 2; x++) {
                        if (mat[j - 1][x] == '*') {
                            bad = true;
                            break;
                        }
                        mat[j - 1][x] = '+'; 
                    }
                    for (int x = max(i - 1, 0); x < n && x <= i + 2; x++) {
                        if (mat[j + 2][x] == '*') {
                            bad = true;
                            break;
                        }
                        mat[j + 2][x] = '+';
                    }
                    mat[i - 1][j] = '+';
                    mat[i - 1][j + 1] = '+';
                    mat[i + 2][j] = '+';
                    mat[i + 2][j + 1] = '+';


                    //mark surroundings as bad
                    mat[j][i]

                }
            }
            if (bad) {
                break;
            }
        }
    }
    return 0;
}