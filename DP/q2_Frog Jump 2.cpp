#include<bits/stdc++.h>
using namespace std;

// Recursive Solution
int helper(int idx, vector<int> &arr, int n, vector<int> &dp, int k) {
    if (idx == 0) return 0;
    int val = INT_MAX;
    for (int i = 1; i <= k; i++) {
        int curr;
        if (idx - i >= 0)
            curr = helper(idx - i, arr, n, dp, k) + abs(arr[idx] - arr[idx - i]);
        val = min(val, curr);
    }
    return val;
}

// DP Solution Memoization
int helperDP(int idx, vector<int> &arr, int n, vector<int> &dp, int k) {
    if (idx == 0) return 0;
    if (dp[idx] != -1) return dp[idx];
    int val = INT_MAX;
    for (int i = 1; i <= k; i++) {
        int curr;
        if (idx - i >= 0)
            curr = helper(idx - i, arr, n, dp, k) + abs(arr[idx] - arr[idx - i]);
        val = min(val, curr);
    }
    return dp[idx] = val;
}


void solution() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> dp(n, -1);
    for (auto &it : arr) cin >> it;


    // Tabulation Solution
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int val = INT_MAX;
        for (int j = 1; j <= k; j++) {
            int curr;
            if (i - j >= 0) {
                curr = dp[i - j] + abs(arr[i] - arr[i - j]);
            }
            val = min(val, curr);
        }
        dp[i] = val;
    }
    cout << dp[n - 1];
}

/* ========== YOUR CODE HERE ========= */
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    solution();
    cout << "\n";
    return 0;
}