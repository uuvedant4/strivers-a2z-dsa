class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>>adj[n + 1];

        for (int i = 0; i < times.size(); ++i) {
            int ui = times[i][0];
            int vi = times[i][1];
            int wt = times[i][2];

            adj[ui].push_back({wt, vi});
        }

        vector<int>dist(n + 1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto p : adj[u]) {
                int v = p.second;
                int wt = p.first;
                if (wt + dist[u] < dist[v]) {
                    dist[v] = wt + dist[u];
                    pq.push({dist[v], p.second});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < dist.size(); i++) {
            ans = max(ans, dist[i]);
        }
        if (ans == 1e9) return -1;
        return ans;
    }
};