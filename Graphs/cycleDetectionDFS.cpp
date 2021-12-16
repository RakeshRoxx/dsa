#include<bits/stdc++.h>
using namespace std;

bool cycleDetectDFS(int source, int parent, vector<bool> &visited, vector<int> list[]) {
	visited[source] = true;
	for (auto &it : list[source]) {
		if (not visited[it]) {
			if (cycleDetectDFS(it, source, visited, list)) return true;
		} else {
			if (parent != it) {
				return true;
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
		if (not visited[i]) {
			if (cycleDetectDFS(i, -1, visited, list))
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