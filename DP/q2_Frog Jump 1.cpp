#include<bits/stdc++.h>
using namespace std;

//Recursive Solution
int helper(int idx, vector<int> &arr, int n) {
    if (idx == n - 1) return 0;
    int left = helper(idx + 1 , arr, n) + abs(arr[idx] - arr[idx + 1]);
    int right = INT_MAX;
    if (idx < n - 2)
        right = helper(idx + 2, arr, n) + abs(arr[idx] - arr[idx + 2]);
    return min(left, right);
}

// DP Solution

int helperDP(int idx, vector<int> &arr, int n, vector<int> &dp) {
    if (idx == n - 1) return 0;
    if (dp[idx] != -1) return dp[idx];
    int left = helper(idx + 1 , arr, n, dp) + abs(arr[idx] - arr[idx + 1]);
    int right = INT_MAX;
    if (idx < n - 2)
        right = helper(idx + 2, arr, n, dp) + abs(arr[idx] - arr[idx + 2]);
    return dp[idx] = min(left, right);
}

void solution() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it;
    // int ans = helper(0, arr, n);
    // cout << ans;
    int ansDP = helperDP(n - 1, arr, n, dp);
    cout << ansDP;
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