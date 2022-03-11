#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int r) {
    vector<int> merged(r - l + 1);
    int idx1 = l;
    int idx2 = mid + 1;
    int x = 0;
    while (idx1 <= mid and idx2 <= r) {
        if (arr[idx1] <= arr[idx2])
            merged[x++] = arr[idx1++];
        else
            merged[x++] = arr[idx2++];
    }
    while (idx1 <= mid)
        merged[x++] = arr[idx1++];
    while (idx2 <= r)
        merged[x++] = arr[idx2++];
    for (int i = 0, j = l; i < merged.size(); i++, j++)
        arr[j] = merged[i];
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}


void solution() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
        cin >> it;
    mergeSort(arr, 0, n - 1);
    for (auto &it : arr)
        cout << it << " ";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solution();
    return 0;
}