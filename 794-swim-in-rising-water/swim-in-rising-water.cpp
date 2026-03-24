class Solution {
public:
    // using dijkstra algo
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        //time,(x,y)
        using syn = pair<int,pair<int,int>>;
        priority_queue <syn,vector<syn>,greater<syn>> pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0],{0,0}});
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        while(!pq.empty()){
            int wt = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if (wt > dist[x][y]) {
                continue;
            }
            for (int k = 0; k < 4; k++) {
                int i = x + dx[k];
                int j = y + dy[k];
                if (i >= 0 && i < n && j >= 0 && j < n) {
                    int newWt = max(wt, grid[i][j]);
                    if (dist[i][j] > newWt) {
                        dist[i][j] = newWt;
                        pq.push({newWt, {i, j}});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};