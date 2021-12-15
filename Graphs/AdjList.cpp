#include<bits/stdc++.h>
using namespace std;

void solution() {
	int N, E;
	cin >> N >> E;
	vector<int> list[N + 1]; // 1-based indexing unweighted graph
	// vector<pair<int, int>> list[N + 1]; //weighted graph
	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		// list[v].push_back(u);
		// weighted graph
		// list[u].push_back({v, weight});
	}
	for (int i = 1; i <= N; i++) {
		cout << i;
		for (auto &it : list[i]) {
			cout << "->" << it;
		}
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