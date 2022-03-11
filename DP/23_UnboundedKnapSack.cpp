#include<bits/stdc++.h>
int solve(int idx, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp) {
    if (idx == 0) {
        if (w >= weight[0]) {
            return (w / weight[0]) * profit[0];
        } else {
            return 0;
        }
    }
    if (dp[idx][w] != -1) return dp[idx][w];
    int notTake = 0 + solve(idx - 1, w, profit, weight, dp);
    int take = INT_MIN;
    if (w >= weight[idx])
        take = profit[idx] + solve(idx, w - weight[idx], profit, weight, dp);
    return dp[idx][w] = max(notTake, take);
}


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
//     vector<vector<int>> dp(n, vector<int> (w+1, -1));
//     return solve(n-1, w, profit, weight, dp);
//     vector<vector<int>> dp(n, vector<int> (w + 1, 0));
//     for(int wt = 0; wt <= w; wt++){
//         if(wt >= weight[0]){
//             dp[0][wt] = (wt / weight[0]) * profit[0];
//         }
//     }
//     for(int idx = 1; idx < n; idx++){
//         for(int wt = 0; wt <= w; wt++){
//             int notTake = dp[idx-1][wt];
//             int Take = INT_MIN;
//             if(wt >= weight[idx]){
//                 Take = profit[idx] + dp[idx][wt - weight[idx]];
//             }
//             dp[idx][wt] = max(Take, notTake);
//         }
//     }
//     return dp[n-1][w];

//     vector<int> prev(w + 1, 0);
//     for(int wt = 0; wt <= w; wt++){
//         if(wt >= weight[0]){
//             prev[wt] = (wt / weight[0]) * profit[0];
//         }
//     }
//     for(int idx = 1; idx < n; idx++){
//         vector<int> curr(w + 1, 0);
//         for(int wt = 0; wt <= w; wt++){
//             int notTake = prev[wt];
//             int Take = INT_MIN;
//             if(wt >= weight[idx]){
//                 Take = profit[idx] + curr[wt - weight[idx]];
//             }
//             curr[wt] = max(Take, notTake);
//         }
//         prev = curr;
//     }
//     return prev[w];

    vector<int> prev(w + 1, 0);
    for (int wt = 0; wt <= w; wt++) {
        if (wt >= weight[0]) {
            prev[wt] = (wt / weight[0]) * profit[0];
        }
    }
    for (int idx = 1; idx < n; idx++) {
//         vector<int> curr(w + 1, 0);
        for (int wt = 0; wt <= w; wt++) {
            int notTake = prev[wt];
            int Take = INT_MIN;
            if (wt >= weight[idx]) {
                Take = profit[idx] + prev[wt - weight[idx]];
            }
            prev[wt] = max(Take, notTake);
        }
    }
    return prev[w];
}
