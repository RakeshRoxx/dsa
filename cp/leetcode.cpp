class Solution {
private:
    bool check(string &a, string &b) {
        // if(a == b) return false;
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) cnt++;
        }
        return cnt == 1;
    }

    vector<vector<string>> ans;

    void getPaths(int src, int dest, int len, int mini, vector<string> &dict, vector<int> adj[], vector<string> &curr) {
        if (len >= mini) return;
        if (src == dest and len == mini - 1) {
            curr.push_back(dict[src]);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        curr.push_back(dict[src]);
        for (int &x : adj[src]) {
            getPaths(x, dest, len + 1, mini, dict, adj, curr);
        }
        curr.pop_back();
    }
public:
    vector<vector<string>> findLadders(string start, string end, vector<string>& dict) {
        ans.clear();
        int n = dict.size() + 2;
        dict.insert(dict.begin(), start);
        dict.push_back(end);
        vector<int> adj[n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(dict[i], dict[j])) {
                    adj[i].push_back(j);
                }
            }
        }


        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({1, 0});
        vector<int> dist(n, INT_MAX);
        dist[0] = 1;
        while (not pq.empty()) {
            int wt = pq.top().first;
            int src = pq.top().second;
            pq.pop();
            if (dist[src] < wt) continue;
            for (int x : adj[src]) {
                if (wt + 1 < dist[x]) {
                    dist[x] = 1 + wt;
                    pq.push({dist[x], x});
                }
            }

        }
        vector<string> curr;
        getPaths(0, n - 1, 0, dist[n - 1], dict, adj, curr);
        // cout << dist[n - 1];
        return ans;
    }
};