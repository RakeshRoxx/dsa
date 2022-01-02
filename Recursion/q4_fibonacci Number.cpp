#include<bits/stdc++.h>
using namespace std;

int findFibo(int n) {
    if (n <= 1)
        return n;
    return findFibo(n - 1) + findFibo(n - 2);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << findFibo(20);
    return 0;
}