#include<bits/stdc++.h>
using namespace std;

// TC - O(N + E)
// SC - O(N) Visited + O(N) Stack
// Aux - O(N)


void topoSort(int src, stack<int> &st, vector<bool> &vis, vector<int> list[]) {
	vis[src] = true;
	for (auto &it : list[src]) {
		if (not vis[it]) {
			topoSort(it, st, vis, list);
		}
	}
	st.push(src);
}


void solution() {
	int N, E;
	cin >> N >> E;
	vector<int> list[N + 1];
	vector<bool> vis(N + 1, false);
	stack<int> st;
	for (int i = 1; i <= E; i++) {
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
	}
	for (int i = 1; i <= N; i++) {
		if (not vis[i]) {
			topoSort(i, st, vis, list);
		}
	}
	while (not st.empty()) {
		cout << st.top() << " ";
		st.pop();
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