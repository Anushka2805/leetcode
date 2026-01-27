class Solution {
public:
    // using dijikstra algo
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map < int, vector<pair<int, int>>> adj;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, 2 * wt}); // bcs of switch cndn
        }
        vector<int> ans(n, INT_MAX);
        ans[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (node == n - 1) {
                return ans[n - 1];
            }
            for (auto& it : adj[node]) {
                int adjNode = it.first;
                int dist = it.second;
                if (dis + dist < ans[adjNode]) {
                    ans[adjNode] = dis + dist;
                    pq.push({dis + dist, adjNode});
                }
            }
        }
        return -1;
    }
};