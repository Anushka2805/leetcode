class Solution {
public:
    int count = 0;
    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& vis) {
        vis[node] = true;
        for (auto [u, dir] : adj[node]) {
            if (!vis[u]) {
                if (dir == 1) {
                    count++;
                }
                dfs(u, adj, vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        vector<bool> vis(n, 0);
        for (auto& it : connections) {
            adj[it[0]].push_back({it[1], 1});
            adj[it[1]].push_back({it[0], 0});
        }
        dfs(0, adj, vis);
        return count;
    }
};