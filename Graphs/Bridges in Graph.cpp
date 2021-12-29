#include<bits/stdc++.h>
using namespace std;

/*
	TC - O(N + E) dfs
	Sc - O(N + E) + O(3N) adj + intime + lowtime + vis

	Ques.
		https://codeforces.com/problemset/problem/118/E
*/

vector<int> inTime, lowTime;
vector<bool> vis;
int timer = 1;

void dfs(int src, int parent, vector<int> adj[]) {
	vis[src] = true;
	inTime[src] = lowTime[src] = timer++;
	for (int child : adj[src]) {
		if (child == parent) continue;
		if (vis[child]) {
			lowTime[src] = min(lowTime[src], inTime[child]);
		} else {
			dfs(child, src, adj);
			if (lowTime[child] > inTime[src]) {
				cout << src << " -> " << child << " is a bridge.\n";
			}
			lowTime[src] = min(lowTime[src], lowTime[child]);
		}
	}
}

void solution() {
	int N, E;
	cin >> N >> E;
	vector<int> adj[N + 1];
	while (E--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	inTime.resize(N + 1);
	lowTime.resize(N + 1);
	vis.resize(N + 1, false);
	dfs(1, 0, adj);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solution();
	return 0;
}