#include<bits/stdc++.h>
using namespace std;

pair<int, int> pos = { -1, -1};

bool cycleDetect(int src, vector<int> &vis, vector<int> &dfsVis, vector<int> list[]) {
	vis[src] = 1;
	dfsVis[src] = 1;
	for (auto &it : list[src]) {
		if (vis[it] == 0) {
			if (cycleDetect(it, vis, dfsVis, list))
				return true;
		} else if (dfsVis[it]) {
			pos = {src, it};
			return true;
		}
	}
	dfsVis[src] = 0;
	return false;
}


void solution() {
	int N, E;
	cin >> N >> E;
	vector<int> list[N + 1];
	vector<int> vis(N + 1, 0);
	vector<int> dfsVis(N + 1, 0);
	for (int i = 1; i <= E; i++) {
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		// list[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		if (vis[i] == 0) {
			if (cycleDetect(i, vis, dfsVis, list)) {
				cout << pos.first << " " << pos.second << " ";
				cout << "True";
				return;
			}
		}
	}
	cout << "False";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solution();
	return 0;
}