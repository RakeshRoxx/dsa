#include<bits/stdc++.h>
using namespace std;

// Recursive DP Solution
// TC = O(N * 4 * 3)
// SC = O(N * 4) + O(N)
int f(int day, int lastTask, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if (day == 0) {
        int maxi = INT_MIN;
        for (int currTask = 0; currTask < 3; currTask++) {
            if (lastTask != currTask) {
                maxi = max(maxi, points[0][currTask]);
            }
        }
        return maxi;
    }
    if (dp[day][lastTask] != -1) return dp[day][lastTask];
    int maxi = INT_MIN;
    for (int currTask = 0; currTask < 3; currTask++) {
        if (lastTask != currTask) {
            int point = points[day][currTask] + f(day - 1, currTask, points, dp);
            maxi = max(point, maxi);
        }
    }
    return dp[day][lastTask] = maxi;
}


void solution() {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> points[i][j];
        }
    }
    //vector<vector<int>> dp(n, vector<int>(4, -1));
    // cout << f(n - 1, 3, points, dp);

    // Tabulation Solution
    // TC = O(N * 4 * 3)
    // SC = O(N * 4)
    /*
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            int maxi = INT_MIN;
            for (int task = 0; task <= 2; task++) {
                if (last != task) {
                    int point = points[day][task] + dp[day - 1][task];
                    maxi = max(maxi, point);
                }
            }
            dp[day][last] = maxi;
        }
    }
    cout << dp[n - 1][3];
    */

    // Space Optimiza Solution
    // TC = O(n * 4 * 3)
    // SC = O(4)
    vector<int> prev(4);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
    for (int day = 1; day < n; day++) {
        vector<int> temp(4);
        for (int last = 0; last < 4; last++) {
            int maxi = INT_MIN;
            for (int task = 0; task <= 2; task++) {
                if (last != task) {
                    int point = points[day][task] + prev[task];
                    maxi = max(maxi, point);
                }
            }
            temp[last] = maxi;
        }
        prev = temp;
    }
    cout << prev[3];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solution();
    return 0;
}