#include<bits/stdc++.h>
using namespace std;

void dfs(int source, vector<bool> &visited, vector<int> list[], vector<int> &ans) {
	ans.push_back(source);
	visited[source] = true;
	for (auto &it : list[source]) {
		if (!visited[it]) {
			dfs(it, visited, list, ans);
		}
	}
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
		// list[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i, visited, list, ans);
		}
	}
	for (auto &it : ans)
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