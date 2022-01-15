#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MAX = 1e12;

void floydWarshall(int n, vector<vector<ll>> &graph) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][k] == MAX or graph[k][j] == MAX) continue;
				else if (graph[i][k] + graph[k][j] < graph[i][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}


void solution() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<ll>> graph(n + 1, vector(n + 1, MAX));
	int pos = 1;
	while (pos <= n) {
		graph[pos][pos] = 0;
		pos++;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		ll wt;
		cin >> u >> v >> wt;
		graph[u][v] = min(graph[u][v], wt);
		graph[v][u] = min(graph[v][u], wt);
	}
	floydWarshall(n, graph);
	while (q--) {
		int u, v;
		cin >> u >> v;
		if (graph[u][v] >= MAX)
			cout << "-1";
		else
			cout << graph[u][v];
		cout << "\n";
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