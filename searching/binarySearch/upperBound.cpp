#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int key) {
    int l = -1, r = arr.size();
    // if (key >= arr[r - 1])
    //     return r;
    // if (key < arr[l + 1])
    //     return 0;
    while (r > l + 1) {
        int mid = l + (r - l) / 2;
        if (key >= arr[mid]) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l + 1;
}

void solution() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &it : arr)
        cin >> it;
    while (k--) {
        int value;
        cin >> value;
        cout << binarySearch(arr, value) << "\n";
        // int pos = upper_bound(arr.begin(), arr.end(), value) - arr.begin();
        // cout << pos << "\n";
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solution();
    return 0;
}