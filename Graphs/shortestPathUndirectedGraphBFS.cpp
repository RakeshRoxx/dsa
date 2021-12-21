#include<bits/stdc++.h>
using namespace std;

// TC - O(N + E)
// SC - O(N) Dist + O(N) Queue + O(N + E) List

void shortestPath(int src, vector<int> &dist, vector<int> list[]) {
	queue<int> q;
	q.push(src);
	dist[src] = 0;
	while (not q.empty()) {
		int node = q.front();
		q.pop();
		for (auto &it : list[node]) {
			if (dist[node] + 1 < dist[it]) {
				dist[it] = dist[node] + 1;
				q.push(it);
			}
		}
	}
}


void solution() {
	int N, E;
	cin >> N >> E;
	vector<int> list[N + 1];
	vector<int> dist(N + 1, INT_MAX);
	for (int i = 1; i <= E; i++) {
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}
	shortestPath(1, dist, list);
	for (int i = 1; i <= N; i++) {
		cout << dist[i] << " ";
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