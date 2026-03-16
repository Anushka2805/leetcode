class Solution {
public:
    // 1 is land
    // 0 is water
    // using dfs
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || vis[i][j]) {
            return;
        }
        vis[i][j] = 1;
        dfs(grid, vis, i - 1, j);
        dfs(grid, vis, i + 1, j);
        dfs(grid, vis, i, j - 1);
        dfs(grid, vis, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(grid,vis,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};