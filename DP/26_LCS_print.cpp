#include<bits/stdc++.h>
using namespace std;
// TC = O(n * m) + O(n + m)
// SC = O(n * m)


void solution() {
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    // base cases
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << "LCS = ";
    cout << dp[n][m] << endl;
    int i = n, j = m;
    string ans = string(dp[n][m], ' ');
    int idx = dp[n][m] - 1;
    while (i > 0 and j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans[idx--] = s[i - 1];
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << "The LCS is = " << ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solution();
    return 0;
}