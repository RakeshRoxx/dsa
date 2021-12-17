#include<bits/stdc++.h>
using namespace std;

// TC - O(N + E)
// SC - O(N+E) Graph  + O(N) Color + O(N) Auxilary Stack


bool bipartideDFS(int src, int col, vector<int> &color, vector<int> list[]) {
	color[src] = col;
	for (auto &it : list[src]) {
		if (color[it] == -1) {
			color[it] = 1 - col;
			if (not bipartideDFS(it, color[it], color, list)) return false;
		} else {
			if (col == color[it]) {
				return false;
			}
		}
	}
	return true;
}


void solution() {
	int N, E;
	cin >> N >> E;
	vector<int> list[N + 1];
	vector<int> color(N + 1, -1);
	for (int i = 1; i <= E; i++) {
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}
	for (int i = 0; i < N; i++) {
		if (color[i] == -1) {
			if (not bipartideDFS(i, 1, color, list)) {
				cout << "False";
				return;
			}
		}
	}
	cout << "True";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solution();
	return 0;
}