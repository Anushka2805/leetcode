class Solution {
public:
    // using kahns algo(topo sort + bfs)
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto& it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto& it : adj[i]) {
                indegree[it]++; // incoming edge towards i from it
            }
        }
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topoOrder;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            for (auto& it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if(topoOrder.size() != numCourses){
            return {};
        }
        return topoOrder;
    }
};