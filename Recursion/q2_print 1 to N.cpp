#include<bits/stdc++.h>
using namespace std;

void print(int n) {
    if (n == 0) return;
    print(n - 1);
    cout << n << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    print(n);
    return 0;
}