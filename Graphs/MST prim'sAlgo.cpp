#include<bits/stdc++.h>
using namespace std;

void solution() {
	int N, E;
	cin >> N >> E;
	vector<pair<int, int>> adj[N];
	for (int i = 0; i < E; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		adj[u].push_back({v, wt});
		adj[v].push_back({u, wt});
	}
	vector<int> parent(N, -1);
	vector<int> key(N, INT_MAX);
	vector<bool> mst(N, false);
	key[0] = 0;
	for (int i = 0; i < N - 1; i++) {
		int mini = INT_MAX, u;
		for (int v = 0; v < N; v++) {
			if (mst[v] == false and key[v] < mini) {
				mini = key[v];
				u = v;
			}
		}
		mst[u] = true;
		for (auto &it : adj[u]) {
			int node = it.first;
			int wt = it.second;
			if (not mst[node] and wt < key[node]) {
				key[node] = wt;
				parent[node] = u;
			}
		}
	}
	int weight = 0;
	for (int i = 1; i < N; i++) {
		weight += key[i];
		cout << i << "->" << parent[i] << " Weight = " << key[i] << endl;
	}
	cout << "Weight=" << weight;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solution();
	return 0;
}