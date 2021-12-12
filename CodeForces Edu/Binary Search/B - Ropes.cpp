#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;
bool check(double val) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += floor(arr[i] / val);
    }
    return s >= k;
}


void solution() {
    cin >> n >> k;
    arr.resize(n);
    for (auto &it : arr) cin >> it;
    double l = 0, r = 1e8;
    for (int i = 1; i <= 100; i++) {
        double  mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << setprecision(20) << l;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solution();
    return 0;
}