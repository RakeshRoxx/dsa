#include<bits/stdc++.h>
using namespace std;

// TC = O(2^n)  exponention tc
// for every index there are two choices( recursive fun call )
// for n==2 _ _ _ = 2 2 2 = 2 ^ 3 (fun calls)


int sizeArr;

void printSubsequence(int idx, vector<int> &ans, vector<int> &arr) {
    if (idx == sizeArr) {
        if (ans.empty()) {
            cout << "{}\n";
            return;
        }
        for (auto &it : ans)
            cout << it << " ";
        cout << endl;
        return;
    }
    //take the current index
    ans.push_back(arr[idx]);
    printSubsequence(idx + 1, ans, arr);
    ans.pop_back();

    //don't take the current index
    printSubsequence(idx + 1, ans, arr);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    sizeArr = n;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it;
    vector<int> ans;
    printSubsequence(0, ans, arr);
    return 0;
}