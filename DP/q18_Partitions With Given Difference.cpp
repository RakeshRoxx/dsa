#include<bits/stdc++.h>
/*
    https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

*/


int mod = (int)1e9 + 7;
int fun(int idx, int sum, vector<int> &arr, vector<vector<int>> &dp) {
    if (idx == 0) {
        if (sum == 0 and arr[0] == 0) return 2;
        if (sum == 0 or arr[0] == sum) return 1;
        return 0;
    }
    if (dp[idx][sum] != -1) return dp[idx][sum];
    int notTake = fun(idx - 1, sum, arr, dp);
    int Take = 0;
    if (arr[idx] <= sum)
        Take = fun(idx - 1, sum - arr[idx], arr, dp);
    return dp[idx][sum] = (Take + notTake) % mod;
}




int countPartitions(int n, int d, vector<int> &arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    int target = (total - d);
    if (target < 0) return 0;
    if (target % 2 != 0) return 0;
    target /= 2;
    // vector<vector<int>> dp(n, vector<int> (target + 1, -1));
    // return fun(n - 1, target, arr, dp);

    // vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    // if (arr[0] == 0) {
    //     dp[0][0] = 2;
    // } else {
    //     dp[0][0] = 1;
    // }
    // if (arr[0] != 0 and arr[0] <= target)
    //     dp[0][arr[0]] = 1;
    // for (int i = 1; i < n; i++) {
    //     for (int sum = 1; sum <= target; sum++) {
    //         int notTake = dp[i - 1][sum];
    //         int take = 0;
    //         if (arr[i] <= sum)
    //             take = dp[i - 1][sum - arr[i]];
    //         dp[i][sum] = (take + notTake) % mod;
    //     }
    // }
    // return dp[n - 1][target];

    //Space optimize solution

    vector<int> prev(target + 1, 0);
    if (arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;

    if (arr[0] != 0 and arr[0] <= target)
        prev[arr[0]] = 1;
    for (int i = 1; i < n; i++) {
        vector<int> curr(target + 1, 0);
        for (int sum = 0; sum <= target; sum++) {
            if (sum >= arr[i])
                curr[sum] = prev[sum] + prev[sum - arr[i]];
            else
                curr[sum] = prev[sum];
        }
        prev = curr;
    }
    return prev[target];

}


