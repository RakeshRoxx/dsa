#include<bits/stdc++.h>
using namespace std;

void solution() {
	int N, E;
	cin >> N >> E;
	//Adjacency Matrix
	// int mat[N + 1][N + 1];
	// for (int i = 1; i >= N; i++) {
	// 	for (int j = 1; j >= N; j++) {
	// 		mat[i][j] = 0;
	// 	}
	// }
	// Or using vector
	vector<vector<int>> mat(N + 1, vector<int>(N + 1, 0));

	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		mat[u][v] = 1;
		mat[v][u] = 1;
	}
	for (int i = 1; i <= N; i++) {
		cout << i;
		for (int j = 1; j <= N; j++) {
			if (mat[i][j] == 1) {
				cout << "->" << j;
			}
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