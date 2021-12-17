#include<bits/stdc++.h>
using namespace std;

// TC - O(N + E)
// SC - O(N) Visited + O(N) Stack
// Aux - O(N)


void topoSort(int size, vector<int> &inDegree, vector<int> &ans, vector<int> list[]) {
	queue<int> q;
	for (int i = 1; i <= size; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}
	while (not q.empty()) {
		int node = q.front();
		ans.push_back(node);
		q.pop();
		for (auto &it : list[node]) {
			if (inDegree[it] > 0) {
				inDegree[it]--;
			}
			if (inDegree[it] == 0) {
				q.push(it);
			}
		}
	}
}


void solution() {
	int N, E;
	cin >> N >> E;
	vector<int> list[N + 1];
	vector<int> ans;
	vector<int> inDegree(N + 1, 0);
	for (int i = 1; i <= E; i++) {
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
	}
	for (int i = 1; i <= N; i++) {
		for (auto &it : list[i]) {
			inDegree[it]++;
		}
	}
	topoSort(N, inDegree, ans, list);
	for (auto &it : ans) {
		cout << it << " ";
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