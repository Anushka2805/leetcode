class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector <pair<int, int>> adj[n];
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                int adjN = it.first;
                int edgeWt = it.second;
                if (dis + edgeWt < dist[adjN]) {
                    dist[adjN] = dis + edgeWt;
                    pq.push({dis + edgeWt, adjN});
                    ways[adjN] = ways[node];
                } else if (dis + edgeWt == dist[adjN]) {
                    ways[adjN] = (ways[adjN] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};