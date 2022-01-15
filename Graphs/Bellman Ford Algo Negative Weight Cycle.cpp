#include<bits/stdc++.h>
using namespace std;
/*
To get shortest path from single source to all other nodes.
It's also used to detect negative cycle in a graph
*/


struct node {
    int u;
    int v;
    int wt;
    node(int _u, int _v, int _wt) {
        u = _u;
        v = _v;
        wt = _wt;
    }
};


void solution() {
    int n, e;
    cin >> n >> e;
    vector<node> edges;
    while (e--) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    int src;
    cin >> src;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto &edge : edges) {
            if (dist[edge.v] == INT_MAX) continue; // Edge Case
            if (dist[edge.u] + edge.wt < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.wt;
            }
        }
    }
    bool neg = false;
    for (auto &edge : edges) {
        if (dist[edge.u] + edge.wt < dist[edge.v]) {
            cout << "Negative Cycle";
            neg = true;
            break;
        }
    }
    if (not neg) {
        for (int x : dist)
            cout << x << " ";
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