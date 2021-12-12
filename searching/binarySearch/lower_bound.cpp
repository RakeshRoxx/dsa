#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int key) {
    int l = 0, r = arr.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid;
    }
    if (l < arr.size() and arr[l] < key)
        l++;
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
        // int pos = lower_bound(arr.begin(), arr.end(), value) - arr.begin();
        // cout << pos + 1 << "\n";
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