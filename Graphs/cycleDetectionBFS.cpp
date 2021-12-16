#include<bits/stdc++.h>
using namespace std;

bool cycleCheckBfs(int source, vector<bool> &visited, vector<int> list[]) {
	queue<pair<int, int>> q;
	q.push({source, -1});
	visited[source] = true;
	while (not q.empty()) {
		auto node = q.front();
		q.pop();
		for (auto &it : list[node.first]) {
			if (not visited[it]) {
				visited[it] = true;
				q.push({it, node.first});
			} else {
				if (node.second != it) {
					return true;
				}
			}
		}
	}
	return false;
}



void solution() {
	int N, E;
	cin >> N >> E;
	vector<int> list[N + 1];
	vector<int> ans;
	vector<bool> visited(N + 1, false);
	for (int i = 0; i <= E; i++) {
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}
	int cycle = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			if (cycleCheckBfs(i, visited, list))
				cycle++;
		}
	}
	cout << cycle;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solution();
	return 0;
}