#include<bits/stdc++.h>
using namespace std;

// TC - O(N + E) * log N    BFS + Min Heap(Priority Queue)
// SC - O(N) + O(N)  Priority Queue and Dist Array


void shortestPath(int src, int N, vector<pair<int, int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> dist(N + 1, INT_MAX);
    dist[src] = 0;
    q.push({0, src});
    while (not q.empty()) {
        auto node = q.top();
        q.pop();
        for (auto &it : adj[node.second]) {
            if (it.second + node.second < dist[it.first]) {
                dist[it.first] = node.first + it.second;
                q.push({dist[it.first], it.first});
            }
        }
    }
    cout << "Shortest Path to All node from Source " << src << " is: ";
    for (int i = 1; i <= N; i++)
        cout << dist[i] << " ";
}


void solution() {
    int N, E;
    cin >> N >> E;
    vector<pair<int, int>> adj[N + 1];
    while (E--) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    shortestPath(1, N, adj);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solution();
    return 0;
}