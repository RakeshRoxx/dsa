#include<bits/stdc++.h>
using namespace std;

void binarySearch(vector<int> &arr, int k) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == k) {
            cout << "YES\n";
            return;
        } else if (arr[mid] > k) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << "NO\n";
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
        binarySearch(arr, value);
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