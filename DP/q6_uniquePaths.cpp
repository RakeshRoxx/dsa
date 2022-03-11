#include<bits/stdc++.h>
using namespace std;

// Recursive DP solution
// TC = O(m * n);
// SC = O(m * n) + O(m * n)
bool inside(int x, int y, int row, int col) {
    return x >= 0 and x < row and y >= 0 and y < col;
}

int fun(int x, int y, int row, int col, vector<vector<int>> &dp) {
    if (x == row - 1 and y == col - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];
    int down = 0 , right = 0;
    if (inside(x + 1, y, row, col))
        down = fun(x + 1, y, row, col, dp);
    if (inside(x, y + 1, row, col))
        right = fun(x, y + 1, row, col, dp);
    return dp[x][y] = down + right;
}

void solution() {
    /*
        Tabulation
        TC = O(m * n)
        SC = O(m * n)
    */
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // return fun(0, 0, m, n, dp);
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (i == 0 and j == 0) dp[i][j] = 1;
    //         else {
    //             int up = 0, left = 0;
    //             if (i > 0) {
    //                 up = dp[i - 1][j];
    //             }
    //             if (j > 0) {
    //                 left = dp[i][j - 1];
    //             }
    //             dp[i][j] = up + left;
    //         }
    //     }
    // }
    // return dp[m - 1][n - 1];
    // vector<int> dp(n, 0);

    /*
        Space Optimization
        TC = O(n * m)
        SC = O(m)
    */

    dp[0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 and j == 0) continue;
            else {
                int up = 0, left = 0;
                if (i > 0) up = dp[j];
                if (j > 0) left = dp[j - 1];
                dp[j] = up + left;
            }
        }
    }
    return dp[n - 1];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solution();
    return 0;
}