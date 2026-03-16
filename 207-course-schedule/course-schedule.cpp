class Solution {
public:
//using topo sort / kahns algo bfs
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. making adj list
        vector<int> adj[numCourses];
        for(auto &it : prerequisites){
            // u -> v
            int u = it[0];   
            int v = it[1];
            adj[u].push_back(v);
        }
        //2. updating the indegree
        vector<int> indegree(numCourses,0);
        for(int i = 0;i<numCourses;i++){
            for(auto &it : adj[i]){
                indegree[it]++;
            }
        }
        //3. inserting elements with 0 indegree in q
        queue<int> q;
        for(int i = 0;i<indegree.size();i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        //4. till q is not empty we do bfs and push the order in this vector
        vector<int> topoOrder;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            for(auto &it : adj[node]){
                indegree[it]--; //that edge is removed so doing minus
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(topoOrder.size() == numCourses){
            return true;
        }
        return false;
    }
};