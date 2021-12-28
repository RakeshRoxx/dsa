#include<bits/stdc++.h>
using namespace std;
/*
Input Graph ->
6 9
1 2 2
2 3 3
2 6 7
2 4 3
6 3 8
3 4 5
4 1 1
1 5 4
4 5 9

TC -> O(E log(E)) + O(E * 4 alpha) = O(E log E),  Sorting + Disjoint Set
SC -> O(E) + O(N) + O(N),  Edges + Parent Array + Rank Array
*/



vector<int> parent;
vector<int> rankArr;

int find(int val) {
	if (parent[val] == val)
		return val;
	return parent[val] = find(parent[val]);
}

void unionSet(int u, int v) {
	u = find(u);
	v = find(v);
	if (rankArr[u] < rankArr[v])
		parent[u] = v;
	else if (rankArr[v] < rankArr[u])
		parent[v] = u;
	else {
		parent[u] = v;
		rankArr[v]++;
	}
}



void solution() {
	int n, e;
	cin >> n >> e;
	vector<pair<int, pair<int, int>>> edges;
	for (int i = 0; i < e; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back({wt, {u, v}});
	}
	parent.resize(n + 1);
	rankArr.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		// rankArr[i] = 0;
	}
	sort(edges.begin(), edges.end());
	vector<pair<int, pair<int, int>>> mst;
	for (auto &it : edges) {
		int wt = it.first;
		int u = it.second.first;
		int v = it.second.second;
		if (find(u) != find(v)) {
			unionSet(u, v);
			mst.push_back({u, {v, wt}});
		}
	}
	for (auto &it : mst) {
		// cout << "U = " << it.first << " V = " << it.second.first << " Wt = " << it.second.second << endl;
		cout << it.first << " " << it.second.first << " " << it.second.second << endl;
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