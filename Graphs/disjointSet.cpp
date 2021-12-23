#include<bits/stdc++.h>
using namespace std;

int parent[1001];
int rankArr[1001];

void makeSet() {
	for (int i = 1; i <= 1000; i++) {
		parent[i] = i;
		rankArr[i] = 0;
	}
}

int findParent(int val) {
	if (val == parent[val])
		return val;
	// return findParent(parent[val]);
	return parent[val] = findParent(parent[val]);
}

void unionOfSet(int u, int v) {
	int parentOfU = findParent(u);
	int parentOfV = findParent(v);
	if (rankArr[parentOfU] < rankArr[parentOfV]) {
		parent[parentOfU] = parentOfV;
	} else if (rankArr[parentOfV] < rankArr[parentOfU]) {
		parent[parentOfV] = parentOfU;
	} else {
		parent[parentOfV] = parentOfU;
		rankArr[parentOfU]++;
	}
}

void solution() {
	makeSet();
	int m;
	cin >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		unionOfSet(u, v);
	}
	// to check if two element belong to same set then
	// find their parent (findParent()) if they are same then yes or no
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		u = findParent(u);
		v = findParent(v);
		if (u == v)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
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