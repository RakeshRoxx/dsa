#include<bits/stdc++.h>

int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
    if (i == 0 or j == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i - 1] == t[j - 1]) {
        return dp[i][j] = 1 + solve(i - 1, j - 1, s, t, dp);
    }
    return dp[i][j] = max(solve(i - 1, j, s, t, dp), solve(i, j - 1, s, t, dp));
}


int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
//     vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
//     return solve(n, m, s, t, dp);
//     vector<vector<int>> dp(n+1, vector<int>(m+1));
//     // base cases
//     for(int i=0;i<=n;i++)
//         dp[i][0] = 0;
//     for(int i=0;i<=m;i++)
//         dp[0][i] = 0;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(s[i-1] == t[j-1])
//                 dp[i][j] = 1 + dp[i-1][j-1];
//             else
//                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//         }
//     }
//     return dp[n][m];

    // 1 array solution
    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
}