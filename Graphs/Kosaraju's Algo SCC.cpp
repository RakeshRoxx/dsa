#include<bits/stdc++.h>
using namespace std;

/*
TC = O(N+E) + O(N+E) + O(N+E) = O(N+E)
    TopoSort + Transpose + DFS
SC = O(N+E) + O(N) + O(N)
    Adj List + Visited + Stack
*/

void topoSort(int src, stack<int> &st, vector<bool>&vis, vector<int> adj[]) {
    vis[src] = true;
    for (auto child : adj[src]) {
        if (not vis[child]) {
            topoSort(child, st, vis, adj);
        }
    }
    st.push(src);
}

void dfs(int src, vector<bool> &visited, vector<int> &ans, vector<int> transposeAdj[]) {
    visited[src] = true;
    ans.push_back(src);
    for (auto child : transposeAdj[src]) {
        if (not visited[child]) {
            dfs(child, visited, ans, transposeAdj);
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
    }
    stack<int> st;
    vector<bool> vis(N + 1, false);
    topoSort(1, st, vis, adj);
    // st.pop();
    // cout << st.size();

    vector<int> transposeAdj[N + 1];
    for (int i = 1; i <= N; i++) {
        for (auto child : adj[i]) {
            transposeAdj[child].push_back(i);
        }
    }
    vector<int> ans;
    vector<bool> visited(N + 1, false);
    while (not st.empty()) {
        int node = st.top();
        st.pop();
        if (not visited[node]) {
            dfs(node, visited, ans, transposeAdj);
            for (int x : ans)
                cout << x << " ";
            cout << "\n";
            ans.clear();
        }
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