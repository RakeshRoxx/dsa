#include<bits/stdc++.h>
using namespace std;

// TC - O(N + E)
// SC - O(N+E) Graph  + O(N) Color + O(N) Queue

bool bipartide(int src, vector<int> &color, vector<int> list[]) {
	queue<int> q;
	q.push(src);
	color[src] = 0;
	while (not q.empty()) {
		int node = q.front();
		q.pop();
		for (auto &it : list[node]) {
			if (color[it] == -1) {
				q.push(it);
				color[it] = (color[node] ^ 1);
			} else {
				if (color[it] == color[node]) {
					return false;
				}
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
			if (not bipartide(i, color, list)) {
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