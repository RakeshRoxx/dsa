#include<bits/stdc++.h>
using namespace std;

// TC - O(N + E) * 2 Topo + BFS
// SC - O(2N) Stack + Dist Array
// Aux - O(N) Topo Sort Recursion

void topoSort(int src, stack<int> &st, vector<bool> &vis, vector<pair<int, int>> adj[]) {
    vis[src] = true;
    for (auto &it : adj[src]) {
        if (not vis[it.first]) {
            topoSort(it.first, st, vis, adj);
        }
    }
    st.push(src);
}


void shortestPath(int src, int N, vector<pair<int, int>> adj[]) {
    stack<int> st;
    vector<bool> vis(N, false);
    for (int i = 0; i < N; i++)
        if (not vis[i])
            topoSort(i, st, vis, adj);

    vector<int> dist(N, INT_MAX);
    dist[src] = 0;
    while (not st.empty()) {
        int node = st.top();
        st.pop();
        if (dist[node] != INT_MAX) {
            for (auto &it : adj[node]) {
                if (dist[node] + it.second < dist[it.first]) {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }
    cout << "Shortest Path From " << src << " to all Nodes: ";
    for (auto &it : dist)
        cout << it << " ";
}

void solution() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    while (m--) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    shortestPath(0, n, adj);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solution();
    return 0;
}