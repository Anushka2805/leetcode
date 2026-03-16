class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n); //reverse adj list
        vector<int> indegree(n, 0); //node's outgoing edges
        for (int i = 0; i < n; i++) {
            indegree[i] = graph[i].size();
            for (auto& it : graph[i]) {
                adj[it].push_back(i);
            }
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto& it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};