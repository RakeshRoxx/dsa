#include<bits/stdc++.h>
using namespace std;

// TC - O(N + E)
// SC - O(N) InDegree + O(N) Queue + O(N + E) List


bool topoSort(int size, vector<int> &inDegree, vector<int> list[]) {
	queue<int> q;
	int count = 0;
	for (int i = 1; i <= size; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}
	while (not q.empty()) {
		int node = q.front();
		q.pop();
		count++;
		for (auto &it : list[node]) {
			if (inDegree[it] > 0) {
				inDegree[it]--;
			}
			if (inDegree[it] == 0) {
				q.push(it);
			}
		}
	}
	if (count == size) return true;
	else return false;
}


void solution() {
	int N, E;
	cin >> N >> E;
	vector<int> list[N + 1];
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
	if (topoSort(N, inDegree, list))
		cout << "No Cycle";
	else
		cout << "Has Cycle";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solution();
	return 0;
}